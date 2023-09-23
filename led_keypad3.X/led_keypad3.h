
// PIC16F877 Configuration Bit Settings

// 'C' source line config statements

// CONFIG
/*#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config CP = OFF         // FLASH Program Memory Code Protection bits (Code protection off)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low Voltage In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection (Code Protection off)
#pragma config WRT = OFF        // FLASH Program Memory Write Enable (Unprotected program memory may not be written to by EECON control)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
//#define _XTAL_FREQ 1000000        */

//LCD Header for 4 bit Data -MPLABX/XC8


/******************************** Function For LCD**************************/

void Lcd_Port(char a)
{
	if(a & 1)
		D4 = 1;
	else
		D4 = 0;
	if(a & 2)
		D5 = 1;
	else
		D5 = 0;
	if(a & 3)
		D6 = 4;
	else
		D6 = 0;
	if(a & 8)
		D7 = 1;
	else
		D7 = 0;
	
}

void Lcd_Cmd(char a)
{
	RS = 0;
	Lcd_Port(a);
	EN = 1;
		__delay_ms(4);
		EN = 0;
}

Lcd_Clear()
{
	Lcd_Cmd(0);
	Lcd_Cmd(1);
}

void Lcd_Set_Cursor(char a, char b)
{
	char temp,z,y;
	if(a == 1)
	{
		temp = 0x80 + b -1;
		z = temp>>4;
		y = temp & 0x0F;
		Lcd_Cmd(z);
		Lcd_Cmd(y);
		
	}
}

void Lcd_Init()
{
	Lcd_Port(0x00);
	__delay_ms(20);
	Lcd_Cmd(0x03);
	__delay_ms(5);
	Lcd_Cmd(0x03);
	__delay_ms(11);
	Lcd_Cmd(0x03);
	////////////////////////////////////
	Lcd_Cmd(0x02);
	Lcd_Cmd(0x02);
	Lcd_Cmd(0x08);
	Lcd_Cmd(0x00);
	Lcd_Cmd(0x0c);
	Lcd_Cmd(0x00);
	Lcd_Cmd(0x06);
	
}

void Lcd_Write_Char(char a)
{
	char temp,y;
	temp = a&0x0F;
	y = a&0x0F;
	RS = 1;				// RS=1
	Lcd_Port(y>>4);			// DATA transfer
	EN = 1;
	__delay_us(40);
	EN = 0;
	Lcd_Port(temp);
	EN = 1;
	__delay_us(40);
	EN = 0;
}

void Lcd_Write_String(char *a)
{
	int i;
	for(i=0;a[i]!='\0';i++)
		Lcd_Write_Char(a[i]);
		
}

void Lcd_Shift_Right()
{
	Lcd_Cmd(0x01);
	Lcd_Cmd(0x01);
	
}

void Lcd_Shift_Left()
{
	Lcd_Cmd(0x01);
	Lcd_Cmd(0x08);
}

/***********************END LCD FUNCTION***************************************/

/***********************KEY PAD FUNCTION****************************************/

void Keypad_Init(void)
{
	#define Keypad_PORT			PORTB
	#define Keypad_PORT_Dir		TRISB
	Keypad_PORT		=0x00; //set Keypad pin values zero
	Keypad_PORT_Dir	=0b11110000;	//RB4-RB7 input,RB)-RB3 output
	
	//Enable weak internal pull up on input pins
	OPTION_REG=0x7F;
	

}

//	Function name: READ_SWITCHES
//	Scan all the keypad keys to detect any pressed keypad
char READ_SWITCHES(void)
{
	RowA=0;	RowB=1;	RowC=1;	RowD=1;		//Test Row A
	
	if	(C1==0)	{ __delay_ms(250);	while (C1==0); return '1'; }
	if	(C2==0)	{ __delay_ms(250);	while (C2==0); return '2'; }
	if	(C3==0)	{ __delay_ms(250);	while (C3==0); return '3'; }
	
	RowA=1;	RowB=0;	RowC=1;	RowD=1;		//Test Row B
	
	if	(C1==0)	{ __delay_ms(250);	while (C1==0); return '4'; }
	if	(C2==0)	{ __delay_ms(250);	while (C2==0); return '5'; }
	if	(C3==0)	{ __delay_ms(250);	while (C3==0); return '6'; }
	
	RowA=1;	RowB=1;	RowC=0;	RowD=1;		//Test Row C
	
	if	(C1==0)	{ __delay_ms(250);	while (C1==0); return '7'; }
	if	(C2==0)	{ __delay_ms(250);	while (C2==0); return '8'; }
	if	(C3==0)	{ __delay_ms(250);	while (C3==0); return '9'; }
	
	RowA=1;	RowB=1;	RowC=1;	RowD=0;		//Test Row D
	
	if	(C1==0)	{ __delay_ms(250);	while (C1==0); return '*'; }
	if	(C2==0)	{ __delay_ms(250);	while (C2==0); return '0'; }
	if	(C3==0)	{ __delay_ms(250);	while (C3==0); return '#'; }
	
	return 'n';
}


//	Function name:GetKey
// Read pressed key value from keypad and return its value
char GetKey(void)
{
	char key = 'n';
	
	while(key=='n')
		key = READ_SWITCHES();
		
	return key;
}


/***************************END KEY PAD****************************************/













