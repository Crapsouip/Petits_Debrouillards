/*	MyMagicStick v_1.0
	Exemples d'utilisation du materiel
		Capteur de Luminosite
	@author Daman Maximilien
*/

#include <MyMagicStick.h>
#include <SoftwareSerial.h>
#define RxD	0
#define TxD	1

SoftwareSerial	BTModule(RxD,TxD);
MyMagicStick	MyStick;
int LumPin = A1;

void setup()
{
	Serial.begin(9600);
	MyStick.attachBlueTooth(&BTModule);
	MyStick.beginLum(RxD, TxD, LumPin);
}

void loop()
{
	MyStick.getLuminosity();
	MyStick.getLuminosityR();
	MyStick.getLuminosityB();
	delay(5000);
}
