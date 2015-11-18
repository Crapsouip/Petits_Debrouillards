/*	MyMagicStick v_1.0
	Exemple Arduino -> Système d'objets
	@author Daman Maximilien
*/

//Inclusion de biblothèque
#include "DHTSensorSA.h"
#include <SoftwareSerial.h>

//Variables generale
#define	DHTMaxFreq	2000
	
	DHTSensor	DHT;
	int 		DHTPin = 4;
	uint8_t		HumValue = 0;
	uint16_t	TempValue = 0;
	int 		LumPin = A0;
	int 		LumValue = 0;
//Variables de temporisation:
	long			Interval = 500;
	unsigned long	Previous[2] = {0, 0};
	unsigned long	Current[2];

void setup()
{
	//Initialisation de la communication:
	Serial.begin(9600);
	//Selection du sens de communcation capteur:
	DHT.begin(DHTPin);
	pinMode(LumPin, INPUT);
}

void loop()
{
//Temporisation:
	for(uint8_t i = 0; i < 2; i++) {	Current[i] = millis();	}
	if(Current[0] - Previous[0] > DHTMaxFreq)
	{
	//Mise a jour Temporisation:
		Previous[0] = Current[0];
	//Mesure
		LumValue = analogRead(LumPin);
		LumValue = map(LumValue, 0, 1023, 0, 100);
		DHT.readSensor();
		TempValue = DHT.getTemperature();
		HumValue = DHT.getHumidity();
	//Ecriture:
		PersonnalMessage();
	}
	else if(Current[1] - Previous[1] > Interval)
	{
		Previous[1] = Current[1];
		Serial.print(".");
	}
}

void PersonnalMessage()
{
	Serial.print("\nLuminosity is @ ");
	Serial.print(LumValue);
	Serial.print("%\n");
	Serial.print("\nTemperature is @ ");
	Serial.print(TempValue);
	Serial.print("°C\n");
	Serial.print("\nHumidity is @ ");
	Serial.print(HumValue);
	Serial.print("%\n");
}