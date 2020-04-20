#include"BufferedSerial.h"

BufferedSerial* BuffSerial; 
bool ledState = LOW; 
int potValue = 0;

void setup()
{
    pinMode(13, OUTPUT);
    BuffSerial->begin(38400);
    BuffSerial->sendingRate();
    BuffSerial->timer->attachInterrupt(blinkLED);

}

void blinkLED(void)
{
  
  ledState = !ledState;
  digitalWrite(13, ledState);
  BuffSerial->sizeElementBuffer(sizeof(potValue), 3); //sizeof (type)
  int v = 12;
  BuffSerial->update<int> (&potValue, &potValue, &v);
}

void loop()
{
    potValue = map(analogRead(0), 0, 1023, 0, 1000);
    

}
