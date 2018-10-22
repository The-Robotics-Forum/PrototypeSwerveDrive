/*
 * PrototypeSwerveDrive.cpp
 * Created: 16-10-2018 18:48:07
 *
 * //TODO:	1. Test Forward and Backward function. Transition should occur gradually and there should be no load on drivers.
 *			2. Write Left & Right functions
 *			3. Test left & right functions
 *			4. Check the value of Fuse bits and configure fuse bits to use external clk. (Take some senior with you if I am not there, preferably Sahil)
 */

/*************INDEX******************
* BUG : a known bug that should be corrected.
* FIXME : should be corrected.
* HACK : a workaround.
* TODO : something to be done.
* UNDONE : a reversal or "roll back" of previous code.
* XXX : warn other programmers of problematic or misguiding code
***************************************/

#define F_CPU 1000000UL		//Buffer board's crystal is not working
#include <m2560/io.h>
#include <m2560/Servo.h>
#include <ModularLibrary/Cytron.h>
#define pwm1 4
#define pwm2 13
#define pwm3 10
#define pwm4 9

#define dir1 30
#define dir2 31
#define dir3 32
#define dir4 33
/********************Objects***********************/
Servo swerve1;
Servo swerve2;
Servo swerve3;
Servo swerve4;
Cytron motors(dir1,pwm1,dir2,pwm2,dir3,pwm3,dir4,pwm4);

/********************Variables********************/
#define servoPwm1 11
#define servoPwm2 12
#define servoPwm3 5
#define servoPwm4 2

int correction[4]={-10,-20,-25,5},angle=30;		//HACK:All four servo are not mounted parallely, thus to compensate the offset angle, correction aray is made.
char prevDir;

/******************Main Code********************/

void forward()
{
	if(prevDir=='b')
	motors.drive(0,0,0,0);

	angle=120;
	swerve1.write(angle+correction[0]);
	swerve2.write(angle+correction[1]);
	swerve3.write(angle+correction[2]);
	swerve4.write(angle+correction[3]);
	delay(700);
	motors.direction(0,1,1,0);
	motors.drive(100,100,100,100);
	prevDir='f';
}
void backward()
{
	if(prevDir=='f')
	motors.drive(0,0,0,0);

	angle=120;
	swerve1.write(angle+correction[0]);
	swerve2.write(angle+correction[1]);
	swerve3.write(angle+correction[2]);
	swerve4.write(angle+correction[3]);
	delay(700);
	motors.direction(0,0,0,0);
	motors.drive(100,100,100,100);
	prevDir='b';
}
void right()
{
	angle=30;
	swerve1.write(angle+correction[0]);
	swerve2.write(angle+correction[1]);
	swerve3.write(angle+correction[2]);
	swerve4.write(angle+correction[3]);
	delay(700);
	motors.direction(1,1,1,1);
	motors.drive(100,100,100,100);
//	prevDir='f'; ??
}
void left()
{
	//if(d=='f')


	angle=210;
	swerve1.write(angle+correction[0]);
	swerve2.write(angle+correction[1]);
	swerve3.write(angle+correction[2]);
	swerve4.write(angle+correction[3]);
	motors.direction(0,0,0,0);
	motors.drive(200,200,200,200);
//	d='b';
}
void setup(){
	swerve1.attach(servoPwm1);
	swerve2.attach(servoPwm2);
	swerve3.attach(servoPwm3);
	swerve4.attach(servoPwm4);
}

void loop(){
	//XXX: Check if servo is stalling, if yes don't freak out just make sure it doesn't stall for long time. Check if heating
	/*forward();
	delay(1000);
	backward();
	delay(1000);*/
	for(angle=0;angle<180;)
{angle+=10;

swerve1.write(angle+correction[0]);
swerve2.write(angle+correction[1]);
swerve3.write(angle+correction[2]);
swerve4.write(angle+correction[3]);
motors.direction(0,0,0,0);
motors.drive(200,200,200,200);
_delay_ms(800);

}
	/*delay(1000);
	forward();
	delay(1000);*/
}
