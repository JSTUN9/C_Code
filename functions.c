// write to SD card

// remember to create file directory in setup
 SD.mkdir("dir/");

// Create the PNG encoder object
  Adafruit_TinyPNG pngEncoder;

  // Initialize the SPI interface
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV16);
  SPI.setDataMode(SPI_MODE0);
  pinMode(chipSelect, OUTPUT);

// take in file location
void SDWrite(char fileLocation[], int width, int height, uint8_t colorType){
	// open / create file
	char base[20] = "dir/";
	strcat(base, fileLocation);
	// adds str2 to str1 
	myFile = SD.open(base);


	// if file is open
	if (myFile) {
		Serial.print("Writing to file")
		// read from image buffer

	}
	else{
		Serial.println("Failed to open file")
	}

	// read image data from SPI

	 // Set the image dimensions and color type
  	//sint width = 100;
  	//int height = 100;
  	//uint8_t colorType = PNG_COLOR_TYPE_RGBA;

  	// Create an image buffer
  	uint8_t imageData[width * height * 4];

  	// Receive the image data over the SPI interface
  	digitalWrite(chipSelect, LOW);
  	for (int i = 0; i < width * height * 4; i++) {
    	imageData[i] = SPI.transfer(0);
  	}
  	digitalWrite(chipSelect, HIGH);


  	// encode data into PNG and store in SD Card
	if (!pngEncoder.encode(&myFile, imageData, width, height)){
		Serial.println("Failed to save PNG file")
		return;
	}
}

