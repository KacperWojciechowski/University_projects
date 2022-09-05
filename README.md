# Overview

This repository contains a collection of university projects in C/C++ language.
Each of the projects is within its respective folder, and is described by this readme below.

# Projects

### Arduino Alarm System

##### General idea

A relatively portable alarm system equipped with 2 PIR sensors and 1 ultrasonic distance sensor, allowing user to monitor 3 different localizations such as rooms in an office. When an alarm is triggered, a Piezo is powered on, producing a sound. User controls the behavior of the system via a numpad or an IR remote.

##### Operation mode

The system is designed to be constructed with Arduino Uno Rev III. It operates on an idea of finite state machine, allowing user to controll all modules at once or each module separately. Additionally, the system contains an LCD display and a panel of different colour LED diodes signalizing the state of each module within the system. The armed / disarmed LED signals are connected together via a logic inverter, saving on control pins in microcontroller. Numpad is operated as a resistance keyboard using an analog input of the used microcontroller.

----------------------------------------------------------------------------

### IMU FSM System

##### General idea

A simple system allowing user to monitor data read from an MCU6050 IMU via an OLED display. 


##### Operation mode

The program is designed to work with Arduino Due. It is constructed as a final state machine, allowing user to switch between modes by pressing a button. Each mode displays data from different MCU6050 sensor (accelerometer, gyroscope, termometer). Current mode is signalized via a different color LED diode. The data is displayed in following units respectively: m/s^2, radians, Celsius.

----------------------------------------------------------------------------

### MCS51 Temperature monitor

##### General idea

A simple temperature monitor based on a laboratory board equiped with 8-bit ADC, potentiometer array of LEDs, LDC display and a temperature sensor.

##### Operation mode

The program monitors the temperature and potentiometer reads, displaying them on LCD and LEDs respectively. It utilizes ADC interrupt to read the result of a conversion, yet due to lack of semaphores on this platform, the main function polls on a flag while waiting for the interrupt to occur. The ADC read of the temperature is then manually converted into string (due to malfunctioning of the sprintf function on this platform) and displayed on an LCD. 
