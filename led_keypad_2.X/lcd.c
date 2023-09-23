#define _XTAL_FREQ 16000000

#define RowA    RB0
#define RowB    RB1
#define RowC    RB2
#define RowD    RB3
#define C1      RB4
#define C2      RB5
#define C3      RB6

#define RS RD2
#define EN RD3
#define D4 RD4
#define D5 RD5
#define D6 RD6
#define D7 RD7

#include <xc.h>

#include "lcd.h";
#include <stdio.h>
#include <stdlib.h>
// BEGIN CONFIG

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config CP = OFF         // FLASH Program Memory Code Protection bits (Code protection off)
#pragma config BOREN = ON      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low Voltage In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection (Code Protection off)
#pragma config WRT = OFF       // FLASH Program Memory Write Enable (Unprotected program memory may be written to by EECON control)

//END CONFIG

void Lock_Buz()
{
    TRISC=0x00;
    PORTCbits.RC2=1;
    PORTCbits.RC3=1;    //buz
    PORTCbits.RC4=1;    //led
    __delay_ms(500);
    PORTCbits.RC3=0;    //buz
    PORTCbits.RC4=0;    //led
    __delay_ms(500);
    PORTCbits.RC3=1;    //buz
    PORTCbits.RC4=1;    //led
    __delay_ms(500);
    PORTCbits.RC3=0;    //buz
    PORTCbits.RC4=0;    //led
    __delay_ms(500);
    PORTCbits.RC3=1;    //buz
    PORTCbits.RC4=1;    //led
     __delay_ms(500);
    PORTCbits.RC3=0;    //buz
    PORTCbits.RC4=0;     //led
    __delay_ms(3000);
    PORTCbits.RC2=0;
            
}

void Buzzer_T1()
{
    TRISC=0x00;
    PORTCbits.RC3=1;
    __delay_ms(1000);
    PORTCbits.RC3=0;
     __delay_ms(1000);
    PORTCbits.RC3=1;
    __delay_ms(1000);
    PORTCbits.RC3=0;
     __delay_ms(1000);
     PORTCbits.RC3=1;
    __delay_ms(1000);
    PORTCbits.RC3=0;

}   


void main(void)
{
    TRISD=0x00;
    //TRISC=0x00;
    
    int R=0;
    int R1=30;
    char Nes[12];
    char Nes1[12];
    
    char Key1='n1';
    char Key2='n2';
    char Key3='n3';
    char Key4='n4';
    
    char p1='1';  char p2='2';  char p3='3';  char p4='4';
    char r1='*';    char r2='0';    char r3='0';    char r4='#';
    
    char rs11;    char rs21;    char rs31;    char rs41;
    char rs12;    char rs22;    char rs32;    char rs42;
    
    Lcd_Init();         
    Keypad_Init();
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String("WElcome TO SLTC");
    __delay_ms(2000);
    Lcd_Clear();
    while(1)
    {
        Lcd_Clear();
        Lcd_Set_Cursor(1,1);            
        Lcd_Write_String("Enter the Key");
        
        sprintf(Nes , "%d", R );
        Lcd_Set_Cursor(1,15);
        Lcd_Write_String(Nes);
        R=R+1;
            
        Key1=GetKey();
        Lcd_Set_Cursor(2,1);
        Lcd_Write_Char(Key1);       
        //__delay_ms(50);        //
        Key2=GetKey();
        Lcd_Set_Cursor(2,2);
        Lcd_Write_Char(Key2);
        //__delay_ms(50);
         Key3=GetKey();
        Lcd_Set_Cursor(2,3);
        Lcd_Write_Char(Key3);
        //__delay_ms(50);
        Key4=GetKey();
        Lcd_Set_Cursor(2,4);
        Lcd_Write_Char(Key4);
        //__delay_ms(50);
        
        
        __delay_ms(1000);
        
        if (p1==Key1 & p2==Key2 & p3==Key3 & p4==Key4 )
            {
        
                Lcd_Clear();
                Lcd_Set_Cursor(1,1);
                Lcd_Write_String("Correct Password");
                Lcd_Set_Cursor(2,1);
                Lcd_Write_String("Door Opened");
                
                /*TRISC=0x00;
                PORTCbits.RC2=1;
                __delay_ms(5000);
                PORTCbits.RC2=0;*/
                Lock_Buz();
                //Buzzer_T1();
                R=0;
                //__delay_ms(2000);
            }
        else if (r1==Key1 & r2==Key2 & r3==Key3 & r4==Key4  )
            {
        
                Lcd_Clear();
                Lcd_Set_Cursor(1,1);
                Lcd_Write_String("Reset Password");
                
                rs11=GetKey();
                Lcd_Set_Cursor(2,1);
                Lcd_Write_Char(rs11);
                // __delay_ms(1000);
                rs21=GetKey();
                Lcd_Set_Cursor(2,2);
                Lcd_Write_Char(rs21);
                //__delay_ms(1000);
                rs31=GetKey();
                Lcd_Set_Cursor(2,3);
                Lcd_Write_Char(rs31);
                //__delay_ms(1000);
                rs41=GetKey();
                Lcd_Set_Cursor(2,4);
                Lcd_Write_Char(rs41);
                __delay_ms(1000);
                
                
                Lcd_Clear();
                Lcd_Set_Cursor(1,1);
                Lcd_Write_String("Enter PW Again");
                
                rs12=GetKey();
                Lcd_Set_Cursor(2,1);
                Lcd_Write_Char(rs12);
                // __delay_ms(1000);
                rs22=GetKey();
                Lcd_Set_Cursor(2,2);
                Lcd_Write_Char(rs22);
                //__delay_ms(1000);
                rs32=GetKey();
                Lcd_Set_Cursor(2,3);
                Lcd_Write_Char(rs32);
                //__delay_ms(1000);
                rs42=GetKey();
                Lcd_Set_Cursor(2,4);
                Lcd_Write_Char(rs42);
                __delay_ms(1000);
                
                if ( rs11==rs12 & rs21==rs22 & rs31==rs32 &rs41==rs42 )
                {
                    p1=rs12;
                    p2=rs22;
                    p3=rs32;
                    p4=rs42;
                    
                    Lcd_Clear();
                    Lcd_Set_Cursor(1,1);
                    Lcd_Write_String("PW Reseted");
                    
                    //Lcd_Clear();
                    Lcd_Set_Cursor(2,1);
                    Lcd_Write_String("Thank You");
                    
                    __delay_ms(2000);
                    
                    
                }  
            }
        else if ( R==5  )
        {
            Lcd_Clear();
            Lcd_Set_Cursor(1,1);
            Lcd_Write_String("Wait For 30 Sec");
            
            TRISC=0x00;
            
            for (int i=0;i<=30;i++)
            {
                sprintf(Nes1 , "%d", R1 );
                Lcd_Clear();
                Lcd_Set_Cursor(1,1);
                Lcd_Write_String("Wait For 30 Sec");
                Lcd_Set_Cursor(2,1);
                Lcd_Write_String(Nes1);
                PORTCbits.RC4=1;    //led
                R1=R1-1;
                __delay_ms(500);
                 PORTCbits.RC4=0;    //led
                __delay_ms(500);
                
            
            }
            R1=30;
            R=0;
            
            
            
        }
        else   
            {
                Lcd_Clear();
                Lcd_Set_Cursor(1,1);
                Lcd_Write_String("Try Again");
                __delay_ms(2000);
                //Buzzer_T1();                     
            }
            
            
    }
  
}

/*void Lock_Open()
{
    TRISC=0x00;
    PORTCbits.RC2=1;
    __delay_ms(5000);
    PORTCbits.RC2=0;
            

}
*/
/*void Buzzer_T1()
{
    PORTCbits.RC3=1;
    __delay_ms(500);
    PORTCbits.RC3=0;

}
*/
/*void Buzzer_T2()
{
    PORTCbits.RC3=1;
    __delay_ms(1000);
    PORTCbits.RC3=0;

}*/

