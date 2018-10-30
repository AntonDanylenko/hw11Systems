#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
  struct stat buffer;
  stat("README.md", &buffer);
  printf("File size: %ld\n", buffer.st_size);
}
