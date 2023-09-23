#define _XTAL_FREQ 1000000

#define RowA    RB0
#define RowB    RB1
#define RowC    RB2
#define RowD    RB3
#define C1      RB4
#define C2      RB5
#define C3      RB6

#define RS      RD2
#define EN      RD3
#define D7      RD7
#define D6      RD6
#define D5      RD5
#define D4      RD4

// 'C' source line config statements

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config CP = OFF         // FLASH Program Memory Code Protection bits (Code protection off)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low Voltage In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection (Code Protection off)
#pragma config WRT = OFF        // FLASH Program Memory Write Enable (Unprotected program memory may not be written to by EECON control)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.



#include<xc.h>
#include "led_keypad3.h"

int R=0;
void main(void)
{
    TRISD=0x00;
    char Key='n';
    Lcd_Init();
    Keypad_Init();
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String("Welcome");
    __delay_ms(1000);
    Lcd_Clear();
    while(1)
    {
        Lcd_Set_Cursor(1,1);
        Lcd_Write_String("Enter Number");
        Key=GetKey();
        Lcd_Set_Cursor(2,1);
        Lcd_Write_Char(Key);
    }
  
}



