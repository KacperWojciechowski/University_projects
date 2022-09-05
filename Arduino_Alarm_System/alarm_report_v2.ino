#include <IRremote.h>
#include <LiquidCrystal.h>

#define LCD_ON A5
#define LCD_EN 0
#define LCD_RS 1
#define LCD_D4 4
#define LCD_D5 7
#define LCD_D6 3
#define LCD_D7 2

#define DIODES_ARMED_INDICATOR_1 A1
#define DIODES_ALARM_INDICATOR_1 5
#define DIODES_ARMED_INDICATOR_2 A2
#define DIODES_ALARM_INDICATOR_2 6
#define DIODES_ARMED_INDICATOR_3 A3
#define DIODES_ALARM_INDICATOR_3 12

#define REMOTE_1            0xFD08F7
#define REMOTE_2            0xFD8877
#define REMOTE_3            0xFD48B7
#define REMOTE_4            0xFD28D7
#define REMOTE_5            0xFDA857
#define REMOTE_6            0xFD6897
#define REMOTE_7            0xFD18E7
#define REMOTE_8            0xFD9867
#define REMOTE_9            0xFD58A7
#define REMOTE_0            0xFD30CF
#define REMOTE_ST_REPT      0xFD708F
#define REMOTE_ENTER        0xFD50AF
#define REMOTE_ON_OFF       0xFD00FF
#define REMOTE_SENSOR_PIN   8
#define REMOTE_REPEAT       0xFFFFFFFF
#define REMOTE_RELEASE      0x0

#define NUMPAD_1 689
#define NUMPAD_2 718
#define NUMPAD_3 765
#define NUMPAD_4 697
#define NUMPAD_5 726
#define NUMPAD_6 771
#define NUMPAD_7 722
#define NUMPAD_8 746
#define NUMPAD_9 785
#define NUMPAD_0 757

#define NUMPAD_A 843
#define NUMPAD_B 847
#define NUMPAD_C 853
#define NUMPAD_D 857

#define NUMPAD_ASTERISK 734
#define NUMPAD_HASH     793

#define NUMPAD_PIN A4

#define PASS_LENGTH     4
#define MODULES_AMOUNT  3
#define PIEZO_PIN       A0
#define PASS_TIMEOUT    10

#define MODULE_1_SENSOR_PIN     9
#define MODULE_2_SENSOR_ECHO    10
#define MODULE_2_SENSOR_TRIGGER 13
#define MODULE_3_SENSOR_PIN     11

#define ENTER       'A'
#define TOGGLE_KEY  'B'
#define BACK        '*'

#define DETECT_STATUS_TIMED_OUT    0
#define DETECT_STATUS_STRIKE       1
#define DETECT_STATUS_SILENCED     2
#define DETECT_STATUS_PROCESSING   3

#define STATE_DISARMED  0
#define STATE_ARMED     1
#define STATE_TRIGGERED 2
#define STATE_STRIKE_1  3
#define STATE_STRIKE_2  4
#define STATE_ALARMED   5

#define SENSOR_PIR 0
#define SENSOR_US  1

struct Module {
    uint8_t id;
    uint8_t sensor_type;
    uint8_t sensor_trigger;
    uint8_t sensor_echo;
    uint8_t diode_alarm;
    uint8_t diode_armed;
    uint8_t status;
    uint8_t timer;
    uint32_t last_checked;
    const char* room_pass;
};

Module modules[] = {
    {1, SENSOR_PIR, 0, MODULE_1_SENSOR_PIN, DIODES_ALARM_INDICATOR_1,
    DIODES_ARMED_INDICATOR_1, STATE_DISARMED, 0, 0, module_1_pass},

    {2, SENSOR_US, MODULE_2_SENSOR_TRIGGER, MODULE_2_SENSOR_ECHO, DIODES_ALARM_INDICATOR_2,
    DIODES_ARMED_INDICATOR_2, STATE_DISARMED, 0, 0, module_2_pass},

    {3, SENSOR_PIR, 0, MODULE_3_SENSOR_PIN, DIODES_ALARM_INDICATOR_3,
    DIODES_ARMED_INDICATOR_3, STATE_DISARMED, 0, 0, module_3_pass}
};

LiquidCrystal  display(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);
IRrecv         remote(REMOTE_SENSOR_PIN);

decode_results signal;
char previous_read = '\0';

bool key_released = true;

const char system_pass[]     = "1234";
const char module_1_pass[]   = "2345";
const char module_2_pass[]   = "3456";
const char module_3_pass[]   = "4567";

char input[]             = "####";
uint8_t input_index      = 0;
bool trigger             = false;
bool is_on               = false;

uint8_t modules_armed     = 0;
uint8_t modules_triggered = 0;
uint8_t modules_alarmed   = 0;

void disable_trigger() {
    trigger = false;
    for(uint8_t i = 0; i < PASS_LENGTH; i++) {
        input[i] = '#';
    }
    input_index = 0;
}

void arm(Module& module) {
    disable_trigger();
    digitalWrite(module.diode_armed, HIGH);
    module.status = STATE_ARMED;
    modules_armed++;
}

void arm_all(Module& module) {
    if(module.id == MODULES_AMOUNT) {
        disable_trigger();
    }
    digitalWrite(module.diode_armed, HIGH);
    module.status = STATE_ARMED;
    modules_armed++;
}

void disarm(Module& module) {
    disable_trigger();
    digitalWrite(module.diode_armed, LOW);
    module.status = STATE_DISARMED;
    modules_armed--;
}

void disarm_all(Module& module) {
    if(module.id == MODULES_AMOUNT) {
        disable_trigger();
    }
    digitalWrite(module.diode_armed, LOW);
    module.status = STATE_DISARMED;
    modules_armed--;
}

void disarm_detection(Module& module) {
    digitalWrite(module.diode_armed, LOW);
    digitalWrite(module.diode_alarm, LOW);
    module.status = STATE_DISARMED;
    modules_armed--;
    modules_triggered--;
}

void set_alarm(Module& module) {
    module.status = STATE_ALARMED;
    digitalWrite(module.diode_alarm, HIGH);
    digitalWrite(PIEZO_PIN, HIGH);
    modules_triggered--;
    modules_alarmed++;
}

void silence_alarm(Module& module) {
    module.status = STATE_DISARMED;
    digitalWrite(module.diode_alarm, LOW);
    digitalWrite(module.diode_armed, LOW);
    digitalWrite(PIEZO_PIN, LOW);
    modules_armed--;
    modules_alarmed--;
}

void perform_strike(Module& module) {
    switch(module.status) {
        case STATE_TRIGGERED:
            module.status = STATE_STRIKE_1;
            break;
        case STATE_STRIKE_1:
            module.status = STATE_STRIKE_2;
            break;
        case STATE_STRIKE_2:
            set_alarm(module);
            break;
    }
    disable_trigger();
}

void detect_procedure_init(Module& module) {
    module.status = STATE_TRIGGERED;
    module.timer = PASS_TIMEOUT;
    module.last_checked = millis();
    modules_triggered++;
}

uint8_t process_detection(Module& module) {
    uint8_t result;
    if(millis() - module.last_checked >= 1000) {
        module.timer--;
    }
    if(0 == module.timer) {
        result = DETECT_STATUS_TIMED_OUT;
    } else {
        if(trigger) {
            if(0 == strcmp(input, module.room_pass)) {
                result = DETECT_STATUS_SILENCED;
                disable_trigger();
            } else if(0 == strcmp(input, system_pass)) {
                result = DETECT_STATUS_SILENCED;
                if(modules_armed == 1) {
                    disable_trigger();
                }
            } else {
                result = DETECT_STATUS_STRIKE;
                disable_trigger();
            }
        } else {
            result = DETECT_STATUS_PROCESSING;
        }
    }
    return result;
}

bool detected(Module& module) {
    bool result = false;
    switch(module.sensor_type) {
        case SENSOR_PIR:
            result = digitalRead(module.sensor_echo);
            break;
        case SENSOR_US:
            digitalWrite(module.sensor_trigger, LOW);
            delayMicroseconds(2);
            digitalWrite(module.sensor_trigger, HIGH);
            delayMicroseconds(10);
            digitalWrite(module.sensor_trigger, LOW);
            if(pulseIn(module.sensor_echo, HIGH) / 29 < 330) {
                result = true;
            } else {
                result = false;
            }
            break;
    }
    return result;
}

void operate(Module& module) {
    uint8_t detection_status;

    switch(module.status) {
        case STATE_DISARMED:
            if((0 == modules_triggered && 0 == modules_alarmed) && trigger) {
                if(0 == strcmp(input, system_pass)) {
                    arm_all(module);
                } else if(0 == strcmp(input, module.room_pass)) {
                    arm(module);
                }
            }
            break;
        case STATE_ARMED:
            if(detected(module)) {
                detect_procedure_init(module);
            } else if((0 == modules_triggered && 0 == modules_alarmed) && trigger) {
                if(0 == strcmp(input, system_pass)) {
                    disarm_all(module);
                } else if (0 == strcmp(input, module.room_pass)) {
                    disarm(module);
                }
            }
            break;
        case STATE_TRIGGERED:
        case STATE_STRIKE_1:
        case STATE_STRIKE_2:
            do {
                detection_status = process_detection(module);
            } while(detection_status == DETECT_STATUS_PROCESSING);
            if(detection_status != DETECT_STATUS_SILENCED) {
                if(detection_status == DETECT_STATUS_TIMED_OUT) {
                    set_alarm(module);
                } else {
                    perform_strike(module);
                }
            } else {
                disarm_detection(module);
            }
            break;
        case STATE_ALARMED:
            do {
                module.timer = 2;
                detection_status = process_detection(module);
            } while(detection_status != DETECT_STATUS_SILENCED);
            silence_alarm(module);
            break;
    }
}

bool is_character(uint16_t& read, const uint16_t& character) {
    if(read >= character - 1 && read <= character + 1) {
        return true;
    }
}

char remote_read_input() {
    char result;
    if(remote.decode(&signal)) {
        if(signal.value == REMOTE_1) result = '1';
        else if(signal.value == REMOTE_2) result = '2';
        else if(signal.value == REMOTE_3) result = '3';
        else if(signal.value == REMOTE_4) result = '4';
        else if(signal.value == REMOTE_5) result = '5';
        else if(signal.value == REMOTE_6) result = '6';
        else if(signal.value == REMOTE_7) result = '7';
        else if(signal.value == REMOTE_8) result = '8';
        else if(signal.value == REMOTE_9) result = '9';
        else if(signal.value == REMOTE_0) result = '0';
        else if(signal.value == REMOTE_ENTER) result = 'A';
        else if(signal.value == REMOTE_ST_REPT) result = '*';
        else if(signal.value == REMOTE_ON_OFF) {
            previous_read = 'B';
            result = '\0';
        } else if(signal.value == REMOTE_REPEAT) {
            if(previous_read != '\0') {
                result = previous_read;
                previous_read = '\0';
            } else {
                result = '\0';
            }
        } else {
            result = '\0';
        }
        remote.resume();
    } else {
        result = '\0';
    }
    return result;
}

char numpad_read_input() {
    uint16_t key_value = analogRead(NUMPAD_PIN);
    char result;
    if(key_value != 1023 && key_released) {
        if(is_character(key_value, NUMPAD_1)) result = '1';
        else if(is_character(key_value, NUMPAD_2)) result = '2';
        else if(is_character(key_value, NUMPAD_3)) result = '3';
        else if(is_character(key_value, NUMPAD_4)) result = '4';
        else if(is_character(key_value, NUMPAD_5)) result = '5';
        else if(is_character(key_value, NUMPAD_6)) result = '6';
        else if(is_character(key_value, NUMPAD_7)) result = '7';
        else if(is_character(key_value, NUMPAD_8)) result = '8';
        else if(is_character(key_value, NUMPAD_9)) result = '9';
        else if(is_character(key_value, NUMPAD_0)) result = '0';
        else if(is_character(key_value, NUMPAD_A)) result = 'A';
        else if(is_character(key_value, NUMPAD_B)) result = 'B';
        else if(is_character(key_value, NUMPAD_C)) result = 'C';
        else if(is_character(key_value, NUMPAD_D)) result = 'D';
        else if(is_character(key_value, NUMPAD_ASTERISK)) result = '*';
        else if(is_character(key_value, NUMPAD_HASH)) result = '#';
        key_released = false;
  	} else if(key_value == 1023) {
        key_released = true;
        result = '\0';
    } else {
        result = '\0';
    }
    return result;
}

char read_input() {
    char character = numpad_read_input();
    if(character == '\0') {
        character = remote_read_input();
    }
    return character;
}

void toggle() {
    is_on = !is_on;
    if(is_on) {
        digitalWrite(LCD_ON, HIGH);
    } else {
        display.clear();
        digitalWrite(LCD_ON, LOW);
    }
}

bool is_ignored(char& char_input) {
    bool result;
    switch(char_input) {
        case 'C':
        case 'D':
        case '#': result = true;
            break;
        default : result = false;
            break;
    }
    return result;
}

void interpret_input() {
    char character = read_input();
    if(!is_ignored(character)) {
        switch(character) {
            case ENTER:
                if(is_on) {
                    trigger = true;
                }
                break;
            case TOGGLE_KEY:
                    toggle();
                break;
            case BACK:
                if(input_index > 0 && is_on) {
                        input_index--;
                }
                break;
            default:
                if(input_index < PASS_LENGTH && is_on) {
                    input[input_index] = character;
                }
                break;
        }
    }
}

void display_status() {
    display.clear();
    if(0 != modules_alarmed) {
        display.write("System Alarmed");
        display.setCursor(0, 1);
        display.write("Pass:");
        for(uint8_t i = 0; i < input_index; i++) {
            display.write('*');
        }
    } else if(0 != modules_triggered) {
        display.write("Detected");
        display.setCursor(0, 1);
        display.write("Pass:");
        for(uint8_t i = 0; i < input_index; i++) {
            display.write('*');
        }
    } else if(0 != modules_armed) {
        display.write("System armed");
    } else if(true == is_on) {
        display.write("System unarmed");
    }
    delay(10);
}

void setup() {
    display.begin(16,2);
    remote.enableIRIn();
}

void loop() {
    display_status();
    interpret_input();
    for(uint8_t i = 0; i < MODULES_AMOUNT; i++) {
        operate(modules[i]);
    }
}