# Data buffer and combiner

This task is designed to be completed in under an hour. The focus is primarily on the coding approach and implementation. Provide only brief explanations where necessary.
If there is time left, feel free to expand in any direction of your choosing (documentation, testing, ...).
Please send us your result ahead of the second interview.

## General scenario

In a data transmission scenario the microcontroller is responsible for receiving, buffering, combining and transmitting data on different communication interfaces.

The data is provided by class `Receiver` as a `Packet` object to class `PacketBuffer` by calling the `append()` method, and removed from the buffer by class `Transmitter` by calling the `extract()` method.
`Receiver` calls `append()` upon receiving the data from the communication channel, `Transmitter` calls `extract()` whenever it is ready to transmit new data.

```c++
constexpr unsigned maxPacketSize = 123u;

struct Packet {
    uchar data[maxPacketSize];  // packet data
    unit8_t size;               // size of data
};
```

For the implementation on a small microcontroller without heap memory allocation the [Embedded Template Library (ETL)](https://www.etlcpp.com) shall be used. We assume a modern C++ compiler.

## Data buffer implementation

First we consider the scenario where data is transmitted as it was received and only needs to be buffered.

1. Design an interface for class `PacketBuffer` and provide its code. Explain your design choices.
2. Implement the designed interface utilizing a suitable container class from the ETL. List the reasons for selecting this particular class.
