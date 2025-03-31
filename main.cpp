#include "stdio.h"
#define ETL_NO_STL
#include "etl/platform.h"
#include "inc/PacketBuffer.hpp"
#include "etl/circular_buffer.h"
#include "inc/Receiver.hpp"
//#include "platform.h" // This took me like 30 mins to figure out, see https://github.com/ETLCPP/etl/issues/231
//#include "PacketBuffer.hpp"

int main ()
{
    Packet packet1 ;
    packet1.data[0] = 1;
    packet1.data[1] = 2;
    packet1.data[2] = 3;
    packet1.size = 3;
    Packet packet2 ;
    packet2.data[0] = 4;
    packet2.data[1] = 5;
    packet2.data[2] = 6;
    packet2.size = 3;
    Packet packet3 ;
    packet3.data[0] = 7;
    packet3.data[1] = 8;
    packet3.data[2] = 9;
    packet3.size = 3;


    PacketBuffer packetBuffer;
    packetBuffer.append(packet1);
    packetBuffer.append(packet2);
    packetBuffer.append(packet3);

    Packet extractedPacket;
    packetBuffer.extract(extractedPacket);
    printf("Extracted Packet: %d %d %d\n", extractedPacket.data[0], extractedPacket.data[1], extractedPacket.data[2]);
    packetBuffer.extract(extractedPacket);
    printf("Extracted Packet: %d %d %d\n", extractedPacket.data[0], extractedPacket.data[1], extractedPacket.data[2]);
    packetBuffer.extract(extractedPacket);
    printf("Extracted Packet: %d %d %d\n", extractedPacket.data[0], extractedPacket.data[1], extractedPacket.data[2]);
    

}