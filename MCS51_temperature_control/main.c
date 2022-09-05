#include <8052.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <labtm_lcd.h>

#define INT0 0x0003

volatile __xdata __at(0xFA00) unsigned char LED;    /* LED diodes address */
volatile __xdata __at(0xF8C0) unsigned char ADC;    /* ADC address */

unsigned char read; /* ADC read */
char* buffer;       /* Conversion buffer */
float value;        /* Measurement value */
int i;              /* Iterator */
int proceed;        /* Polling flag for semaphore-like purpose, due to no semaphore support */

void LCD_clear(void);                           /* Clear LCD screen */
void check_potentiometer(void);                 /* Display the value of potentiometer voltage on LED diodes */
void check_temperature(void);                   /* Temperature read function */
void reverse_str(char str[]);                   /* Reverse a string */
void disp_temperature_val(unsigned char val);   /* Display temperature read as string */
void disp_binary_as_dec_str(unsigned char val); /* Display binary value as string */

void handle_interrupt(void) __interrupt(0);     /* Interrupt callback for ADC */

void main(void) {
    LabTM_LCD_Init();                   /* LCD initialization */
    LabTM_LCD_SetPosition(1, 1);        /* Set cursor at LCD origin */
    LabTM_LCD_PrintChar('A');           /* Display a character */
    LabTM_LCD_SetPosition(2, 1);        /* Set cursor in second line */
    LabTM_LCD_PrintString("Test");      /* Display string */

    proceed = 0;

    while(1) {
        while(proceed == 0)
            check_potentiometer();      /* Initialize the ADC conversion for potentiometer voltage */
        proceed = 0;                    /* Reset the polling flag */
        LED = read;                     /* Display the value of potentiometer voltage on LEDs */
        while(proceed == 0)
            check_temperature();        /* Send temperature sensor address to ADC to initialize another read */
        proceed = 0;                    /* Reset the polling flag */

        LCD_clear();                    /* Clear LCD screen */
        LabTM_LCD_SetPosition(1, 1);    /* Set cursor to LCD origin */
        disp_binary_as_dec_str(read);   /* Display the read temperature as an ADC value (8-bit range) */

        disp_temperature_val(read);     /* Display the calculated temperature */
    };
}

/* Display binary value as a string */
void disp_binary_as_dec_str(unsigned char val) {
    i = 0;                              
    buffer = malloc(sizeof(char)*4);    /* Create buffer for 3-digit decimal value */
    mask = 0x1;                         /* Create binary AND mask */
    for (i = 0; i < 8; i++) {           /* Iterate over all the bits in the value in LSB first order */
        buffer[i] = val & 0x1 + '0';    /* Extract the digit */
        val = val >> 1;                 /* Bitshift the value */
    }
    buffer[i] = '\0';                   /* End the string */
    reverse_str(buffer);                /* Reverse the string to acquire the correct order of bits */
    LabTM_LCD_PrintString(buffer);      /* Display the buffer content */
    free(buffer);                       /* Free the buffer */
}

/* Read the temperature */
void check_temperature(void) {
    ADC = 0x0D;         /* Initialize the ADC temperature read from channel 6 */
}

/* Read the potentiometer */
void check_potentiometer(void) {
    ADC = 0x0C;         /* Initialize the ADC potentiometer read from channel 5 */
}

/* Clear the LCD screen */
void LCD_clear(void) {
    /* Clear the first row by displaying spaces */
    LabTM_LCD_SetPosition(1, 1);                
    LabTM_LCD_PrintString("                ");  
    /* Clear the second row by displaying spaces */
    LabTM_LCD_SetPosition(2, 1);                
    LabTM_LCD_PrintString("                ");
    /* Move cursor back to LCD origin */
    LabTM_LCD_SetPosition(1, 1);                
}

/* Wyswietl odczyt temperatury jako wartosc */
void disp_temperature_val(unsigned char adc_read) {
    unsigned char temp;                     /* Conversion temp variable */
    LCD_clear();                            /* Clear the LCD screen */

    value = adc_read*2.5f;                  /* Multiply the read by ref voltage */
    value /= 256;                           /* Divide by the ADC resolution to acquire read in voltage */
    value *= 100;                           /* Multiply by 100 (1*C = 0.01V) to calculate the read in degrees Celsius */

    buffer = malloc(sizeof(char)*17);       /* Create buffer for the whole LCD line */
    value *= 100;                           /* Multiply the value to extract the floating point value with 2 digits past comma */
    temp = (unsigned char)value;            /* Cast away unnecessary part of the read (3 and more digits past comma) */

    /* Convert the fractional part of the read and save to the buffer */
    for(i = 0; i < 2; i++) {                
        buffer[i] = (temp % 10) + '0';
        temp /= 10;
    }

    buffer[i] = '.';                        /* Insert comma separator */
    i++;                                    

    /* Convert the integer part of the read and append to the buffer */
    while(temp != 0) {
        buffer[i] = (temp % 10) + '0';
        temp /= 10;
        i++;
    }

    /* If the integer part was equal to 0 (thus not saved in the buffer), append 0 to the buffer */
    if(i == 3) {
        buffer[i] = '0';
        i++;
    }

    buffer[i] = '\0';                       /* End the string */
    reverse_str(buffer);                    /* Reverse the string to obtain correct digits order */

    /* Display the temperature value */
    LabTM_LCD_SetPosition(1, 1);
    LabTM_LCD_PrintString("Temperatura");
    LabTM_LCD_SetPosition(2, 4);
    LabTM_LCD_PrintString(buffer);
    LabTM_LCD_PrintString(" *C");

    free(buffer);                           /* Free the buffer */
}

/* Reverse string function */
void reverse_str(char str[]) {
    unsigned char length;               /* String length */
    char temp;                          /* Value swap temporary variable */
    length = strlen(str);               /* Read the string length */
    i = 0;

    /* Reverse the string */
    while(i <= length / 2) {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

/* Interrupt handler */
void handle_interrupt(void) __interrupt(0) {
    read = ADC;  /* Read the ADC value */
    proceed = 1; /* Set the proceed flag to unblock the main function */
}
