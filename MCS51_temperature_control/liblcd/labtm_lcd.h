#ifndef __LabTM_LCD_H
#define __LabTM_LCD_H 1

void LabTM_LCD_Init (void);
void LabTM_LCD_SetPosition (unsigned char row, unsigned char column);
void LabTM_LCD_PrintChar (char c);
void LabTM_LCD_PrintString (char *string);

#endif