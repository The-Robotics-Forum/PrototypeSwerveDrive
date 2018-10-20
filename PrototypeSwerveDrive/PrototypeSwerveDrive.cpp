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
/********************Objects***********************/
Servo swerve1;
Servo swerve2;
Servo swerve4;
Servo swerve3;

/********************Variables********************/
int correction[4]={-5,-15,-15,5},angle=40;
	
void setup(){
Serial.begin(4800);
swerve1.attach(11);
swerve2.attach(12);
swerve3.attach(6);
swerve4.attach(7);
}
void loop(){
	swerve1.write(angle+correction[0]);
	swerve2.write(angle+correction[1]);
	swerve3.write(angle+correction[2]);
	swerve4.write(angle+correction[3]);
	delay(1000);
}