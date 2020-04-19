#include"BufferedSerial.h"

BufferedSerial* BuffSerial; 

void setup()
{
    BuffSerial->begin(38400);
    //BuffSerial.sendingRate(blinkLed);
}


void loop()
{
    int val = map(analogRead(0), 0, 1023, 0, 1000);
    BuffSerial->sizeElementBuffer(sizeof(val), 3); //sizeof (type)
    int v = 12;
    BuffSerial->update<int> (&val, &val, &v);

}
