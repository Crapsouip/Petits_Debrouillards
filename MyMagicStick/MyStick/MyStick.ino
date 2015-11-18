/*	MyMagicStick v_1.0
	Programme Arduino
	@author Daman Maximilien
*/

#include <MyMagicStick.h>
#include <SoftwareSerial.h>
#define RxD	0
#define TxD	1

SoftwareSerial	BTModule(RxD,TxD);
MyMagicStick	MyStick;
int	MoistPin = A0;
int LumPin = A1;
int TempPin = 4;

void setup()
{
	Serial.begin(9600);
	MyStick.attachBlueTooth(&BTModule);
	MyStick.begin(RxD, TxD, MoistPin, LumPin, TempPin);
}

void loop()
{
	MyStick.checkMessage();
	MyStick.treatMessage();
	MyStick.takeMeasure();
	MyStick.mountMessage();
	MyStick.sendMessage();
}
