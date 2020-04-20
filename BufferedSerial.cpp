/*
 * This file is part of SerialSendBuffer
 * BufferedSerial.h - BufferedSerial library forBuffering Data and Sending it via UART/Serial
 * 
 * This program is free software: you can redistribute it and/or modify, 
 * is distributed in the hope that it will be useful :)
 * 
 * Copyright (c) 2020 Jenifen Seifeddin.  All right reserved.
 */

#include "BufferedSerial.h"

void BufferedSerial::sendingRate(const unsigned long& microseconds=MIN_SENDING_RATE) const 
{
  timer->initialize((microseconds < MIN_SENDING_RATE) ? MIN_SENDING_RATE : microseconds);
}

void BufferedSerial::setSizeBuffer(const byte& elements, const byte& size) 
{ 
  size_ = size;
  elements_ = elements;
}

void BufferedSerial::begin(const unsigned int& baudrate) const 
{  
  Serial.begin(baudrate); 
}

BufferedSerial::~BufferedSerial()
{
  BufferedSerial::clear();
}
