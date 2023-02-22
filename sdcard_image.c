#include <nuttx/config.h>
#include <stdio.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image/stb_image_write.h"

int main(int argc, char *argv[])
{
  int width, height, channels;
  unsigned char *img = stbi_load("/mnt/sd0/test.jpg", &width, &height, &channels, 0);
  if(img == NULL) {
    printf("Error in loading the image\n");
    exit(1);
  }
  printf("Loaded image with a width of %dpx, a height of %dpx and %d channels\n", width, height, channels);

  stbi_write_jpg("/mnt/sd0/test2.jpg", width, height, channels, img, 100);

  stbi_image_free(img);

  return 0;
}