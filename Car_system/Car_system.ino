#include <Servo.h>
#include <LiquidCrystal.h>

/* if air signal reads 4 or over, close the vents */
#define VENTS_SIGNAL 3

/* if temp sensor reads 80 or over, sound the alarm */
#define TEMP_ALARM_DIODE 2

/* if high, headlights are on, else daylights are on */
/* if sun exposure is 30 or lower, turn on headlights*/
#define HEADLIGHTS 4

#define LCD_RS 5
#define LCD_ENABLE 6
#define LCD_DB4 7
#define LCD_DB5 8
#define LCD_DB6 9
#define LCD_DB7 10

/* if doors read 1, they are closed, else they are opened */
#define DRIVER_DOORS 11
#define PASSENGER_DOORS 12
#define TRUNK_DOORS 13

/* reads range from 0 to 371 */
#define AIR_SIGNAL A0

/* reads range from 6 to 679 */
#define SUN_EXPOSURE A1

/* reads in range from 20 to 358 */
#define TEMP_SENSOR A2

/* reads in range from 6 to 33 */
#define GAS_PEDAL A3

#define SELECT_LOAD_1 A4
#define SELECT_LOAD_2 A5

LiquidCrystal lcd(LCD_RS, LCD_ENABLE, LCD_DB4, LCD_DB5, LCD_DB6, LCD_DB7);
Servo vent;
long int lights_update;
long int lcd_update;

void setup() {
    pinMode(TEMP_ALARM_DIODE, OUTPUT);
    pinMode(HEADLIGHTS, OUTPUT);
    pinMode(SELECT_LOAD_1, OUTPUT);
    pinMode(SELECT_LOAD_2, OUTPUT);

    pinMode(DRIVER_DOORS, INPUT);
    pinMode(PASSENGER_DOORS, INPUT);
    pinMode(TRUNK_DOORS, INPUT);
    pinMode(AIR_SIGNAL, INPUT);
    pinMode(SUN_EXPOSURE, INPUT);
    pinMode(TEMP_SENSOR, INPUT);
    pinMode(GAS_PEDAL, INPUT);

    digitalWrite(TEMP_ALARM_DIODE, LOW);

    lcd.begin(16, 2);
    vent.attach(VENTS_SIGNAL);
    vent.write(180);
    lcd.clear();
    lcd.print("Engine started");

    lights_update = 0;
    lcd_update = 0;
    delay(100);
}

/* returns engine rpm mode 1 to 4 */
int readGas() {
    int value = map(analogRead(GAS_PEDAL), 6, 33, 1, 4);
    return value;
}

/* returns the percentage of sun exposure */
int readSunExposure() {
    int value = map(analogRead(SUN_EXPOSURE), 6, 679, 0, 100);
    return value;
}

/* returns the engine temperature */
int readEngineTemp() {
    int value = map(analogRead(TEMP_SENSOR), 20, 358, -40, 125);
    return value;
}

/* returns the rating of air quality */
/* the smaller value, the better quality */
int readAirPolution() {
    int value = map(analogRead(AIR_SIGNAL), 0, 371, 0, 10);
}

/* control the rpm of engine */
void controlEngine() {
    switch(readGas()) {
        case 1:
            digitalWrite(SELECT_LOAD_1, HIGH);
            digitalWrite(SELECT_LOAD_2, HIGH);
            break;
        case 2:
            digitalWrite(SELECT_LOAD_1, LOW);
            digitalWrite(SELECT_LOAD_2, HIGH);
            break;
        case 3:
            digitalWrite(SELECT_LOAD_1, HIGH);
            digitalWrite(SELECT_LOAD_2, LOW);
            break;
        case 4:
            digitalWrite(SELECT_LOAD_1, LOW);
            digitalWrite(SELECT_LOAD_2, LOW);
            break;
    }
}

/* control vents based on air quality */
void controlVents() {
    if(readAirPolution() >= 4) {
        vent.write(0);
        if(millis() - lcd_update >= 1000) {
            lcd.setCursor(0, 1);
            lcd.write("Vents closed    ");
            lcd_update = millis();
        }
    } else {
        vent.write(180);
        if(millis() - lcd_update >= 1000) {
            lcd.setCursor(0, 1);
            lcd.write("Vents opened    ");
            lcd_update = millis();
        }
    }
}

/* control headlights based on sun exposure */
/* turn on headlights if sun exposure is low */
/* else turn on daylights */
void controlHeadlights() {
    if(readSunExposure() <= 30) {
        if(millis() - lights_update >= 1000) {
            digitalWrite(HEADLIGHTS, HIGH);
            lights_update = millis();
        }
    } else {
        if(millis() - lights_update >= 1000) {
            digitalWrite(HEADLIGHTS, LOW);
            lights_update = millis();
        }
    }
}

/* control if engine temperature is in safe range */
void controlEngineTemp() {
    if(readEngineTemp() >= 80) {
        digitalWrite(TEMP_ALARM_DIODE, HIGH);
        if(millis() - lcd_update >= 1000) {
            lcd.setCursor(0, 1);
            lcd.write("Engine overheat!");
            lcd_update = millis();
        }
    } else {
        digitalWrite(TEMP_ALARM_DIODE, LOW);
    }
}

/* check if any doors are opened */
void checkDoors() {
    if(!digitalRead(DRIVER_DOORS) && millis() - lcd_update >= 1000) {
        lcd.setCursor(0, 1);
        lcd.write("Driver opened");
        lcd_update = millis();
    } else if(!digitalRead(PASSENGER_DOORS) && millis() - lcd_update >= 1000) {
        lcd.setCursor(0, 1);
        lcd.write("Passen. opened");
        lcd_update = millis();
    } else if(!digitalRead(TRUNK_DOORS) && millis() - lcd_update >= 1000) {
        lcd.setCursor(0, 1);
        lcd.write("Trunk opened    ");
        lcd_update = millis();
    }
}

void loop() {
    controlEngine();
    controlHeadlights();
    checkDoors();
    controlEngineTemp();
    controlVents();
    delay(10);
}