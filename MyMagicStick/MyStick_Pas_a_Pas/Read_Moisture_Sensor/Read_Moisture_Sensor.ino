/*	MyMagicStick v_1.0
	Exemples d'utilisation du materiel
		Capteur d'Hydrometrie
	@author Daman Maximilien
*/

#include <MyMagicStick.h>
#include <SoftwareSerial.h>
#define RxD	0
#define TxD	1

SoftwareSerial	BTModule(RxD,TxD);
MyMagicStick	MyStick;
int MoisturePin = A0;

void setup()
{
	Serial.begin(9600);
	MyStick.attachBlueTooth(&BTModule);
	MyStick.beginMoist(RxD, TxD, MoisturePin);
}

void loop()
{
	MyStick.getMoisture();
	delay(5000);
}
