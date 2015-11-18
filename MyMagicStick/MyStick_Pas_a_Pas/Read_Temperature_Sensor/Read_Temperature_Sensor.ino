/*	MyMagicStick v_1.0
	Exemples d'utilisation du materiel
		Capteur de Temperature
	@author Daman Maximilien
*/

#include <MyMagicStick.h>
#include <SoftwareSerial.h>
#define RxD	0
#define TxD	1

SoftwareSerial	BTModule(RxD,TxD);
MyMagicStick	MyStick;
int TempPin = A2;

void setup()
{
	Serial.begin(9600);
	MyStick.attachBlueTooth(&BTModule);
	MyStick.beginTemp(RxD, TxD, TempPin);
}

void loop()
{
	MyStick.getTemperature();
	MyStick.getTemperatureR();
	delay(5000);
}
