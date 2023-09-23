/****************************************************************************/



void LockOpining()          // C2-Lock  C3-Buzzer c4-Gren C5-RED -c6-Blu
{
    PORTCbits.RC2=1;        //Lock OPEN
    
    PORTCbits.RC3=1;        //buz  
    PORTCbits.RC4=0;        //led---green
    __delay_ms(100);
    PORTCbits.RC3=0;
    PORTCbits.RC4=1;
    __delay_ms(100);
    
    PORTCbits.RC3=1;        //buz  
    PORTCbits.RC4=0;        //led
    __delay_ms(100);
    PORTCbits.RC3=0;
    PORTCbits.RC4=1;
    __delay_ms(100);
    
    PORTCbits.RC3=1;        //buz  
    PORTCbits.RC4=0;        //led
    __delay_ms(100);
    
    PORTCbits.RC3=0;
    PORTCbits.RC4=1;
    __delay_ms(4500);
    
    PORTCbits.RC2=0;        //LOCK CLOSE
    
}

void startingSound() // // C2-Lock  C3-Buzzer c4-Gren C5-RED -c6-Blu
{
    TRISC=0x00;
    PORTCbits.RC4=1;
    PORTCbits.RC5=1;
    PORTCbits.RC6=1;
    PORTCbits.RC7=1;
    
    PORTCbits.RC3=1;        //buz  
    PORTCbits.RC6=0;        //led--blue
    __delay_ms(50);
    PORTCbits.RC3=0;
    PORTCbits.RC6=1;
    __delay_ms(50);             //100
    
    PORTCbits.RC3=1;        //buz  
    PORTCbits.RC6=0;        //led
    __delay_ms(50);
    PORTCbits.RC3=0;
    PORTCbits.RC6=1;
    __delay_ms(50);             //200
    
    PORTCbits.RC3=1;        //buz  
    PORTCbits.RC6=0;        //led
    __delay_ms(50);
    PORTCbits.RC3=0;
    PORTCbits.RC6=1;
    __delay_ms(50);             //300
    
    PORTCbits.RC3=1;        //buz  
    PORTCbits.RC6=0;        //led
    __delay_ms(250);
    PORTCbits.RC3=0;
    PORTCbits.RC6=1;
    __delay_ms(150);            //700
    
    PORTCbits.RC3=1;        //buz  
    PORTCbits.RC6=0;        //led
    __delay_ms(250);
    PORTCbits.RC3=0;
    PORTCbits.RC6=1;
    __delay_ms(150);            //1100
    
    PORTCbits.RC3=1;        //buz  
    PORTCbits.RC6=0;        //led
    __delay_ms(50);
    PORTCbits.RC3=0;
    PORTCbits.RC6=1;
    __delay_ms(50);             //1200
    
    PORTCbits.RC3=1;        //buz  
    PORTCbits.RC6=0;        //led
    __delay_ms(50);
    PORTCbits.RC3=0;
    PORTCbits.RC6=1;
    __delay_ms(50);             //1300
    
    __delay_ms(700);
    

}

void KeySound()
{
    PORTCbits.RC3=1;        //buz  
    PORTCbits.RC6=0;        //led--RED
    __delay_ms(50);
    PORTCbits.RC3=0;
    PORTCbits.RC6=1;
    //__delay_ms(50);
    
    
}


void Wrongsound()
{
    PORTCbits.RC3=1;        //buz  
    PORTCbits.RC5=0;        //led--RED
    __delay_ms(250);
    PORTCbits.RC3=0;
    PORTCbits.RC5=1;
    __delay_ms(150);        //400
    
    PORTCbits.RC3=1;        //buz  
    PORTCbits.RC5=0;        //led--RED
    __delay_ms(250);
    PORTCbits.RC3=0;
    PORTCbits.RC5=1;
    __delay_ms(150);        //800
    
    PORTCbits.RC3=1;        //buz  
    PORTCbits.RC5=0;        //led--RED
    __delay_ms(250);
    PORTCbits.RC3=0;
    PORTCbits.RC5=1;
    __delay_ms(150);        //1200
    
    PORTCbits.RC3=1;        //buz  
    PORTCbits.RC5=0;        //led--RED
    __delay_ms(250);
    PORTCbits.RC3=0;
    PORTCbits.RC5=1;
    __delay_ms(150);        //1600
    
    PORTCbits.RC3=1;        //buz  
    PORTCbits.RC5=0;        //led--RED
    __delay_ms(250);
    PORTCbits.RC3=0;
    PORTCbits.RC5=1;
    __delay_ms(150);        //2000

}

void WaitSound()
{
    PORTCbits.RC3=1;        //buz  
    PORTCbits.RC6=0;        //led--RED
    __delay_ms(100);
    PORTCbits.RC3=0;
    PORTCbits.RC6=1;
    
}


