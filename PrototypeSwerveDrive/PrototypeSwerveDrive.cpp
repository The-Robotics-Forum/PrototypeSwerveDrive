/*
 * PrototypeSwerveDrive.cpp
 * Created: 16-10-2018 18:48:07
 * Updated: 16-10-18 19:59	
 * //TODO:	1. Include servo.h
			2. Attach 2 servos on same pin
			3. Control angle using Android App
 */ 
/*************INDEX******************
*BUG – a known bug that should be corrected.
*FIXME – should be corrected.
*HACK – a workaround.
*TODO – something to be done.
*UNDONE – a reversal or "roll back" of previous code.
*XXX – warn other programmers of problematic or misguiding code
*/




#define F_CPU 1000000UL
#include <m2560/io.h>
#include <m2560/Servo.h>
//#include <ModularLibrary/Cytron.h>
Servo swerve1;
/*#include <avr/io.h>
#include <math.h>
#include <stdlib.h>
#include <util/delay.h>*/
int angle[4]={180,135,135,135};
	
void setup(){
int x;	
DDRB=0xff;
Serial.begin(4800);
swerve1.attach(11);
}
void loop()
{
	/*x=map(15,10,20,30,40);*/
	for(int i=1;i<270;i+=10){
	swerve1.write(i);
	_delay_ms(500);	
	}
	
	/*swerve1.write(180);
	_delay_ms(2000);*/
	//DDRD   |= (1<<PD5);
		/*TCCR1A |= (1<<WGM11) | (1<<COM1A1) | (1<<COM1A0);
		TCCR1B |= (1<<WGM12) | (1<<WGM13);
		TCCR1B |= (1<<CS10);
		//val=90;
		//val=map(val,0,240,17700,19530)
		ICR1 =20000;
		
		//OCR1A = ICR1-(1500-(690*5.55555555));
		OCR1A=18600;
		/*PORTB=0xff;
		_delay_ms(1000);
		PORTB=0x00;
		_delay_ms(1000);*/
}