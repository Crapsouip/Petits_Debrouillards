/*	MyMagicStick v_1.0
	Fichier de Header capteur Hydratation
	@author Daman Maximilien
*/

#ifndef MoistureSensor_h
#define MoistureSensor_h

//Inclusion des librairies
	#include "Arduino.h"
	#include "MyMagicStick.h"

	class MoistureSensor
	{
		public:
			MoistureSensor();
			void begin(uint8_t ConnectPin);
			uint8_t errorlevel();
			inline	void	setError(uint8_t err)	{	ErrorLevel = err;	}
		public:
			inline void 	readVal()	{	Val = int(map(analogRead(Pin), 0, 1023, 0 ,100));	}
			inline uint8_t	getVal()	{	return Val;	}
		private:
			uint8_t Pin;
			uint8_t ErrorLevel;
			uint8_t Val;
	};
#endif