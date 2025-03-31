#include "stdio.h"
// #define ETL_NO_STL
#include "etl/platform.h"
// #include <gtest/gtest.h> // Wanted to use GTest for Unit-Tests, but it gives me compiler errors, because initializer list is defined in both ETL, as well as GTest. Couldn't figure this out due to time budget.
#include "inc/PacketBuffer.hpp"
#include "etl/circular_buffer.h"
#include "inc/Receiver.hpp"
#include <iostream>
// #include "platform.h" // This took me like 30 mins to figure out, see https://github.com/ETLCPP/etl/issues/231

void testCase1()
{
    /*
     * Test-Case 1: "Normal use case"
     */
    Packet packet1;
    packet1.data[0] = 1;
    packet1.data[1] = 2;
    packet1.data[2] = 3;
    packet1.size = 3;
    Packet packet2;
    packet2.data[0] = 4;
    packet2.data[1] = 5;
    packet2.data[2] = 6;
    packet2.size = 3;
    Packet packet3;
    packet3.data[0] = 7;
    packet3.data[1] = 8;
    packet3.data[2] = 9;
    packet3.size = 3;

    PacketBuffer<3> packetBuffer;
    packetBuffer.append(packet1);
    packetBuffer.append(packet2);
    packetBuffer.append(packet3);

    Packet extractedPacket;
    packetBuffer.extract(extractedPacket);
    // printf("Extracted Packet: %d %d %d\n", extractedPacket.data[0], extractedPacket.data[1], extractedPacket.data[2]);
    assert(extractedPacket.data[0] == 1);
    assert(extractedPacket.data[1] == 2);
    assert(extractedPacket.data[2] == 3);

    packetBuffer.extract(extractedPacket);
    // printf("Extracted Packet: %d %d %d\n", extractedPacket.data[0], extractedPacket.data[1], extractedPacket.data[2]);
    assert(extractedPacket.data[0] == 4);
    assert(extractedPacket.data[1] == 5);
    assert(extractedPacket.data[2] == 6);

    packetBuffer.extract(extractedPacket);
    // printf("Extracted Packet: %d %d %d\n", extractedPacket.data[0], extractedPacket.data[1], extractedPacket.data[2]);
    assert(extractedPacket.data[0] == 7);
    assert(extractedPacket.data[1] == 8);
    assert(extractedPacket.data[2] == 9);

    // packetBuffer.extract(extractedPacket);
    // printf("Extracted Packet: %d %d %d\n", extractedPacket.data[0], extractedPacket.data[1], extractedPacket.data[2]);
    // packetBuffer.extract(extractedPacket);
    // printf("Extracted Packet: %d %d %d\n", extractedPacket.data[0], extractedPacket.data[1], extractedPacket.data[2]);
}

void testCase2()
{
    /*
     * Test-Case 2: We try to add packets to a full buffer
     */
    Packet packet1;
    packet1.data[0] = 1;
    packet1.data[1] = 2;
    packet1.data[2] = 3;
    packet1.size = 3;
    Packet packet2;
    packet2.data[0] = 4;
    packet2.data[1] = 5;
    packet2.data[2] = 6;
    packet2.size = 3;

    // This packet should not be appendable
    Packet packet3;
    packet3.data[0] = 7;
    packet3.data[1] = 8;
    packet3.data[2] = 9;
    packet3.size = 3;

    PacketBuffer<2> packetBuffer;
    assert(packetBuffer.append(packet1) == 0);
    assert(packetBuffer.append(packet2) == 0);
    assert(packetBuffer.append(packet3) == -1); // This packet should not be appendable

    Packet extractedPacket;
    packetBuffer.extract(extractedPacket);
    assert(extractedPacket.data[0] == 1);
    assert(extractedPacket.data[1] == 2);
    assert(extractedPacket.data[2] == 3);

    packetBuffer.extract(extractedPacket);
    assert(extractedPacket.data[0] == 4);
    assert(extractedPacket.data[1] == 5);
    assert(extractedPacket.data[2] == 6);

    packetBuffer.extract(extractedPacket);
    assert(extractedPacket.data[0] == 4);
    assert(extractedPacket.data[1] == 5);
    assert(extractedPacket.data[2] == 6);
}

void testCase3()
{
    /*
     * Test-Case 3: We try to extract packets from an empty buffer
     */
    PacketBuffer<2> packetBuffer;
    Packet extractedPacket;
    assert(packetBuffer.extract(extractedPacket) == -1);
}

int main()
{
    // As the etl library seemingly collides with GTest we do a very lean basic Unit-Testing here.

    /*
     * Test-Case 1: "Normal use case"
     */
    testCase1();
    std::cout << "Testcase 1 passed! :)" << std::endl;

    /*
     * Test-Case 2: We try to add packets to a full buffer
     */
    testCase2();
    std::cout << "Testcase 2 passed! :)" << std::endl;

    /*
     * Test-Case 3: We try to extract packets from an empty buffer
     */
    testCase3();
    std::cout << "Testcase 3 passed! :)" << std::endl;
}