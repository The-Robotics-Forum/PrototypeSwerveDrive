/*
 * PrototypeSwerveDrive.cpp
 * Created: 16-10-2018 18:48:07
 *
 * //TODO:	1. Test Forward and Backward function. Transition should occur gradually and there should be no load on drivers.
 *			2. Write Left & Right functions
 *			3. Test left & right functions
 *
 */

/*************INDEX******************
* BUG : a known bug that should be corrected.
* FIXME : should be corrected.
* HACK : a workaround.
* TODO : something to be done.
* UNDONE : a reversal or "roll back" of previous code.
* XXX : warn other programmers of problematic or misguiding code
***************************************/

//#define F_CPU 1000000UL		//Buffer board's crystal is not working
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

/*void forward()
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
	prevDir='r';
}

void left()
{
	//if(d=='f')


	angle=210;		//FIXME: Servo goes till 200 angle only;
	swerve1.write(angle+correction[0]);
	swerve2.write(angle+correction[1]);
	swerve3.write(angle+correction[2]);
	swerve4.write(angle+correction[3]);
	motors.direction(0,0,0,0);
	motors.drive(250,250,250,250);
	prevDir='l';
}

void angle1(int dist){
	v=(ang1-90) +(dist-1250)*k;
	y=(ang2-90)+ (dist-1250)*k;
	z=(ang3-90)+ (dist-1250)*k;
	w=(ang4-90)+ (dist-1250)*k;

	swerve1.write(v+correction[0]);
	swerve2.write(y+correction[1]);
	swerve3.write(z+correction[2]);
	swerve4.write(w+correction[3]);
}

void angle2(int dist){
	v=ang1 + (dist-2000)*k;
	y=ang2 + (dist-2000)*k;
	z=ang3 + (dist-2000)*k;
	w=ang4 + (dist-2000)*k;

	swerve1.write(v+correction[0]);
	swerve2.write(y+correction[1]);
	swerve3.write(z+correction[2]);
	swerve4.write(w+correction[3]);
}

void angle3(int dist){
	v=(ang1+90)-(dist-2750)*k;
	y=(ang2+90)-(dist-2750)*k;
	z=(ang3+90)-(dist-2750)*k;
	w=(ang4+90)-(dist-2750)*k;

	swerve1.write(v+correction[0]);
	swerve2.write(y+correction[1]);
	swerve3.write(z+correction[2]);
	swerve4.write(w+correction[3]);
}

void angle4(int dist){
	v=ang1-(dist-500)*k;
	y=ang2-(dist-500)*k;
	z=ang3-(dist-500)*k;
	w=ang4-(dist-500)*k;

	swerve1.write(v+correction[0]);
	swerve2.write(y+correction[1]);
	swerve3.write(z+correction[2]);
	swerve4.write(w+correction[3]);
}

void angle5(int dist){
	v=ang1-(dist-3500)*k;
	y=ang2-(dist-3500)*k;
	z=ang3-(dist-3500)*k;
	w=ang4-(dist-3500)*k;

	swerve1.write(v+correction[0]);
	swerve2.write(y+correction[1]);
	swerve3.write(z+correction[2]);
	swerve4.write(w+correction[3]);
}

void angle6(int dist){
	v=(ang1-90)+ (dist-4250)*k;
	y=(ang2-90)+ (dist-4250)*k;
	z=(ang3-90)+ (dist-4250)*k;
	w=(ang4-90)+ (dist-4250)*k;

	swerve1.write(v+correction[0]);
	swerve2.write(y+correction[1]);
	swerve3.write(z+correction[2]);
	swerve4.write(w+correction[3]);
}

void angle7(int dist){
	v=ang1+(dist-5000)*k;
	y=ang2+(dist-5000)*k;
	z=ang3+(dist-5000)*k;
	w=ang3+(dist-5000)*k;

	swerve1.write(v+correction[0]);
	swerve2.write(y+correction[1]);
	swerve3.write(z+correction[2]);
	swerve4.write(w+correction[3]);
}*/

void simulate(){
	dist=500;	//initial distance
	while(dist<=1250){
		ychorddist=ychorddist+5;
	  angl=asin(ychorddist/amp);
		dist=map(angl,500,1250,0,pi);
		alpha=atan(1.05*cos(0.0020943951*dist-2.61799387799))*180/M_PI;
		swerve1.write(alpha+correction[0]);
		swerve2.write(alpha+correction[1]);
		swerve3.write(alpha+correction[2]);
		swerve4.write(alpha+correction[3]);
		motors.direction(0,0,0,0);
		motors.drive(250,250,250,250);
	}
}


void setup(){
	swerve1.attach(servoPwm1);
	swerve2.attach(servoPwm2);
	swerve3.attach(servoPwm3);
	swerve4.attach(servoPwm4);
	for(dist=500;dist<=1250;dist+=5){
		mot_theta=atan(1.05*cos(0.0020943951*dist-2.61799387799))*180/M_PI;
    swerve1.write(mot_theta+correction[0]);

		swerve2.write(mot_theta+correction[1]);
		swerve3.write(mot_theta+correction[2]);
		swerve4.write(mot_theta+correction[3]);
		motors.direction(0,0,0,0);
		motors.drive(250,250,250,250);
	}
}


	simulate();
	motors.drive(0,0,0,0);
}

void loop(){
	//XXX: Check if servo is stalling, if yes don't freak out just make sure it doesn't stall for long time. Check if heating
}
