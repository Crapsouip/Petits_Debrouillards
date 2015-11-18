#include <CapacitiveSensor.h>
#define NbTouches   10

CapacitiveSensor    Touches[NbTouches] = {    CapacitiveSensor(2,3),
                                              CapacitiveSensor(2,4),
                                              CapacitiveSensor(2,6),
                                              CapacitiveSensor(2,9),
                                              CapacitiveSensor(2,10), 
                                              CapacitiveSensor(2,8),
                                              CapacitiveSensor(2,9),
                                              CapacitiveSensor(2,10),
                                              CapacitiveSensor(2,11),
                                              CapacitiveSensor(2,12)
                                          };
										  
int		    Note[] = {523, 587, 659, 784, 880, 880, 784, 659, 587, 523};
bool		Connected[NbTouches];
int		    Speaker = 13;

void setup()
{
	Touches[0].set_CS_AutocaL_Millis(0xFFFFFFFF);
	for(uint8_t i = 0; i < NbTouches; i++)	{	Connected[i] = false;	}
}

void loop()
{
	for(uint8_t i = 0; i < NbTouches; i++)
	{
  		Connected[i] = (Touches[i].capacitiveSensor(25) > 25);
		if(Connected[i])  tone(Speaker, Note[i], 50);
	}
}
