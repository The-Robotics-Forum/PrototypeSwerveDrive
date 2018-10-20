/*
 * PrototypeSwerveDrive.cpp
 * Created: 16-10-2018 18:48:07
 *	
 * //TODO:	4. Attach 2 servos on same pin
 * 			2. Control angle using Android App
 *			3. Connect motors to motor drivers
 *			1. Keep the bot on venti/stool and drive all four motors		
 */ 

/*************INDEX******************
*BUG – a known bug that should be corrected.
*FIXME – should be corrected.
*HACK – a workaround.
*TODO – something to be done.
*UNDONE – a reversal or "roll back" of previous code.
*XXX – warn other programmers of problematic or misguiding code
***************************************/




#define F_CPU 1000000UL		//Buffer board's crystal is not working
#include <m2560/io.h>
#include <m2560/Servo.h>
#include <ModularLibrary/Cytron.h>
#define pwm1 4
#define pwm2 2
#define pwm3 17
#define pwm4 6

#define dir1 5
#define dir2 3
#define dir3 16
#define dir4 45
/********************Objects***********************/
Servo swerve1;
Servo swerve2;
Servo swerve3;
Servo swerve4;

Cytron motor1(dir1,pwm1);
Cytron motor2(dir2,pwm2);
Cytron motor3(dir3,pwm3);
Cytron motor4(dir4,pwm4);

/********************Variables********************/
#define servoPwm1 11
#define servoPwm2 12
#define servoPwm3 46
#define servoPwm4 7

int correction[4]={-10,-30,-15,5},angle=180;		//HACK:All four servo are not mounted parallely, thus to compensate the offset angle, correction aray is made. 

/******************Main Code********************/	
void setup(){
	Serial.begin(4800);
	swerve1.attach(servoPwm1);
	swerve2.attach(servoPwm2);
	swerve3.attach(servoPwm3);
	swerve4.attach(servoPwm4);
	motor1.direction(1);
}
void loop(){
	//XXX: Check if servo is stalling, if yes don't freak out just make sure it doesn't stall for long time. Check if heating
	swerve1.write(angle+correction[0]);
	swerve2.write(angle+correction[1]);
	swerve3.write(angle+correction[2]);
	swerve4.write(angle+correction[3]);	
	motor1.drive(50);
}