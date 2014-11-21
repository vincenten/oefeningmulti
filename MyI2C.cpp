#include "MyI2C.h"
#include <string.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>          //O_RDWR
#include <stdio.h>          //perror

namespace RemoteMemoryLib{
    
    ssize_t (* pi_i2c_write)(int, const void *, size_t) = write;
    ssize_t (* pi_i2c_read)(int, void *, size_t) = read;
    
    MyI2C::MyI2C(const char * device, int i2caddress):I2C(device, i2caddress)
    {
	strcpy(this->device,device);
	openBus();
	acquireBus(i2caddress);
    }

    int MyI2C::openBus(void)
    {
	this->handle = open(this->device, O_RDWR);
	return handle;
    }

    int MyI2C::acquireBus(int i2caddress)
    {
	return ioctl(this->handle,I2C_SLAVE,i2caddress);
    }

    int MyI2C::write(int address, char * data, int length)
    {
	return pi_i2c_write(this->handle,data,length);
    }

    int MyI2C::read(int address, char * data, int length)
    {
	return pi_i2c_read(this->handle,data,length);
    }
}
