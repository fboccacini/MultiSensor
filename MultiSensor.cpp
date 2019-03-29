//////////////////////////////////////////////////////////////////////////////////////////
/*																																											*/
/* Interaction channels setup	and management																						*/
/*																																											*/
//////////////////////////////////////////////////////////////////////////////////////////

void Sensor::addPrintChannel(PrintChannel* printChannel)
{
  //this->printChannels++ = printChannel;
}

void Sensor::removePrintChannel(short int index)
{

}

void Sensor::addControlChannel(ControlChannel* controlChannel)
{
  //this->controlChannels++ = controlChannel;
}

void Sensor::removeControlChannel(short int index)
{

}

/* printAll: prints a message on all print channels */
void Sensor::printAll(const char* message)
{
  for(short int i = 0; i < sizeof(this->printChannels); i++)
  {
    this->printChannels[i]->print(message);
  }
}

/* readCharAnyControl: reads on all control channels and returns the input 							*/
/* of the first one to respond.																													*/
char readCharAnyControl()
{

}

/* readSentenceAnyControl: reads on all control channels and returns the 							  */
/* input sentence (read chars until a accept char is given) of the first one to respond.*/
char* readSentenceAnyControl()
{

}
