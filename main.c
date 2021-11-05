#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include  <fcntl.h>
#include <unistd.h>


int main(int argc, char const *argv[]) {
  struct stat mystat;
  stat("./nyc_pop.txt", &mystat);
  int fh = open("./nyc_pop.txt", O_RDONLY);
  char * bigtext;
  read(fh, bigtext, mystat.st_size);
  char * cp= bigtext;
  printf("%s\n", cp);
  char* target;
  // target[0] = '\0';
  // printf("%s\n", cp);
  while ( target != NULL){
    // TTDW
    target = strchr(cp, '\n');
    target[0] = '\0';
    cp = (target ++);
    printf("%s\n", cp);
    cp = (target + 1);
  }

  return 0;
}
