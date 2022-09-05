#include <LiquidCrystal.h>

const int source_default = 0;
const int source_keyboard = 1;
const int source_morse = 2;

const int dot_led = 13;
const int dash_led = 12;
const int buzzer = 8;
const int keyboard = A2;

const int next_char = 743;
const int prev_char = 630;
const int ok = 547;

const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 10, d7 = 9;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

String morse[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", 
                    "--.", "....", "..", ".---", "-.-", ".-..", 
                    "--", "-.", "---", ".--.", "--.-", ".-.", 
					"...", "-", "..-", "...-", ".--", "-..-", 
                    "-.--", "--.."};

char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 
                     'I', 'J', 'K', 'L', 'M', 'N', 'O', 'Q', 
                     'P', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 
                     'Y', 'Z'};

uint8_t sig_source;

int lcd_cursor_pos = 0;

char morse_buffer[16][4];
int morse_buffer_index = 0;

char lcd_buffer[16] = {};
int lcd_buffer_index = 0;

char character;

uint8_t alph_index = 0;

uint32_t start_time = 0;
uint32_t end_time = 0;
uint8_t char_index = 0;
bool morse_char_loaded = false;
bool pressed = false;
uint16_t button;

uint8_t index;

uint8_t serial_char_buffer;
uint8_t serial_count;

uint8_t get_alphabet_index()
{
  	static char buff[5];
	static uint8_t i;
  	for(i = 0; i < 4; i++)
    {
      	if(morse_buffer[morse_buffer_index][i] != ' ')
        {
         	buff[i] = morse_buffer[morse_buffer_index][i]; 
    	}
    }
  	buff[i] = '\0';
  	for(i = 0; i < 26; i++)
    {
     	if(0 == strcmp(buff, morse[i].c_str()))
        {
         	break; 
        }
    }	
  	return i;
}

void monitor_morse()
{
 	if(millis() - end_time >= 2000 && morse_char_loaded)
    {
      	index = get_alphabet_index();
      	morse_buffer_index++;
      	char_index = 0;
      	if(index < 26)
        {
      		lcd.setCursor(lcd_cursor_pos, 1);
      		lcd.print(alphabet[index]);
            if(lcd_cursor_pos < 16)
          	{    
                lcd_buffer[lcd_cursor_pos] = alphabet[index];
                lcd_cursor_pos++;
            }
        }
        
      	morse_char_loaded = false;
    }
}

void monitor_serial()
{
  	
 	if(serial_count = Serial.available())
    {
      	noInterrupts();
    	for(int i = 0; i < serial_count; i++)
        {
       		serial_char_buffer = Serial.read();
          	index = serial_char_buffer - 'A';
          	for(uint8_t j = 0; j < morse[index].length(); j++)
          	{
            	if(morse[index][j] == '.')
            	{
              		digitalWrite(buzzer, HIGH);
                    digitalWrite(dot_led, HIGH);
                    for(uint8_t i = 0; i < 20; i++)
                      	delayMicroseconds(10000);
                    digitalWrite(dot_led, LOW);
                    digitalWrite(buzzer, LOW);
                    for(uint8_t i = 0; i < 30; i++)
                    	delayMicroseconds(10000);
                }
                else if (morse[index][j] == '-')
                {
                    digitalWrite(buzzer, HIGH);
                    digitalWrite(dash_led, HIGH);
                    for(uint8_t i = 0; i < 40; i++)
                     	delayMicroseconds(10000);
                  	digitalWrite(dash_led, LOW);
                  	digitalWrite(buzzer, LOW);
                  	for(uint8_t i = 0; i < 30; i++)
                   		delayMicroseconds(10000);
                }
          	}
        }
      	interrupts();
    }
}

void reset()
{
    morse_buffer_index = 0;
    for(uint8_t i = 0; i < 16; i++)
	    for(uint8_t j = 0; j < 4; j++)
    		morse_buffer[i][j] = ' ';
    for(uint8_t i = 0; i < 16; i++)
        lcd_buffer[i] = ' ';
    lcd_cursor_pos = 0;
    morse_char_loaded = false;
  	lcd.clear();
    lcd.print("Wprowadz slowo");
}

void morse_button_interrupt()
{
  	if(sig_source != source_morse)
    {
    	sig_source = source_morse;
    }
    if(pressed)
    {
      	if(millis() - start_time >= 300)
        {
          	digitalWrite(dash_led, HIGH);
          	if(morse_buffer_index < 16 && char_index < 4)	
            {	
              	morse_buffer[morse_buffer_index][char_index] = '-';
          		Serial.print("-");
                char_index++;
                morse_char_loaded = true;
            }
            end_time = millis();	
          	for(uint8_t i = 0; i < 30; i++)
            	delayMicroseconds(10000);
          	digitalWrite(dash_led, LOW);
        }
      	else
        {
          	digitalWrite(dot_led, HIGH);
          	if(morse_buffer_index < 16 && char_index < 4)
            {	
             	morse_buffer[morse_buffer_index][char_index] = '.';
          		Serial.print(".");
                char_index++;
                morse_char_loaded = true;
            }
            end_time = millis();
          	for(uint8_t i = 0; i < 30; i++)
            	delayMicroseconds(10000);
          	digitalWrite(dot_led, LOW);
        }
      	digitalWrite(buzzer, LOW);
      	pressed = false;
    }
    else
    {
		start_time = millis();
      	digitalWrite(buzzer, HIGH);
      	pressed = true;
    }
}

void lcd_button_interrupt()
{
  	if(!morse_char_loaded)
    {
        button = analogRead(keyboard);
        if(button >= next_char - 40 && button <= next_char + 40)
        {
            if(sig_source != source_keyboard)
            {
                sig_source = source_keyboard;
                lcd.setCursor(lcd_cursor_pos, 1);
                lcd.print("A");
            }
            else if(alph_index < 25)
            {
                lcd.setCursor(lcd_cursor_pos, 1);
                lcd.print(alphabet[++alph_index]);
            }
        }
        else if(button >= prev_char - 40 && button <= prev_char + 40)
        {
            if(sig_source != source_keyboard)
            {
                sig_source = source_keyboard;
                lcd.setCursor(lcd_cursor_pos, 1);
                lcd.print("A");
            }
            else if (alph_index > 0)
            {
                lcd.setCursor(lcd_cursor_pos, 1);
                
                lcd.print(alphabet[--alph_index]);
            }
        }
        else if(button >= ok - 40 && button <= ok + 40)
        {
            if(sig_source != source_keyboard)
            {
                sig_source = source_keyboard;
                lcd.setCursor(lcd_cursor_pos, 1);
                lcd.print("A");
            }
            lcd_buffer[lcd_cursor_pos] = alphabet[alph_index];
            lcd_cursor_pos++;
            sig_source = source_default;
            alph_index = 0;
        }
        else
        {
            noInterrupts();
            uint8_t index;
            uint8_t i = 0;
          	
            while(i < 16 && lcd_buffer[i] != ' ')
            {
                index = lcd_buffer[i] - 'A';
                for(uint8_t j = 0; j < morse[index].length(); j++)
                {
                    if(morse[index][j] == '.')
                    {
                        digitalWrite(buzzer, HIGH);
                        digitalWrite(dot_led, HIGH);
                        for(uint8_t i = 0; i < 20; i++)
                            delayMicroseconds(10000);
                        digitalWrite(dot_led, LOW);
                        digitalWrite(buzzer, LOW);
                        for(uint8_t i = 0; i < 30; i++)
                            delayMicroseconds(10000);
                    }
                    else if (morse[index][j] == '-')
                    {
                        digitalWrite(buzzer, HIGH);
                        digitalWrite(dash_led, HIGH);
                        for(uint8_t i = 0; i < 40; i++)
                            delayMicroseconds(10000);
                        digitalWrite(dash_led, LOW);
                        digitalWrite(buzzer, LOW);
                        for(uint8_t i = 0; i < 30; i++)
                            delayMicroseconds(10000);
                    }
                }
                i++;
            }
            
            interrupts();
        }
    }
}

void setup()
{
  	Serial.begin(9600);
 	pinMode(dot_led, OUTPUT);
  	pinMode(dash_led, OUTPUT);
  	pinMode(buzzer, OUTPUT);
  	digitalWrite(dot_led, LOW);
  	digitalWrite(dash_led, LOW);
  	digitalWrite(buzzer, LOW);
	
  	pinMode(keyboard, INPUT);
  
  	lcd.begin(16, 2);
  
  	attachInterrupt(digitalPinToInterrupt(2), morse_button_interrupt, CHANGE);
  	attachInterrupt(digitalPinToInterrupt(3), lcd_button_interrupt, RISING);
	reset();
}


void loop()
{
  	monitor_morse();
  	monitor_serial();
}
