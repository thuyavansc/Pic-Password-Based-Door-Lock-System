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

#include "Lcd_KeyPad.h";
#include "Buz_Lock_Led.h";
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



void main(void)
{
    TRISD=0x00;
    
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
    startingSound();
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
        KeySound();
        
        Key2=GetKey();
        Lcd_Set_Cursor(2,2);
        Lcd_Write_Char(Key2);
        KeySound();
        
        Key3=GetKey();
        Lcd_Set_Cursor(2,3);
        Lcd_Write_Char(Key3);
        KeySound();
        
        Key4=GetKey();
        Lcd_Set_Cursor(2,4);
        Lcd_Write_Char(Key4);
        KeySound();
        
        
        
        __delay_ms(950);
        
        if (p1==Key1 & p2==Key2 & p3==Key3 & p4==Key4 )
            {
        
                Lcd_Clear();
                Lcd_Set_Cursor(1,1);
                Lcd_Write_String("Correct Password");
                Lcd_Set_Cursor(2,1);
                Lcd_Write_String("Door Opened");
                
                LockOpining();
                
                R=0;
                
            }
        else if (r1==Key1 & r2==Key2 & r3==Key3 & r4==Key4  )
            {
        
                Lcd_Clear();
                Lcd_Set_Cursor(1,1);
                Lcd_Write_String("Reset Password");
                
                rs11=GetKey();
                Lcd_Set_Cursor(2,1);
                Lcd_Write_Char(rs11);
                KeySound();
                
                rs21=GetKey();
                Lcd_Set_Cursor(2,2);
                Lcd_Write_Char(rs21);
                KeySound();
                
                rs31=GetKey();
                Lcd_Set_Cursor(2,3);
                Lcd_Write_Char(rs31);
                KeySound();
                
                rs41=GetKey();
                Lcd_Set_Cursor(2,4);
                Lcd_Write_Char(rs41);
                KeySound();
                
                __delay_ms(950);
                
                
                Lcd_Clear();
                Lcd_Set_Cursor(1,1);
                Lcd_Write_String("Enter PW Again");
                
                rs12=GetKey();
                Lcd_Set_Cursor(2,1);
                Lcd_Write_Char(rs12);
                KeySound();
                
                rs22=GetKey();
                Lcd_Set_Cursor(2,2);
                Lcd_Write_Char(rs22);
                KeySound();
                
                rs32=GetKey();
                Lcd_Set_Cursor(2,3);
                Lcd_Write_Char(rs32);
                KeySound();
                
                rs42=GetKey();
                Lcd_Set_Cursor(2,4);
                Lcd_Write_Char(rs42);
                KeySound();
                
                __delay_ms(950);
                
                if ( rs11==rs12 & rs21==rs22 & rs31==rs32 &rs41==rs42 )
                {
                    p1=rs12;
                    p2=rs22;
                    p3=rs32;
                    p4=rs42;
                    
                    Lcd_Clear();
                    Lcd_Set_Cursor(1,1);
                    Lcd_Write_String("PW Reseted");
                    
                    
                    Lcd_Set_Cursor(2,1);
                    Lcd_Write_String("Thank You");
                    
                    Wrongsound();
                    R=0;
                    
                    
                }  
            }
        else if ( R==5  )
        {
            Lcd_Clear();
            Lcd_Set_Cursor(1,1);
            Lcd_Write_String("Wait For 30 Sec");
            
            
            
            for (int i=0;i<=30;i++)
            {
                sprintf(Nes1 , "%d", R1 );
                Lcd_Clear();
                Lcd_Set_Cursor(1,1);
                Lcd_Write_String("Wait For 30 Sec");
                Lcd_Set_Cursor(2,1);
                Lcd_Write_String(Nes1);
                WaitSound();
                R1=R1-1;
                __delay_ms(900);
                 
                
            
            }
            R1=30;
            R=0;
            
            
            
        }
        else   
            {
                Lcd_Clear();
                Lcd_Set_Cursor(1,1);
                Lcd_Write_String("Try Again");
                
                Wrongsound();                    
            }
            
            
    }
  
}

