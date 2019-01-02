

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> 			// open
#include <inttypes.h>		 // uint8_t, etc
#include <linux/i2c-dev.h> // I2C bus definitions
#include <sys/ioctl.h>


int main() {
	
  int ADS_address = 0x40;	// base address of our device on the I2C bus
  int I2CFile;
  	
  uint8_t buffer[2];		// 2 byte buffer to store the data read from the I2C device

  int16_t val;				// Stores the 16 bit value of our ADC conversion
  
  I2CFile = open("/dev/i2c-1", O_RDWR);		// Open the I2C device
  
  ioctl(I2CFile, I2C_SLAVE, ADS_address);   // Specify the address of the I2C Slave to communicate with

  buffer[0] = 0x06;  //reset 
  write(I2CFile, buffer, 1);	


  buffer[0] = 0x40;
  buffer[1] = 0x06;				//continuos conversion, 90SPS
//  buffer[1] = 0x00;				//csingle shot conversion, 20SPS 
  write(I2CFile, buffer, 2);	// this set config register
  
  
  
  buffer[0] = 0x20;  //read config only for debug
  write(I2CFile, buffer, 1);	  
  read(I2CFile, buffer, 1);	
  printf("config value %x \n", buffer[0]);
  

  
	buffer[0] = 0x08;
	write(I2CFile, buffer, 1);	  // start conversion

// tentative for single shot conversion mode
	buffer[0] = 0x21;  
	write(I2CFile, buffer, 1);	  // read status register
	
 
// Wait for the conversion to complete, this requires bit 7 to change from 0->1
//  while ((buffer[0] & 0x80) == 0)	// readBuf[0] contains 8 MSBs of config register, AND with 10000000 to select bit 7
//  {
//	  buffer[0] = 0x21;  	// not sure if need all the time
//	  write(I2CFile, buffer, 1);	  // read status register
//	  read(I2CFile, buffer, 1);	// Read the status register into readBuf
//	  printf("status %x \r", buffer[0]);
//  }

while (1)
  {
  buffer[0] = 0x10;
  write(I2CFile, buffer, 1);	// command to read value
  
  read(I2CFile, buffer, 2);		// Read the contents of the conversion register into readBuf

  val = buffer[0] << 8 | buffer[1];	// Combine the two bytes of readBuf into a single 16 bit result 
  
  printf("AD Reading %d \r", val);	// Print the result to terminal
}		
  close(I2CFile);
  
  return 0;

}
