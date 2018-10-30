#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
  struct stat buffer;
  stat("README.md", &buffer);
  printf("File size: %ld\n", buffer.st_size);
  printf("mode: %d\n", buffer.st_mode);
  printf("Tiem of Last access: %s\n", ctime(buffer.st_atime));
}
