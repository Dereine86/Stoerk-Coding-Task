constexpr unsigned maxPacketSize = 123u;

struct Packet {
    uchar data[maxPacketSize];  // packet data
    unit8_t size;               // size of data
};