//sensor setup-col_reflect
#pragma config(Sensor, S3, reflectedValue, sensorEV3_Color,modeEV3Color_Color)
//*!!Code automatically generated by 'ROBOTC' configuration wizard !!*//

task main()
{
	motor[motorB] = 30;
	motor[motorC] = 30;

	while (SensorValue(reflectedValue) ==5) {

		motor[motorB] = 30;
		motor[motorC] = 30;
		wait1Msec(1000);
	}

	

	while (SensorValue(reflectedValue) ==2) {

	motor[motorB] = 30;
	motor[motorC] = 0;
	wait1Msec(1000);
		
	}

	while (SensorValue(reflectedValue) == 4) {

		motor[motorB] = 30;
		motor[motorC] = 0;
		wait1Msec(1000);

	}

	while (SensorValue(reflectedValue) == 3) {

		motor[motorB] = -30;
		motor[motorC] = -30;
		wait1Msec(1000);

	}
	motor[motorB] = 0;
	motor[motorC] = 0;


}
