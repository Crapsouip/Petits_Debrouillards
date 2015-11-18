/*	MyMagicStick v_1.0
	Fichier de Header capteur Temperature
	@author Daman Maximilien
*/

#ifndef TemperatureSensor_h
#define TemperatureSensor_h

//Inclusion des librairies
	#include "Arduino.h"
	#include <math.h>
	#include "MyMagicStick.h"
	
	#define THERMISTOR_VAL 3975

	class TemperatureSensor
	{
		public:
			TemperatureSensor();
			void 	begin(uint8_t ConnectPin);
			uint8_t errorlevel();
			inline	void	setError(uint8_t Error)	{	ErrorLevel = Error;	}
		public:
			void 	readData();
			inline 	float	getTemperature()	{	return Temperature;	}
			inline 	float 	getResistance()	{	return Resistance;	}
		private:
			uint8_t	Pin;
			uint8_t ErrorLevel;
			float	Temperature;
			float	Resistance;
	};
#endif