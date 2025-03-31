# Stoerk-Coding-Task

This is the solution of the Coding Task for my Application as Embedded Software Developer at Stoerk Tronic.

The interface definition of the PacketBuffer interface and it's implementation can be found in inc/PacketBuffer.hpp.  
I've decided to use a circular buffer directly from the ETL because it gives me all the funcionality that's required and I don't need to implement by myself.  
I had some struggles getting the ETL to run. Luckily I found the solution here: https://github.com/ETLCPP/etl/issues/231  
The Buffer Size is configurable via a template value.  
I also added some Unit-Tests to test the basic functionality.  

## What could still be done
In the next step one could use CMake for building the project. Due to time reasons, and because the project is very simple, I decided not to do so.