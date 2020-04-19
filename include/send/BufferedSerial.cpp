/*
  BufferedSerial.h - BufferedSerial library forBuffering Data and Sending it via UART/Serial 
  Copyright (c) 2020 Jenifen.  All right reserved.
*/

// include types & constants of Wiring core API
#include "BufferedSerial.h"

BufferedSerial::BufferedSerial()
{
    //constructor empty
}

void BufferedSerial::sendingRate( unsigned long microseconds=1000000)
{

  microseconds = (microseconds < MIN_SENDING_RATE) ? MIN_SENDING_RATE : microseconds;
  //timer->initialize(microseconds);
  //timer->attachInterrupt(isr);

}
