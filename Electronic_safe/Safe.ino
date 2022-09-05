// include the library code:
#include <LiquidCrystal.h>
#include <IRremote.h>
#include <Servo.h>

#define REMOTE_1 0xFD08F7
#define REMOTE_2 0xFD8877
#define REMOTE_3 0xFD48B7
#define REMOTE_4 0xFD28D7
#define REMOTE_5 0xFDA857
#define REMOTE_6 0xFD6897
#define REMOTE_7 0xFD18E7
#define REMOTE_8 0xFD9867
#define REMOTE_9 0xFD58A7
#define REMOTE_0 0xFD30CF
#define REMOTE_BACK 0xFD708F
#define REMOTE_OPEN 0xFD50AF
#define REMOTE_LOCK 0xFD10EF
#define REMOTE_PROGRAM 0xFD40BF
#define REMOTE_TOGGLE 0xFD00FF
#define REMOTE_REPEAT 0xFFFFFFFF
#define REMOTE_RELEASE 0x0

enum pin {
    rs = 1,
    en = 0,
    d4 = 4,
    d5 = 7,
    d6 = 3,
    d7 = 2,
    ir_in = 8,
    lcd_on = A5
};

enum diode {
 	Strike_1 = A0,
  	Strike_2 = A1,
  	Strike_3 = A2,
  	Lock_open = A3,
  	Program = 12
};

enum key : char {
    k_open = 'A',
    k_program = 'B',
    k_lock = 'C',
    k_back = '*',
    k_toggle = 'T'
};

enum button : uint16_t {
    _1 = 689,
    _2 = 718,
    _3 = 765,
    _4 = 697,
    _5 = 726,
    _6 = 771,
    _7 = 722,
    _8 = 746,
    _9 = 785,
    _0 = 757,
    _A = 843,
    _B = 847,
    _C = 853,
    _D = 857,
    _asterisk = 734,
    _hash = 793
};

enum lock_pins {
    pin_1 = 11,
    pin_2 = 10,
    pin_3 = 9,
    pin_4 = 6,
    latch = 5
};

struct user {
    char name[16];
    char password[5];
};

LiquidCrystal lcd(pin::rs, pin::en, pin::d4, pin::d5, pin::d6, pin::d7);
IRrecv remote(pin::ir_in);

const uint8_t users_ammount = 2;
user users[] = {
    {"Kacper", "1234"},
    {"Bartek", "4321"}
};

decode_results signal;
char remote_previous_key = '\0';
char pass[5];
uint8_t pass_index = 0;
uint8_t curr_strike = 0;
uint8_t active_user;
bool is_on;
bool opened = false;
bool key_released = true;
Servo lock_pin_1;
Servo lock_pin_2;
Servo lock_pin_3;
Servo lock_pin_4;
Servo lock_latch;


void setup() {
    is_on = true;
    pass[4] = '\0';
    lcd.begin(16, 2);
    remote.enableIRIn();
  	pinMode(diode::Strike_1, OUTPUT);
  	pinMode(diode::Strike_2, OUTPUT);
  	pinMode(diode::Strike_3, OUTPUT);
  	pinMode(diode::Lock_open, OUTPUT);
  	pinMode(diode::Program, OUTPUT);
    pinMode(pin::lcd_on, OUTPUT);
    digitalWrite(pin::lcd_on, HIGH);
    lock_pin_1.attach(lock_pins::pin_1);
    lock_pin_1.write(0);
    lock_pin_2.attach(lock_pins::pin_2);
    lock_pin_2.write(0);
    lock_pin_3.attach(lock_pins::pin_3);
    lock_pin_3.write(0);
    lock_pin_4.attach(lock_pins::pin_4);
    lock_pin_4.write(0);
    lock_latch.attach(lock_pins::latch);
    lock_latch.write(0);
}

bool correct_password() {
    for(uint8_t i = 0; i < users_ammount; i++) {
        if(0 == strcmp(pass, users[i].password)) {
            active_user = i;
            return true;
        }
    }
    return false;
}

void display_status() {
    lcd.clear();
    if(is_on) {
        if(!opened) {
            digitalWrite(diode::Lock_open, LOW);
            lcd.print("Lock secured");
            lcd.setCursor(0, 1);
            if(curr_strike != 3) {
                for(uint8_t i = 0; i < pass_index; i++) {
                    lcd.print('*');
                }
            }
            if(curr_strike == 0) {
                digitalWrite(diode::Strike_1, LOW);
                digitalWrite(diode::Strike_2, LOW);
                digitalWrite(diode::Strike_3, LOW);
            } else if(curr_strike == 1) {
                digitalWrite(diode::Strike_1, HIGH);
            } else if(curr_strike == 2) {
                digitalWrite(diode::Strike_2, HIGH);
            } else if(curr_strike == 3) {
                digitalWrite(diode::Strike_3, HIGH);
                lcd.setCursor(0, 1);
                lcd.print("Permanently");
                while(true);
            }
        } else {
            lcd.print("Lock opened");
            lcd.setCursor(0, 1);
            lcd.print(users[active_user].name);
            digitalWrite(diode::Lock_open, HIGH);
        }
    }
}

void read_pass(char& input) {
    if(input == key::k_back) {
        if(pass_index > 0) {
            pass_index--;
        }
    } else if(input == 'D') {
        // ignore input
    } else if(pass_index < 4) {
        pass[pass_index] = input;
        pass_index++;
    }
}

void open() {
    if(correct_password) {
        opened = true;
        digitalWrite(diode::Strike_1, LOW);
        digitalWrite(diode::Strike_2, LOW);
        digitalWrite(diode::Strike_3, LOW);
        curr_strike = 0;
        lock_pin_1.write(20 * (pass[0] - '0'));
        delay(200);
        lock_pin_2.write(20 * (pass[1] - '0'));
        delay(200);
        lock_pin_3.write(20 * (pass[2] - '0'));
        delay(200);
        lock_pin_4.write(20 * (pass[3] - '0'));
        delay(200);
        lock_latch.write(180);
    } else {
        lcd.clear();
        lcd.print("Wrong password");
        pass_index = 0;
        curr_strike++;
    }
}

void lock() {
    digitalWrite(diode::Lock_open, LOW);
    opened = false;
    pass_index = 0;
    curr_strike = 0;
    lock_pin_1.write(0);
    lock_pin_2.write(0);
    lock_pin_3.write(0);
    lock_pin_4.write(0);
    lock_latch.write(0);
    for(uint8_t i = 0; i < 4; i++) {
        pass[i] = '#';
    }
}

void program() {
    digitalWrite(diode::Program, HIGH);
    pass_index = 0;
    char input;
    while(pass_index != 4) {
        lcd.clear();
        lcd.print("Insert new pass:");
        lcd.setCursor(0, 1);
        for(uint8_t i = 0; i < pass_index; i++) {
            lcd.print('*');
        }
        do {
            input = get_input();
        } while(input == '\0');

        if(input == key::k_back) {
            if(pass_index > 0) {
                pass_index--;
            }
        } else if(!is_excluded(input)) {
            pass[pass_index++] = input;
        } else {
            lcd.clear();
            lcd.print("Wrong character");
            lcd.setCursor(0, 1);
            lcd.print("Select 0 - 9");
            delay(1000);
        }
    }
    strcpy(users[active_user].password, pass);
    lcd.clear();
    lcd.print("New password set");
    digitalWrite(diode::Program, LOW);
    delay(1000);
}

bool is_excluded(char& input) {
    if((input >= 'A' && input <= 'D') || input == '#') {
        return true;
    } else {
        return false;
    }
}

char get_input() {
	uint16_t value_keypad = analogRead(A4);
    char result;
  	if(value_keypad != 1023 && key_released) {
        if(value_keypad >= (button::_1 - 1) && value_keypad <= (button::_1 + 1)) result = '1';
        else if(value_keypad >= (button::_2 - 1) && value_keypad <= (button::_2 + 1)) result = '2';
        else if(value_keypad >= (button::_3 - 1) && value_keypad <= (button::_3 + 1)) result = '3';
        else if(value_keypad >= (button::_A - 1) && value_keypad <= (button::_A + 1)) result = 'A';
        else if(value_keypad >= (button::_4 - 1) && value_keypad <= (button::_4 + 1)) result = '4';
        else if(value_keypad >= (button::_5 - 1) && value_keypad <= (button::_5 + 1)) result = '5';
        else if(value_keypad >= (button::_6 - 1) && value_keypad <= (button::_6 + 1)) result = '6';
        else if(value_keypad >= (button::_B - 1) && value_keypad <= (button::_B + 1)) result = 'B';
        else if(value_keypad >= (button::_7 - 1) && value_keypad <= (button::_7 + 1)) result = '7';
        else if(value_keypad >= (button::_8 - 1) && value_keypad <= (button::_8 + 1)) result = '8';
        else if(value_keypad >= (button::_9 - 1) && value_keypad <= (button::_9 + 1)) result = '9';
        else if(value_keypad >= (button::_C - 1) && value_keypad <= (button::_C + 1)) result = 'C';
        else if(value_keypad >= (button::_asterisk - 1) && value_keypad <= (button::_asterisk + 1)) result = '*';
        else if(value_keypad >= (button::_0 - 1) && value_keypad <= (button::_0 + 1)) result = '0';
        else if(value_keypad >= (button::_hash - 1) && value_keypad <= (button::_hash + 1)) result = '#';
        else if(value_keypad >= (button::_D - 1) && value_keypad <= (button::_D + 1)) result = 'D';
        key_released = false;
  	} else if (remote.decode(&signal)) {
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
        else if(signal.value == REMOTE_OPEN) result = 'A';
        else if(signal.value == REMOTE_LOCK) result = 'C';
        else if(signal.value == REMOTE_BACK) result = '*';
        else if(signal.value == REMOTE_PROGRAM) result = 'B';
        else if(signal.value == REMOTE_TOGGLE) {
            remote_previous_key = key::k_toggle;
            result = '\0';
        } else if(signal.value == REMOTE_REPEAT) {
            if(remote_previous_key == key::k_toggle) {
                result = remote_previous_key;
                remote_previous_key = '\0';
            } else {
                result = '\0';
            }
        } else result = '#';
        key_released = false;
        signal.value = REMOTE_RELEASE;
        remote.resume();
    } else if (1023 == value_keypad && signal.value == REMOTE_RELEASE) {
        result = '\0';
        key_released = true;
    } else {
        result = '\0';
    }
    delay(2);
    return result;
}

void operate() {
    char input;
    do {
        input = get_input();
    } while(input == '\0');

    if(key::k_toggle == input) {
        is_on = !is_on;
        if(is_on) digitalWrite(pin::lcd_on, HIGH);
        else digitalWrite(pin::lcd_on, LOW);
        if(opened) {
            lock();
        }
    } else if(is_on) {
        if(key::k_open == input) {
            if(!opened) {
                open();
            }
        } else if(key::k_program == input) {
            if(opened) {
                program();
            }
        } else if(key::k_lock == input) {
            if(opened) {
                lock();
            }
        } else {
            read_pass(input);
        }
    }
}

void loop() {
    display_status();
    operate();
}