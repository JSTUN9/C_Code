#include <SPI.h>
#include <libpng/png.h>

void setup() {
	// Initialize the SPI interface
	SPI.begin();
	SPI.setClockDivider(SPI_CLOCK_DIV16);
	SPI.setDataMode(SPI_MODE0);
	pinMode(chipSelect, OUTPUT);
}

// read PNG data from file




