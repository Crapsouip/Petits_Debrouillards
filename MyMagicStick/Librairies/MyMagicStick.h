/*	MyMagicStick v_1.0
	Fichier de Header Systeme Global
	@author Daman Maximilien
*/

#ifndef MyMagicStick_h
#define MyMagicStick_h

//Inclusion des librairies
	#include "Arduino.h"
	#include <string.h>
	#include <SoftwareSerial.h>
	#include "MyMagicStick.h"
	
	#include "DHTSensor.h"
	#include "LuminositySensor.h"
	#include "TemperatureSensor.h"
	#include "MoistureSensor.h"
	
	#define BTBaudRate 38400
	#define DHTMaxFreq 2500
	
	template<class T> void myPrint(const T Data, SoftwareSerial& BlueTooth)
	{
		Serial.print(Data);
		if(BlueTooth.available() == 0) BlueTooth.print(Data);
		return;
	}
	
	template<class T> void myPrintln(const T Data, SoftwareSerial& BlueTooth)
	{
		Serial.println(Data);
		if(BlueTooth.available() == 0) BlueTooth.println(Data);
		return;
	}
	
	template<class T>	void myFlush(T& BlueTooth)
	{
		Serial.flush();
		if(BlueTooth.available() == 0) BlueTooth.flush();
		return;
	}
	
	class MyMagicStick
	{
		public:
			MyMagicStick();
			inline void attachBlueTooth(SoftwareSerial* BT)	{	BTModule = BT;	}
			void begin(uint8_t RX, uint8_t TX, uint8_t MoisturePin, uint8_t LumPin, uint8_t Temperature);
			void setupBTconnection(uint8_t RX, uint8_t TX);
			void beginLum(uint8_t RX, uint8_t TX, uint8_t Pin);
			void beginMoist(uint8_t RX, uint8_t TX, uint8_t Pin);
			void beginTemp(uint8_t RX, uint8_t TX, uint8_t Pin);
		public:
			void getTemperature();
			void getTemperatureR();
			void getHumidity();
			void getLuminosity();
			void getLuminosityR();
			void getLuminosityB();
			void getMoisture();
		public:
			void checkMessage();
			void treatMessage();
			void takeMeasure();
			void mountMessage();
			void sendMessage();
		private:
			SoftwareSerial*		BTModule;
			DHTSensor 			Capteur_TH;
			TemperatureSensor	Capteur_T;
			LuminositySensor	Capteur_L;
			MoistureSensor		Capteur_M;
		private:
			String				ReceivedBuffer;
			String				SendingBuffer;
			bool				IsDHTHere;
			int					MessageLevel;
			unsigned long		DHTTimer[2];
	};
#endif