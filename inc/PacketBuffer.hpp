#ifndef PACKETBUFFER_HPP
#define PACKETBUFFER_HPP

#include "Receiver.hpp"
#include "etl/circular_buffer.h"

// Interface-Definition
class IPacketBuffer
{

public:
  virtual char
  append(const Packet packetToAppend) = 0;           // Rein virtuelle methode
  virtual char extract(Packet &extractedPacket) = 0; // Rein virtuelle methode
  virtual ~IPacketBuffer() = default;                // Virtueller Destruktor
};

//template <uint16_t bufferSize>

// Implementierung des Interfaces in einer Klasse
class PacketBuffer : public IPacketBuffer
{

public:
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
  etl::circular_buffer<Packet, 10> buffer;
};
#endif // PACKETBUFFER_HPP