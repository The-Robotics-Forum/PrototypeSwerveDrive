/*
 * PrototypeSwerveDrive.cpp
 * Created: 16-10-2018 18:48:07
 * Updated: 16-10-18 19:59	
 * //TODO:	1. Include servo.h
			2. Attach 2 servos on same pin
			3. Control angle using Android App
 */ 
/*************INDEX******************
*BUG � a known bug that should be corrected.
*FIXME � should be corrected.
*HACK � a workaround.
*TODO � something to be done.
*UNDONE � a reversal or "roll back" of previous code.
*XXX � warn other programmers of problematic or misguiding code
*/

#include <m2560/io.h>
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
}		