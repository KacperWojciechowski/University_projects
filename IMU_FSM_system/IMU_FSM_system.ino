#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>
 
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

#define FONT_HEIGHT 10
#define FONT_SPACING 3

#define LINE_OFFSET (FONT_HEIGHT + FONT_SPACING)
#define LINE_1 FONT_HEIGHT
#define LINE_2 LINE_OFFSET + LINE_1
#define LINE_3 2 * LINE_OFFSET + LINE_1
#define LINE_4 3 * LINE_OFFSET + LINE_1
#define LINE_5 4 * LINE_OFFSET + LINE_1

#define GRAVITY_CONST 8

#define LED_BASE_ADDR A0
#define ACCEL_LED_BLUE A0
#define GYRO_LED_GREEN A1
#define TEMP_LED_RED A2

#define MODE_BUTTON 52

#define ACCELEROMETER 0
#define GYROSCOPE 1
#define THERMOMETER 2

Adafruit_MPU6050 mpu;
sensors_event_t a, g, temp;
U8G2_SH1106_128X64_NONAME_F_2ND_HW_I2C oled(U8G2_R0, U8X8_PIN_NONE);
char buffer[26];

uint8_t mode = 0;

uint8_t disp_freq = 500;
uint32_t disp_update = 0;


void sensorSetup() {
    Serial.println("Adafruit MPU6050 test!");
 
    // Try to initialize!
    if (!mpu.begin()) {
        Serial.println("Failed to find MPU6050 chip");
        while (1) {
            delay(10);
        }
    }
     Serial.println("MPU6050 Found!");
 
    mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
    Serial.print("Accelerometer range set to: ");
    switch (mpu.getAccelerometerRange()) {
    case MPU6050_RANGE_2_G:
        Serial.println("+-2G");
        break;
    case MPU6050_RANGE_4_G:
        Serial.println("+-4G");
        break;
    case MPU6050_RANGE_8_G:
        Serial.println("+-8G");
        break;
    case MPU6050_RANGE_16_G:
        Serial.println("+-16G");
        break;
    }
    mpu.setGyroRange(MPU6050_RANGE_500_DEG);
    Serial.print("Gyro range set to: ");
    switch (mpu.getGyroRange()) {
    case MPU6050_RANGE_250_DEG:
        Serial.println("+- 250 deg/s");
        break;
    case MPU6050_RANGE_500_DEG:
        Serial.println("+- 500 deg/s");
        break;
    case MPU6050_RANGE_1000_DEG:
        Serial.println("+- 1000 deg/s");
        break;
    case MPU6050_RANGE_2000_DEG:
        Serial.println("+- 2000 deg/s");
        break;
    }
 
    mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
    Serial.print("Filter bandwidth set to: ");
    switch (mpu.getFilterBandwidth()) {
    case MPU6050_BAND_260_HZ:
        Serial.println("260 Hz");
        break;
    case MPU6050_BAND_184_HZ:
        Serial.println("184 Hz");
        break;
    case MPU6050_BAND_94_HZ:
        Serial.println("94 Hz");
        break;
    case MPU6050_BAND_44_HZ:
        Serial.println("44 Hz");
        break;
    case MPU6050_BAND_21_HZ:
        Serial.println("21 Hz");
        break;
    case MPU6050_BAND_10_HZ:
        Serial.println("10 Hz");
        break;
    case MPU6050_BAND_5_HZ:
        Serial.println("5 Hz");
        break;
    }
}

void parseFloatToString(char buff[], float value) {
    bool sign = value < 0;
    value = abs(value);
    int temp = (int)(value * 100);
    sprintf(buff, "%c%3d.%s%d", sign ? '-' : ' ', temp/100, 
        temp % 100 < 10 ? "0" : "", temp % 100); 
}

void showAccelRead() {
    if(millis() - disp_update >= disp_freq) {
        oled.clearBuffer();
        oled.setFont(u8g2_font_ncenB08_tr);
        oled.drawStr(0, LINE_1, "Accelerometre reading:");

        strcpy(buffer, "X = ");
        parseFloatToString(&buffer[strlen(buffer)], a.acceleration.x);
        strcat(buffer, " m/s^2");
        oled.drawStr(0, LINE_3, buffer);

        strcpy(buffer, "Y = ");
        parseFloatToString(&buffer[strlen(buffer)], a.acceleration.y);
        strcat(buffer, " m/s^2");
        oled.drawStr(0, LINE_4, buffer);

        strcpy(buffer, "Z = ");
        parseFloatToString(&buffer[strlen(buffer)], a.acceleration.z - GRAVITY_CONST);
        strcat(buffer, " m/s^2");
        oled.drawStr(0, LINE_5, buffer);

        oled.sendBuffer();
    }
}

void showGyroRead() {
    if(millis() - disp_update >= disp_freq) {
        oled.clearBuffer();
        oled.setFont(u8g2_font_ncenB08_tr);
        oled.drawStr(0, LINE_1, "Gyroscope reading:");

        strcpy(buffer, "Roll = ");
        parseFloatToString(&buffer[strlen(buffer)], g.gyro.x);
        strcat(buffer, " rad");
        oled.drawStr(0, LINE_3, buffer);
        
        strcpy(buffer, "Pitch = ");
        parseFloatToString(&buffer[strlen(buffer)], g.gyro.y);
        strcat(buffer, " rad");
        oled.drawStr(0, LINE_4, buffer);

        strcpy(buffer, "Yaw = ");
        parseFloatToString(&buffer[strlen(buffer)], g.gyro.z);
        strcat(buffer, " rad");
        oled.drawStr(0, LINE_5, buffer);

        oled.sendBuffer();
    }
    
}

void showTempRead() {
    if(millis() - disp_update >= disp_freq) {
        oled.clearBuffer();
        oled.setFont(u8g2_font_ncenB08_tr);
        oled.drawStr(0, LINE_1, "Temperature reading:");

        strcpy(buffer, "Temp = ");
        parseFloatToString(&buffer[strlen(buffer)], temp.temperature);
        strcat(buffer, " degC");
        oled.drawStr(0, LINE_3, buffer);

        oled.sendBuffer();
    }
}

void modeSwitchIH() {
    if(mode < 2) {
        mode++;
    } else {
        mode = 0;
    }
    switch(mode + LED_BASE_ADDR) {
        case ACCEL_LED_BLUE:
            digitalWrite(ACCEL_LED_BLUE, HIGH);
            digitalWrite(GYRO_LED_GREEN, LOW);
            digitalWrite(TEMP_LED_RED, LOW);
            break;
        case GYRO_LED_GREEN:
            digitalWrite(ACCEL_LED_BLUE, LOW);
            digitalWrite(GYRO_LED_GREEN, HIGH);
            digitalWrite(TEMP_LED_RED, LOW);
            break;
        case TEMP_LED_RED:
            digitalWrite(ACCEL_LED_BLUE, LOW);
            digitalWrite(GYRO_LED_GREEN, LOW);
            digitalWrite(TEMP_LED_RED, HIGH);
            break;
    }
}

void setup(void) {
    Serial.begin(115200);
    while (!Serial)
        delay(10); // will pause Zero, Leonardo, etc until serial console opens
    sensorSetup();
    oled.begin();
    pinMode(MODE_BUTTON, INPUT);
    attachInterrupt(digitalPinToInterrupt(52), modeSwitchIH, FALLING);
    Serial.println("");
    pinMode(ACCEL_LED_BLUE, OUTPUT);
    pinMode(GYRO_LED_GREEN, OUTPUT);
    pinMode(TEMP_LED_RED, OUTPUT);
    switch(mode + LED_BASE_ADDR) {
        case ACCEL_LED_BLUE:
            digitalWrite(ACCEL_LED_BLUE, HIGH);
            break;
        case GYRO_LED_GREEN:
            digitalWrite(GYRO_LED_GREEN, HIGH);
            break;
        case TEMP_LED_RED:
            digitalWrite(TEMP_LED_RED, HIGH);
            break;
    }
    delay(100);
}

void loop() {
    mpu.getEvent(&a, &g, &temp);
    switch(mode) {
        case ACCELEROMETER:
            showAccelRead();
            break;
        case GYROSCOPE:
            showGyroRead();
            break;
        case THERMOMETER:
            showTempRead();
            break;
    }
    delay(100);
}