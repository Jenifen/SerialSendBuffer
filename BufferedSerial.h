/*
 * This file is part of SerialSendBuffer
 * BufferedSerial.h - BufferedSerial library forBuffering Data and Sending it via UART/Serial
 * 
 * This program is free software: you can redistribute it and/or modify, 
 * is distributed in the hope that it will be useful :)
 * 
 * Copyright (c) 2020 Jenifen Seifeddin.  All right reserved.
 */

// ensure this library description is only included once
#ifndef BufferedSerial_h
#define BufferedSerial_h

// include types & constants of Wiring core API
#include "Arduino.h"
#include<TimerOne.h>

#define MIN_SENDING_RATE 10000 // 10ms

// library interface description
class BufferedSerial
{
  // user-accessible "public" interface
  public:

    BufferedSerial() = default;
    ~BufferedSerial();
    
    void begin(const unsigned int& baudrate) const;
    void sendingRate(const unsigned long& microseconds=MIN_SENDING_RATE) const ;
    /*
    * @brief method for set buffer size 
    * @param size 
    */ 
    void setSizeBuffer(const byte& elements, const byte& size) ;

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
          
      if (size_ == sizeof(int))//4
      { 
        for (byte i=0, j=2, k=4; i <= 1, j<=3, k<=5; i++, j++, k++)
        {
          buffer_[i] = byteData1[i];
          buffer_[j] = byteData2[i];
          buffer_[k] = (data3 == NULL) ? 0 : byteData3[i] ;
        }
      }
      else if (size_ == sizeof(double))//8) // double 
      {
        for (byte i=0, j=4, k=8; i <= 3, j<=7, k<=11; i++, j++, k++)
        {
          buffer_[i] = byteData1[i];
          buffer_[j] = byteData2[i];
          buffer_[k] = (data3 == NULL) ? 0 : byteData3[i] ;
        }
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
    *@brief sending buffer method 
    *
    */ 
    inline void sendPacket() const 
    {
      Serial.write(buffer_, elements_ * 2); 
    }
    /*
    * 
    */
    TimerOne* timer;
 
    
  // library-accessible "private" interface
  private:
    
  
    byte size_ ;
    byte* buffer_{ new byte[12]{0} };
    byte elements_ ;

    
};
#endif
