/*	MyMagicStick v_1.0
	Exemple Arduino -> Luminosite
	@author Daman Maximilien
*/

//Variables generale
	int LumPin = A0;
	int LumValue = 0;
//Variables de temporisation:
	long			Interval = 1500;
	unsigned long	Previous = 0;
	unsigned long	Current;
	long Interval2 = 500;
	unsigned long	Previous2 = 0;
	unsigned long	Current2;

void setup()
{
	//Initialisation de la communication:
	Serial.begin(9600);
	//Selection du sens de communcation capteur:
	pinMode(LumPin, INPUT);
}

void loop()
{
//Temporisation:
	Current = millis();
	Current2 = millis();
	if(Current - Previous > Interval)
	{
	//Mise a jour Temporisation:
		Previous = Current;
	//Mesure
		LumValue = analogRead(LumPin);
		LumValue = map(LumValue, 0, 1023, 0, 100);
	//Ecriture:
		PersonnalMessage();
	}
	else if(Current2 - Previous2 > Interval2)
	{
	//Mise a jour Temporisation:
		Previous2 = Current2;
	//Ecriture:
		Serial.print(".");
	}
}

void PersonnalMessage()
{
	Serial.print("\nLuminosity is @ ");
	Serial.print(LumValue);
	Serial.print("%\n");
}