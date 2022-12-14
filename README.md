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

----------------------------------------------------------------------------

### Smart Pot

##### General idea

A smart pot IoT solution consisting of two microcontrollers communicating via UART, monitoring a plant environment. The data provided by the system can be accessed and processed by the Thingsboard platform.

##### Operation mode

The system is modular, designed for Arduino Nano Every as a measuring module, and Huzzah ESP8266 as an Internet communication module. The Nano Every module reads the measurements from analog soil humidity sensor and insolation sensor, maps it to a percentage range from 0 to 100%, outputs the processed data via serial port to a computer and passes the data via another serial port to the communication module. The ESP8266 module connects to the Thingsboard platform via WiFi network of given SSID and password (embedded in the code), awaits data from the measuring module, and passes the data to the Thingsboard cloud platform. Communication module outputs diagnostic information on the common serial port (used both by the computer and measuring module) however the measuring module ignores any information it receives from the communication module.

Tested with demo.thingsboard.io.

----------------------------------------------------------------------------

### Car system

##### General idea

A circuit symulating the work of onboard car system, with functionalities such as engine acceleration, drive/reverse gear shifting, door open sensors, windows control, air quality sensor, engine temperature sensor, daylight sensor and headlights control and LCD status display. 

##### Operation mode

The system is build based on Arduino Uno Rev III. It consists of various sensors simulating a system that might be found in a car. To simulate engine, a DC motor was used, with several speed levels available, based on a flex sensor position (simulating a gas pedal). The controller monitors all the sensors displaying relevant information on an LCD display board, such as temperature info, door open info, air quality info. 

----------------------------------------------------------------------------

### Morse code station

##### General idea

A station allowing translation to and from morse code, displaying the message on LCD screen and sending it via serial port to an overseeing computer.

##### Operation mode

The control panel offers user several buttons. First two buttons select a letter from an english alphabet, third button accepts the letter and fourth button deletes previously accepted letter. By using them, the user can create a message to be translated to morse code. Message is translated after pressing the send button, which is 5th in order. The 6th button is a morse code switch, allowing user to input letters in a morse code signal. This signal is automatically translated after each letter input (the acceptance of the letter is signified by a longer pause from pressing the morse button). 
