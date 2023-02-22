#include <Adafruit_TinyPNG.h>
#include <SD.h>

#define SDCARD_CS_PIN 8

void setup() {
  // Initialize the SD card
  if (!SD.begin(SDCARD_CS_PIN)) {
    Serial.println("SD card initialization failed!");
    return;
  }

  // Open the image file
  File imageFile = SD.open("image.png", FILE_WRITE);
  if (!imageFile) {
    Serial.println("Failed to open image file!");
    return;
  }

  // Create the PNG encoder object
  Adafruit_TinyPNG pngEncoder;

  // Set the image dimensions and color type
  int width = 100;
  int height = 100;
  uint8_t colorType = PNG_COLOR_TYPE_RGBA;

  // Create an image buffer
  uint8_t imageData[width * height * 4];

  // Fill the image buffer with dummy data
  for (int i = 0; i < width * height * 4; i++) {
    imageData[i] = i;
  }

  // Encode the image buffer as a PNG image
  if (!pngEncoder.encode(&imageFile, imageData, width, height, colorType)) {
    Serial.println("Failed to encode the image as PNG!");
    return;
  }

  // Close the image file
  imageFile.close();

  Serial.println("Image saved successfully to the SD card!");
}

void loop() {
  // Empty loop
}
