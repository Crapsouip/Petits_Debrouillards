/*	MyMagicStick v_1.0
	Bibliotheque de fonction capteur Hydratation
	@author Daman Maximilien
*/

//Inclusion des librairies
	#include "Arduino.h"
	#include "MyMagicStick.h"

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////CONSTRUCTEURS///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////	
MoistureSensor::MoistureSensor()
{}

void MoistureSensor::begin(uint8_t ConnectPin)
{
	Pin = ConnectPin + 54;
	pinMode(Pin, INPUT);
	setError(0);
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////ERRORLEVEL///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
uint8_t MoistureSensor::errorlevel()
{	//A STABILISER//
/* //Initialisation:
	int NbTry = 2;
	int Temp[NbTry];
	int M[2*NbTry];
	int Test = 0;
//Test de fonctionnement:
	for(int i=0; i<NbTry; i++)
	{
		M[2*i] = analogRead(Pin);
		delay(1);
		M[2*i+1] = analogRead(Pin);
		delay(1);
		Temp[i] = (M[2*i]>M[2*i+1])?(M[2*i]-M[2*i+1]):(M[2*i+1]-M[2*i]);
		Temp[i] = (Temp[i]>2)?0:1;
	}
	for(int i=0; i<NbTry-1; i++)
	{
		Test += (Temp[2*i]==Temp[2*i+1]);
	}
 *///Niveau d erreur:
	ErrorLevel = 0;
	return ErrorLevel;
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////