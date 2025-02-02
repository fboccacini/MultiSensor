#ifndef MultiSensor_h
#define MultiSensor_h

#include "Arduino.h"
#include "Sensor.h"

typedef struct matrix_row{

	Sensor* sensor;
	float* values[];		//slope  intercept  dec   CP  |-calibration points-|

};

class MultiSensor
{
	public:
		MultiSensor();
		void mainMenu();

		//////////////////////////////////////////////////////////////////////////////////////////
		/*																																											*/
		/* Sensors setup	and management																						*/
		/*																																											*/
		//////////////////////////////////////////////////////////////////////////////////////////

		void connectSensor(Sensor* sensor);
		void connectSensorByPin(short int pin);

		//////////////////////////////////////////////////////////////////////////////////////////
		/*																																											*/
		/* Interaction channels setup	and management																						*/
		/*																																											*/
		//////////////////////////////////////////////////////////////////////////////////////////

		void addPrintChannel(PrintChannel printChannel);
		void removePrintChannel(short int index);
		void addControlChannel(ControlChannel controlChannel);
		void removeControlChannel(short int index);

		/* printAll: prints a message on all print channels */
		void printAll();

		/* readCharAnyControl: reads on all control channels and returns the input 							*/
		/* of the first one to respond.																													*/
		char readCharAnyControl();

		/* readSentenceAnyControl: reads on all control channels and returns the 							  */
		/* input sentence (read chars until a accept char is given) of the first one to respond.*/
		char readSentenceAnyControl();
		//////////////////////////////////////////////////////////////////////////////////////////
		/*																																											*/
		/* Interaction channels setup	and management																						*/
		/*																																											*/
		//////////////////////////////////////////////////////////////////////////////////////////

		void addPrintChannel(PrintChannel* printChannel);
		void removePrintChannel(short int index);
		void addControlChannel(ControlChannel* controlChannel);
		void removeControlChannel(short int index);

		/* printReading: prints formatted reading on specified printChannels. Null forall channels. */
		void printReading(PrintChannel* channels);

		/* printAll: prints a message on all print channels */
		void printAll(const char* messsage);

		/* readCharAnyControl: reads on all control channels and returns the input 							*/
		/* of the first one to respond.																													*/
		char readCharAnyControl();

		/* readSingleIntAnyControl: like readCharAnyControl but it returns an integer						*/
		short int readSingleIntAnyControl();

		/* readSentenceAnyControl: reads on all control channels and returns the 							  */
		/* input sentence (read chars until a accept char is given) of the first one to respond.*/
		char* readSentenceAnyControl();

		/* readIntAnyControl: like readSentenceAnyControl, but it converts the output to an integer */
    int readIntAnyControl();

		/* readFloatAnyControl: same again, but it converts to float. 													*/
		/* The dot button marks the decimal point 																							*/
    float readFloatAnyControl();
	private:
		PrintChannel** printChannels;
		ControlChannel** controlChannels;
		matrix_row* sensorsMatrix;
		void printAll(char* message,char* channels[]);
};


#endif
