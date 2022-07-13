#pragma config(Sensor, port2,  reflectedValue, sensorEV3_Color)
#pragma config(Sensor, port3,  colorValue,     sensorEV3_Color, modeEV3Color_Color)
#pragma config(Sensor, port4,  ultra,          sensorEV3_Ultrasonic)


task main()
{
int degree;
int distance;
int distance_deep;
float angle = 90.0;
float radius = 2.8;
float axis = 12.0;
distance=SensorValue(ultra);

motor[motorB] = 50;
motor[motorC] = 50;

while (SensorValue(colorValue)==2) {
playSound(soundBeepBeep);
setLEDColor(ledGreen);
wait1Msec(2000);
}


int i = 0;
wait1Msec(1000);
while ( i < 2 ) {
    motor[motorB] = 20;
    motor[motorC] = 20;
      while( SensorValue(colorValue) == 4) {}
      for (int j = 0; j < i; j++) {
        motor[motorB] = 70;
        motor[motorC] = 70;
      }
      i++;
   }


motor[motorB] = 50;
motor[motorC] = 50;
wait1Msec(2000);

distance_deep=SensorValue(ultra);

while(SensorValue(ultra)>distance){
   motor[motorB] = 20;
    motor[motorC] = 20;
	}
motor[motorB] = 0;
motor[motorC] = 0;

degree=(int)distance_deep/(2*3.14*radius);
resetMotorEncoder( motorB );
resetMotorEncoder( motorC );
setMotorTarget( motorB, -degree, 10);
setMotorTarget( motorC, -degree, 10);

while(getMotorRunning( motorB )){
degree=(int)axis/(radius*angle);
	}

resetMotorEncoder( motorB );
resetMotorEncoder( motorC );
setMotorTarget( motorB, degree, 10);

while(getMotorRunning( motorB )){
	setMotorTarget( motorC, -degree, 10);
	}

motor[motorB] = 0;
motor[motorC] = 90;
wait1Msec(1000);

motor[motorB] = 70;
motor[motorC] = 70;
wait1Msec(1000);

motor[motorB] = 0;
motor[motorC] = 90;
wait1Msec(1000);

motor[motorB] = 50;
motor[motorC] = 50;

int h = 0;
wait1Msec(1000);
while ( h < 2 ) {
    motor[motorB] = 50;
    motor[motorC] = 50;
      while( SensorValue(colorValue) == 4) {}
      for (int k = 0; k < h; k++) {
        motor[motorB] = 80;
        motor[motorC] = 80;
      }
      h++;

motor[motorB] = 50;
motor[motorC] = 50;

while(1){

 if(SensorValue(reflectedValue)>45){
  motor[motorB] = 0;
  motor[motorC] = 30;}


 else{
  motor[motorB] = 0;
  motor[motorC] = 30;}
}



while (SensorValue(colorValue)==2) {
playSound(soundBeepBeep);
setLEDColor(ledGreen);
wait1Msec(2000);
motor[motorB] = 0;
motor[motorC] = 30;
}


}
}
