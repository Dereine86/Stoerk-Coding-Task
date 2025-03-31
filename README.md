# Stoerk-Coding-Task


This is the solution of the Coding Task for my Application as Embedded Software Developer at Stoerk Tronic.

The interface definition of the PacketBuffer interface and it's implementation can be found in inc/PacketBuffer.hpp.  
I've decided to use a circular buffer directly from the ETL because it gives me all the funcionality that's required and I don't need to implement by myself.  
I had some struggles getting the ETL to run. Luckily I found the solution here: https://github.com/ETLCPP/etl/issues/231  
The Buffer Size is configurable via a template value.  
I also added some Unit-Tests to test the basic functionality.  

## Preconditions
1. It is expected that GTest Library is available on the system
2. Software is supposed to be run on Linux

## How to build
Use the following command to build the Software:
`g++ -g main.cpp -o main.out -I inc -D __STDC_LIMIT_MACROS -I include -l gtest -l gtest_main -pthread`

## What could still be done
In the next step one could use CMake for building the project. Due to time reasons, and because the project is very simple, I decided not to do so.

