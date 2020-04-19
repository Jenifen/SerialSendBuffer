/*
  BufferedSerial.h - BufferedSerial library forBuffering Data and Sending it via UART/Serial 
  Copyright (c) 2020 Jenifen.  All right reserved.
*/

// ensure this library description is only included once
#ifndef BufferedSerial_h
#define BufferedSerial_h

// include types & constants of Wiring core API
#include "Arduino.h"
#include<TimerOne.h>
//#include <StandardCplusplus.h>

//#include <vector>

#define MIN_SENDING_RATE 100000 // 100ms

// library interface description
class BufferedSerial
{
  // user-accessible "public" interface
  public:

    BufferedSerial();
    inline void begin(const unsigned int& baudrate){  Serial.begin(baudrate); }
    void sendingRate(  unsigned long microseconds=1000000);
    
    inline void sizeElementBuffer(byte size) { size_ = size; }

    // One function works for all data types.  This would work 
    // even for user defined types if operator '>' is overloaded 
    template <typename T> T update(T* data1, T* data2, T* data3) 
    { 
      
      byte* byteData1 = (byte*)(data1);
      byte* byteData2 = (byte*)(data2);
      byte* byteData3 = (byte*)(data3);
        
      if (size_ == 4)
      {
        byte buf[6] = {byteData1[0], byteData1[1],
                    byteData2[0], byteData2[1],
                    byteData3[0], byteData3[1]};
      
        BufferedSerial::sendPacket(buf, sizeof(buf));
      }
      else if (size_ == 8) // double 
      {

        byte buf[12] = {byteData1[0], byteData1[1], byteData1[2], byteData1[3],
                      byteData2[0], byteData2[1], byteData2[2], byteData2[3],
                      byteData3[0], byteData3[1], byteData3[2], byteData3[3]};
  
        BufferedSerial::sendPacket(buf, sizeof(buf));
      } 

   
    }
  
  

  // library-accessible "private" interface
  private:
    inline void sendPacket(byte buf[], byte size) 
      {
        Serial.write(buf, size); 
      }
  
    byte size_ ;
    TimerOne* timer;

};

#endif
