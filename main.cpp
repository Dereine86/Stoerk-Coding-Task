#include "stdio.h"
#include "etl/platform.h"
#include <gtest/gtest.h>
#include "inc/PacketBuffer.hpp"
#include "etl/circular_buffer.h"
#include <iostream>
// #include "platform.h" // This took me like 30 mins to figure out, see https://github.com/ETLCPP/etl/issues/231

TEST(PacketBufferTest, Normal)
{
    /*
     * EXPECT-Case 1: "Normal use case"
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
    EXPECT_EQ(extractedPacket.data[0], 1);
    EXPECT_EQ(extractedPacket.data[1], 2);
    EXPECT_EQ(extractedPacket.data[2], 3);

    packetBuffer.extract(extractedPacket);
    EXPECT_EQ(extractedPacket.data[0], 4);
    EXPECT_EQ(extractedPacket.data[1], 5);
    EXPECT_EQ(extractedPacket.data[2], 6);

    packetBuffer.extract(extractedPacket);
    EXPECT_EQ(extractedPacket.data[0], 7);
    EXPECT_EQ(extractedPacket.data[1], 8);
    EXPECT_EQ(extractedPacket.data[2], 9);
}

TEST(PacketBufferTest, AddToFull)
{
    /*
     * EXPECT-Case 2: We try to add packets to a full buffer
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
    EXPECT_EQ(packetBuffer.append(packet1), 0);
    EXPECT_EQ(packetBuffer.append(packet2), 0);
    EXPECT_EQ(packetBuffer.append(packet3), -1); // This packet should not be appendable

    Packet extractedPacket;
    packetBuffer.extract(extractedPacket);
    EXPECT_EQ(extractedPacket.data[0], 1);
    EXPECT_EQ(extractedPacket.data[1], 2);
    EXPECT_EQ(extractedPacket.data[2], 3);

    packetBuffer.extract(extractedPacket);
    EXPECT_EQ(extractedPacket.data[0], 4);
    EXPECT_EQ(extractedPacket.data[1], 5);
    EXPECT_EQ(extractedPacket.data[2], 6);

    packetBuffer.extract(extractedPacket);
    EXPECT_EQ(extractedPacket.data[0], 4);
    EXPECT_EQ(extractedPacket.data[1], 5);
    EXPECT_EQ(extractedPacket.data[2], 6);
}

TEST(PacketBufferTest, ExtractFromEmpty)
{
    /*
     * EXPECT-Case 3: We try to extract packets from an empty buffer
     */
    PacketBuffer<2> packetBuffer;
    Packet extractedPacket;
    EXPECT_EQ(packetBuffer.extract(extractedPacket), -1);
}

int main(int argc, char **argv)
{
    // Init GTest
    ::testing::InitGoogleTest(&argc, argv);

    // Run the tests
    return RUN_ALL_TESTS();
}