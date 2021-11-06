#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include  <fcntl.h>
#include <unistd.h>
#include "data.h"

int main(int argc, char const *argv[]) {
  struct stat mystat;
  stat("./nyc_pop.txt", &mystat);
  int fh = open("./nyc_pop.txt", O_RDONLY);
  int fhsave = open("./nyc_pop.data", 0_CREATE | 0_EXCL | 0_APPEND, 0777);

  char * bigtext = calloc(1, mystat.st_size);
  read(fh, bigtext, mystat.st_size);
  char *cp = bigtext;

  printf("%s\n", bigtext);
  char * target = strchr(cp, '\n');

  // target = strchr(cp, '\n');
  // target[0] = '\0';
  // printf("%s\n", cp);
  // cp = (target + 1);
  // printf("test\n");
  int counter =0;
  unsigned long year;
  unsigned long m;
  unsigned long bk;
  unsigned long q;
  unsigned long bx;
  unsigned long si;

  int boroNumb; // how many pop_entrys there are
  // printf("%s\n", cp);
  while (target != NULL && *target != '\0'){
    lineNumb ++;
    *target = '\0';
    if (lineNumb != 1){
      printf("%s\n", cp);

        sscanf(cp, "%llu,%llu,%llu,%llu,%llu,%llu\0", &year, &m, &bk, &q, &bx, &si);
        printf("%llu, %llu, %llu, %llu, %llu, %llu \n", year, m, bk, q, bx, si);
    }
    printf("%s\n", cp);
    int i;
    struct pop_entry = m;
    struct pop_entry = bk;
    struct pop_entry = q;
    struct pop_entry = bx;
    struct pop_entry = si;
    m -> year  = year;
    bk -> year  = year;
    q-> year  = year;
    bx-> year  = year;
    si-> year  = year;
    m -> population = m;
    bk -> population = bk;
    q -> population = q;
    bx -> population = bx;
    si -> population = si;
    m -> boro = "manhattan";
    bk -> boro = "brooklyn";
    q -> boro = "queens";
    bx -> boro = "bronx";
    si -> boro = "staten island";
    write()


    temp -> population =
    printf("\n");
    cp = (target+1);
    target = strchr(cp, '\n');
  }

  //   target[0] = '\0';
  //   printf("%s\n", bigtext);
  //   // target = strchr(bigtext, '\n');
  // }

  return 0;
}
