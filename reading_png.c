#include <stdio.h>

int main(void) {
  // Open the PNG file
  FILE *fp = fopen("image.png", "rb");
  if (fp == NULL) {
    // Error opening the file
    return 1;
  }

  // Get the size of the file
  fseek(fp, 0, SEEK_END);
  long int size = ftell(fp);
  rewind(fp);

  // Allocate a buffer to store the file
  unsigned char *buffer = (unsigned char *)malloc(size);
  if (buffer == NULL) {
    // Error allocating memory
    fclose(fp);
    return 1;
  }

  // Read the file into the buffer
  size_t bytes_read = fread(buffer, 1, size, fp);
  if (bytes_read != size) {
    // Error reading the file
    free(buffer);
    fclose(fp);
    return 1;
  }

  // Close the file
  fclose(fp);

  // Use the buffer to process the PNG file

  // ...

  // Free the buffer when done
  free(buffer);

  return 0;
}
