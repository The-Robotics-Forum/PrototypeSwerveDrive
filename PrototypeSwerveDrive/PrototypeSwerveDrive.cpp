/*
 * PrototypeSwerveDrive.cpp
 * Created: 16-10-2018 18:48:07
 *
 * //TODO:	1. Include servo.h
			2. Attach 2 servos on same pin
			3. Control angle using Android App
 */ 

#include <m2560/io.h>

int main(void)
{
	pinMode(13,OUTPUT);
    while(1)
    {
		digitalWrite(13,HIGH);
		_delay_ms(1000);
		digitalWrite(13,LOW);
		_delay_ms(1000);
	}		 
}