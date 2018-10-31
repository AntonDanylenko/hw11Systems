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

  while (permissions)
  {
    octalPerm += (permissions % 8) * i;
    permissions /= 8;
    i *= 10;
  }

  octalPerm = octalPerm%1000;
  printf("OctalPerm: %d\n", octalPerm);

  int binaryPerm = 0;
  i = 1;
  int ii = 100;
  int tempOctal = 0;
  while (ii){
    tempOctal = (octalPerm%(ii*10))/ ii;
    while (tempOctal){
      binaryPerm += (tempOctal % 2) * i;
      tempOctal /= 2;
      i *= 10;
      //printf("tempOctal: %d, binaryPerm: %d, i: %d, ii: %d\n", tempOctal, binaryPerm, i, ii);
    }
    if (ii/10){
      binaryPerm *= 1000;
    }
    ii /= 10;
    i = 1;
    //printf("binaryPerm: %d\n", binaryPerm);
  }
  printf("BinaryPerm: %d\n", binaryPerm);

  i = 1;
  ii = 100000000;
  char permString[20];
  strcpy(permString, "");
  while (binaryPerm){
    printf("Permissions: %s\n", permString);
    if (binaryPerm / ii){
      if (i%3 == 1){
        strcat(permString,"r");
      }
      else if (i%3 == 2){
        strcat(permString,"w");
      }
      else{
        strcat(permString,"x");
      }
    }
    else {
      strcat(permString,"-");
    }
    i++;
    binaryPerm %= ii;
    ii /= 10;
  }
  printf("Permissions: %s\n", permString);
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
}
