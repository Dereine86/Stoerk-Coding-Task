#ifndef RECEIVER_HPP
#define RECEIVER_HPP
#include "cstdint"

constexpr unsigned maxPacketSize = 123u;

struct Packet {
    unsigned char data[maxPacketSize];  // packet data
    uint8_t size;               // size of data
};
#endif // RECEIVER_HPP