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
#include<stdarg.h>

//#include <StandardCplusplus.h>

//#include <vector>

#define MIN_SENDING_RATE 100000 // 100ms

// library interface description
class BufferedSerial
{
  // user-accessible "public" interface
  public:

    BufferedSerial();
    ~BufferedSerial();
    
    void begin(const unsigned int& baudrate) const;
    void sendingRate(  unsigned long microseconds=1000000);
    
    void sizeElementBuffer(byte sizeElement, byte matchdata) ;

    /*
     @brief : One method works for all data types.  This would work 
              even for user defined types if operator '>' is overloaded 
      @param data 
    */
    template <typename T> void update(T* data1, T* data2, T* data3 = NULL ) 
    { 
      
      byte* byteData1 = (byte*)(data1);
      byte* byteData2 = (byte*)(data2);
      byte* byteData3 = (byte*)(data3);
      
      
      if (size_ == sizeof(int))//4)
      {
        
        for (byte i=0, j=2, k=4; i <= 1, j<=3, k<=5; i++, j++, k++)
        {
          buffer_[i] = byteData1[i];
          buffer_[j] = byteData2[i];
          if (data3 == NULL) buffer_[k] = 0; //buffer_[k] = 0;
          else buffer_[k] = byteData3[i];
        
        }
        BufferedSerial::sendPacket(buffer_, matchdata_ * 2); 
      }
      else if (size_ == sizeof(double))//8) // double 
      {

   
        for (byte i=0, j=4, k=8; i <= 3, j<=7, k<=11; i++, j++, k++)
        {
          buffer_[i] = byteData1[i];
          buffer_[j] = byteData2[i];
          if (data3 == NULL) buffer_[k] = 0 ;
          else  buffer_[k] = byteData3[i];

          
        }
  
        BufferedSerial::sendPacket(buffer_, matchdata_ * 2);

      }

    } 

    /*
    * @brief method to get buffer 
    * @return array 
    */ 
    inline byte* getBuffer() const {return buffer_; }; 

    /*
     * @brief method for  delete array to deallocate array
    */
    inline void clear() const { delete(buffer_); };


    /*
    *
    */
    TimerOne* timer;
 
    
  // library-accessible "private" interface
  private:
    /*
    *@brief sending buffer method 
    @param array, size
    */ 
    inline void sendPacket(const byte buf[], const byte size) const 
    {
      Serial.write(buf, size); 
    }
  
    byte size_ ;
    byte* buffer_{ new byte[12]{0} };
    byte matchdata_ ;

    
};
#endif
