#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include  <fcntl.h>
#include <unistd.h>
#include "data.h"
#include "csvFun.h"
int main(int argc, char const *argv[]) {
  if( argc > 2 ) {
      printf("Too many arguments supplied.\n");
      return 0;
   }
  else if(argc < 2){
      printf("Include an argument\n\
      -read_csv\n\
      -read_data\n\
      -add_data\n\
      -update_data\n");
      return 0;
   }else if(argc == 2){
     if (!strcmp(argv[1], "-read_csv")){
       readCSV();
     }else if(!strcmp(argv[1], "-read_data")){
       readData();
     }
   }

  return 0;
}
