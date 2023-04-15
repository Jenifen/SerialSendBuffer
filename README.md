# SerialSendBuffer
The SerialSendBuffer Arduino library is a software library that provides a buffering mechanism for data and sending it via serial communication. The library allows Arduino programs to store data in a buffer and send it to a connected device over a serial communication channel.

## Info
```
This is an example C++ library for Arduino , created by 
[Jenifen Seifeddin]

Date creation : 20.April.2020

Installation
-------------------------------------------------------------------------

To install this library, just place this entire folder as a subfolder in your
Arduino/lib/targets/libraries folder.

When installed, this library should look like:

Arduino/lib/targets/libraries/SerialSendBuffer              (this library's folder)
Arduino/lib/targets/libraries/SerialSendBuffer/BufferedSerial.cpp     (the library implementation file)
Arduino/lib/targets/libraries/SerialSendBuffer/BufferedSerial.h       (the library description file)
Arduino/lib/targets/libraries/SerialSendBuffer/keywords.txt (the syntax coloring file)
Arduino/lib/targets/libraries/SerialSendBuffer/examples     (the examples in the "open" menu)
Arduino/lib/targets/libraries/SerialSendBuffer/readme.txt   (this file)

Building
-------------------------------------------------------------------------
After this library is installed, you just have to start the Arduino application.
You may see a few warning messages as it's built.

To use this library in a sketch, go to the Sketch | Import Library menu and
select SerialSendBuffer.  This will add a corresponding line to the top of your sketch:
#include <SerialSendBuffer.h>

To stop using this library, delete that line from your sketch.

Geeky information:
After a successful build of this library, a new file named "SerialSendBuffer.o" will appear
in "Arduino/lib/targets/libraries/SerialSendBuffer". This file is the built/compiled library
code.

If you choose to modify the code for this library (i.e. "SerialSendBuffer.cpp" or "SerialSendBuffer.h"),
then you must first 'unbuild' this library by deleting the "SerialSendBuffer.o" file. The
new "SerialSendBuffer.o" with your code will appear after the next press of "verify"

```
## Requirement
Add library timerOne [https://github.com/PaulStoffregen/TimerOne]
```
This library is a collection of routines for configuring the 16 bit hardware timer called Timer1 on the ATmega168/328. 
There are 3 hardware timers available on the chip, and they can be configured in a variety of ways to achieve different functionality. 
The development of this library began with the need for a way to quickly and easily set the PWM period or frequency, but has grown to include timer overflow interrupt handling and other features. 
It could easily be expanded upon or ported to work with the other timers.
```
# Example

```bash
#include<BufferedSerial.h>

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
```
