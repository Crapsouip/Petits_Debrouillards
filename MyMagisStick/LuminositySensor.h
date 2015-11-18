/*	MyMagicStick v_1.0
	Fichier de Header capteur Luminosite
	@author Daman Maximilien
*/

#ifndef LuminositySensor_h
#define LuminositySensor_h

//Inclusion des librairies
	#include "Arduino.h"
	#include "MyMagicStick.h"

	class LuminositySensor
	{
		public:
			LuminositySensor();
			void 	begin(uint8_t ConnectPin);
			uint8_t errorlevel();
			inline	void	setError(uint8_t Error)	{	ErrorLevel = Error;	}
		public:
			inline	void 	readData()			{	LVal = analogRead(Pin);	}
			inline 	void 	readRVal()			{	RVal = (1023-analogRead(Pin))*10/analogRead(Pin);	}
			inline 	void 	readBrightness()	{	BVal = int(map(analogRead(Pin), 0,1023,0,100));	}
		public:
			inline 	int		getVal()	{	return LVal;	}
			inline 	float 	getRVal()	{	return RVal;	}
			inline 	int 	getBVal()	{	return BVal;	}
		private:
			uint8_t	Pin;
			uint8_t ErrorLevel;
			int		LVal;
			float	RVal;
			int		BVal;	
	};
#endif