# IPBC - INTERPLANETARY BROADCAST COIN

Here lies all the code for the core.
Based on [Karbowanec](https://github.com/seredat/karbowanec), which is based on [Cryptonote](https://github.com/cryptonotefoundation/cryptonote).

## Build Instructions
These are kept very simple. Do not consider this an exhaustive guide.

#### Required:
* CMake 2.8.6 or higher
* Boost 1.55 or higher (system filesystem thread date_time chrono regex serialization program_options)
* Git (For proper versioning)

#### Windows:
* Clone this repository
* Create a new directory to build in (i.e. "win_build")
* Inside "win_build" run: 'cmake -G "Visual Studio 15 2027 Win64" ..' (Change version and platform as needed)
* If everything went successfully, you should have "IPBC.sln" in "win_build", which you can open with Visual Studio to compile the solution
* Once compiled, binaries should be in "win_build/src/Release" or "win_build/src/Debug"

Note: If cmake can't find boost, try downloading it from [here](https://dl.bintray.com/boostorg/release/1.66.0/source/boost_1_66_0.zip) and extracting it to "C:\Program Files\boost\boost_1_66_0"

#### Linux/Mac:
* Clone this repository
* Create a new directory to build in (i.e. "build")
* Inside "build", run these commands: 'cmake ..', 'make'
* Compiled binaries should now be found in "build/src", enjoy
