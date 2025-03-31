/*
 * Solution for Coding Task for Stoerk-Tronic application
 * Johannes Scherle, johannes.scherle@gmail.com
 */
#ifndef PACKETBUFFER_HPP
#define PACKETBUFFER_HPP

#include "Receiver.hpp"
#include "etl/circular_buffer.h" // We include circular buffer from ETL as requested

// As requested a very lean interface definition for the PacketBuffer interface
class IPacketBuffer
{

public:
  virtual char
  append(const Packet packetToAppend) = 0;           // Virtual append method
  virtual char extract(Packet &extractedPacket) = 0; // Virtual extract method
  virtual ~IPacketBuffer() = default;                // Virtual destructor
};

// We use this template for the buffer size.
template <uint16_t bufferSize>

// Implementation of the PacketBuffer-Class
class PacketBuffer : public IPacketBuffer
{

public:

  // This method appends a new Packet to the buffer.
  char append(const Packet packetToAppend) override
  {
    char returnValue;
    if (!buffer.full())
    {
      buffer.push(packetToAppend);
      returnValue = 0;
    }
    else
    {
      returnValue = -1;
    }
    return returnValue;
  }

  char extract(Packet &extractedPacket) override
  {
    char returnValue;
    if (!buffer.empty())
    {
      extractedPacket = buffer.front();
      buffer.pop();
      returnValue = 0;
    }
    else
    {
      returnValue = -1;
    }
    return returnValue;
  }

private:
  // We use the circular buffer, because it directly matches our use case. No need to implement it on our own.
  etl::circular_buffer<Packet, bufferSize> buffer;
};
#endif // PACKETBUFFER_HPP