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

#include <m2560/io.h>
<<<<<<< HEAD
<<<<<<< HEAD
#include <string.h>
//#include <m2560/Servo.h>
//#include <ModularLibrary/Cytron.h>

static volatile int pulse = 0;
static volatile int i = 0;
uint8_t COUNTA = 0;//storing digital output 	
=======

>>>>>>> parent of 1e7bf21... Included Cytron.h
void setup(){
	DDRA = 0xFF;
    DDRD = 0b11111011;
    _delay_ms(50);
	EIMSK|=(1<<INT0);//enabling interrupt0
	EICRA|=(1<<ISC00);//setting interrupt triggering logic change
	
	sei();
	Serial.begin(4800);
	Serial.write(1);
}	
void loop(){
	//Serial.write(2);
	PORTD|=(1<<PIND0);
	_delay_us(15);///triggering the sensor for 15usec
	PORTD &=~(1<<PIND0);
	//Serial.write(3);
	COUNTA = pulse/58;
	Serial.write(COUNTA);
}

ISR(INT0_vect)//interrupt service routine when there is a change in logic level

{
	//Serial.write(5);
	if (i==1)//when logic from HIGH to LOW

	{
	//Serial.write(6);
	TCCR1B=0;//disabling counter

	pulse=TCNT1;//count memory is updated to integer

	TCNT1=0;//resetting the counter memory

	i=0;

	}

	if (i==0)//when logic change from LOW to HIGH

	{
	//Serial.write(7);
	TCCR1B|=(1<<CS10);//enabling counter

	i=1;

	}

=======
#include <m2560/Servo.h>
#include <ModularLibrary/Cytron.h>
void setup(){
	pinMode(13,OUTPUT);
}	
void loop(){
		digitalWrite(13,HIGH);
		_delay_ms(1000);
		digitalWrite(13,LOW);
		_delay_ms(1000);
>>>>>>> parent of 6ea3b60... Sinosudal Wave travelling
}		