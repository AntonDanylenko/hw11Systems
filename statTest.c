#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
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
  int octalPerm = 0;
  int i = 1;

  while (decimalNumber != 0)
  {
    octalPerm += (permissions % 8) * i;
    permissions /= 8;
    i *= 10;
  }

  octalPerm = octalPerm/1000;
  printf("OctalPerm: %d\n", octalPerm);
  /*char *permstr = "-";
  if (S_IRUSR(permissions)){
    strcat(permstr, "r");
  }
  else{strcat(permstr, "-");}
  if(S_IWUSR(permissions)){
    strcat(permstr, "w");
  }
  else{strcat(permstr, "-");}
  if(S_IXUSR(permissions)){
    strcat(permstr, "x");
  }
  else{strcat(permstr, "-");}
  if (S_IRGRP(permissions)){
    strcat(permstr, "r");
  }
  else{strcat(permstr, "-");}
  if(S_IWGRP(permissions)){
    strcat(permstr, "w");
  }
  else{strcat(permstr, "-");}
  if(S_IXGRP(permissions)){
    strcat(permstr, "x");
  }
  else{strcat(permstr, "-");}
  if (S_IROTH(permissions)){
    strcat(permstr, "r");
  }
  else{strcat(permstr, "-");}
  if(S_IWOTH(permissions)){
    strcat(permstr, "w");
  }
  else{strcat(permstr, "-");}
  if(S_IXOTH(permissions)){
    strcat(permstr, "x");
  }
  else{strcat(permstr, "-");}*/
  //printf("Permissions: %s", permstr);
}
