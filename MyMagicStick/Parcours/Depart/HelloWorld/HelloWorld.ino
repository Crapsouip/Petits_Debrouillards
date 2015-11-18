/*	MyMagicStick v_1.0
	Exemple Arduino -> Hello World!
	@author Daman Maximilien
*/

void setup()
{
	//Initialisation de la communication:
	Serial.begin(9600);
}

void loop()
{
	//Ecriture:
	Serial.println("Hello World...");
	delay(0);
}
