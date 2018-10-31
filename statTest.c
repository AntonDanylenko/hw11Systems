#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

int main(){
  struct stat buffer;
  stat("test.file", &buffer);
  int size = buffer.st_size;
  printf("File size: %d\n", size);
  printf("mode: %d\n", buffer.st_mode);
  printf("Time of Last access: %s\n", ctime(&buffer.st_atime));
  
  char b[100];
  char *s = "%ld B";
  if(size/1000 > 0){
    size /= 1000;
    s = "%ld KB";
  }
  if(size/1000 > 0){
    size /= 1000;
    s = "%ld MB";
  }
  if(size/1000 > 0){
    size /= 1000;
    s = "%ld GB";
    }
  
  sprintf(b, s, size);
  printf("File size (readable): %s\n", b);
}
