#include"BufferedSerial.h"

#define RATE_SENDING 10000 // 10ms
#define BAUD_RATE 38400
#define TYPE_DATA int 

BufferedSerial* BuffSerial; 

void setup()
{
    BuffSerial->begin(BAUD_RATE);

    // call send function every RATE_SENDING
    BuffSerial->sendingRate(RATE_SENDING);
    BuffSerial->timer->attachInterrupt(send);

    // setsizeof (number data 2, 3, type to send)
    BuffSerial->setSizeBuffer( 2, sizeof(TYPE_DATA)); //
}

inline void send(void)
{
  BuffSerial->sendPacket();
}

void loop()
{
    TYPE_DATA potValue1 =  analogRead(A0); 
    TYPE_DATA potValue2 =  -analogRead(A0) ; 
    
    BuffSerial->update <TYPE_DATA> (&potValue1, &potValue2); // 2 data of type int 

}
