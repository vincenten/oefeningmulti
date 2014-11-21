
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef I2C_HEADER
#define I2C_HEADER

namespace RemoteMemoryLib{

    class I2C{
        public:
            I2C(const char * device, int i2caddress);
			int write(int address, char * data, int length);
			int read(int address, char * data, int length);

        private:
            int openBus(void);
            int acquireBus(int i2caddress);
            char device[128];
            int handle;
    };
}

#endif