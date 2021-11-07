#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include  <fcntl.h>
#include <unistd.h>
#include "data.h"

int readCSV(){
  struct stat mystat;
  stat("./nyc_pop.txt", &mystat);
  int fh = open("./nyc_pop.txt", O_RDONLY);
  int fhsave = open("./nyc_pop.data", O_CREAT | O_WRONLY, 0777);

  char * bigtext = calloc(1, mystat.st_size);
  read(fh, bigtext, mystat.st_size);
  printf("reading nyc_pop.csv\n");
  char *cp = bigtext;

  // printf("%s\n", bigtext);
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
  int i;
  int lineNumb = 0;
  for (i = 0; bigtext[i] != '\0'; i++){
    if (bigtext[i] == '\n'){
      lineNumb ++;
    }
  }
  // subtract one to account for heading line
  struct pop_entry data[(lineNumb - 1) *5];

  int lineNumbTemp = 0;
  while (target != NULL && *target != '\0'){
    lineNumbTemp++;
    *target = '\0';
    if (lineNumbTemp != 1){
      // printf("%s\n", cp);
      sscanf(cp, "%llu,%llu,%llu,%llu,%llu,%llu\0", &year, &m, &bk, &q, &bx, &si);
      // printf("%llu, %llu, %llu, %llu, %llu, %llu \n", year, m, bk, q, bx, si);
      int i;
      struct pop_entry _m;
      struct pop_entry _bk;
      struct pop_entry _q;
      struct pop_entry _bx;
      struct pop_entry _si;
      _m.year  = year;
      _bk.year  = year;
      _q.year  = year;
      _bx.year  = year;
      _si.year  = year;
      _m.population = m;
      _bk.population = bk;
      _q.population = q;
      _bx.population = bx;
      _si.population = si;
      strcpy(_m.boro,"manhattan");
      strcpy(_bk.boro,"brooklyn");
      strcpy(_q.boro , "queens");
      strcpy(_bx.boro , "bronx");
      strcpy(_si.boro , "staten island");
      // subtract one to account for heading line
      data[(lineNumbTemp-1)* 5 + 0] = _m;
      data[(lineNumbTemp-1)* 5 + 1] = _bk;
      data[(lineNumbTemp-1)* 5 + 2] = _q;
      data[(lineNumbTemp-1)* 5 + 3] = _bx;
      data[(lineNumbTemp-1)* 5 + 4] = _si;
    }
    cp = (target+1);
    target = strchr(cp, '\n');
  }

  write(fhsave,data, sizeof(data));
  printf("wrote %d bytes to nyc_pop.data\n", sizeof(data));
  return 0;
}

int readData(){
  struct stat mystat;
  if (stat("./nyc_pop.data", &mystat) == -1){
    printf("%s\n", strerror(errno));
    return 0;
  }
  int fh = open("./nyc_pop.data", O_RDONLY);
  struct pop_entry *data = calloc(1, mystat.st_size + sizeof(struct pop_entry));

  read(fh, data, mystat.st_size);
  int i = 0;
  int counter = 0;
  for (; i * sizeof(struct pop_entry) < mystat.st_size; i++){
    printf("%d: year: %d boro: %s	pop: %d\n", counter, data[i].year, data[i].boro, data[i].population);
    counter ++;
  }

  // printf("%d\n", mystat.st_size);

}
