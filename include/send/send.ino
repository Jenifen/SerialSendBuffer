#include"BufferedSerial.h"

BufferedSerial BuffSerial; 

void setup()
{
    BuffSerial.begin(38400);
    //BuffSerial.sendingRate(blinkLed);
}


void loop()
{
    double val = map(analogRead(0), 0, 1023, 0, 1000);
    BuffSerial.sizeElementBuffer(8); //sizeof (double)
    BuffSerial.update< double >(&val, &val, &val);
    //  foo<int>();


}
