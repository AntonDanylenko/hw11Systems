#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

int main(){
  struct stat buffer;
  stat("README.md", &buffer);
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

  int permissions = buffer.st_mode;
  char *permstr = "-";
  if (S_IRUSR(permissions)){
    strcat(permstr, "r");
  }
  if(S_IWUSR(permissions)){
    strcat(permstr, "w");
  }
  if(S_IXUSR(permissions)){
    strcat(permstr, "x");
  }
  if (S_IRGRP(permissions)){
    strcat(permstr, "r");
  }
  if(S_IWGRP(permissions)){
    strcat(permstr, "w");
  }
  if(S_IXGRP(permissions)){
    strcat(permstr, "x");
  }
  if (S_IROTH(permissions)){
    strcat(permstr, "r");
  }
  if(S_IWOTH(permissions)){
    strcat(permstr, "w");
  }
  if(S_IXOTH(permissions)){
    strcat(permstr, "x");
  }
  printf("Permissions: %s", permstr);
}
