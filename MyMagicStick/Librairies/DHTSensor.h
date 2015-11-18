/*	MyMagicStick v_1.0
	Fichier de Header capteur DHT
	@author Daman Maximilien
*/

#ifndef DHTSensor_h
#define DHTSensor_h

	#include "Arduino.h"
	#include "MyMagicStick.h"

	class DHTSensor
	{
		public:
			DHTSensor();
			void	begin(uint8_t ConnectPin);
			void 	TypeDetection();
			uint8_t	errorlevel();
			inline	void	setError(uint8_t Error)	{	ErrorLevel = Error;	}
		public:
			void	readSensor();
			inline	uint8_t		getType()			{	return SensorType;	}
			inline	int16_t		getTemperature()	{	return Temp;	}
			inline	int8_t		getHumidity()		{	return Hum;	}
		private:
			uint8_t		Pin;
			uint8_t		SensorType;
			uint8_t		ErrorLevel;
			int16_t		Temp;
			int8_t		Hum;
	};
#endif