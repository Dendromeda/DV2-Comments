#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//TJA









FILE *openFile(char *file, char *mode);

int main(int argc, char **argv){
  bool mode = 1;
  bool alert = 0;
  char c;
  FILE *inFile;
  FILE *outFile;

  if (argc != 3){
    printf("Usage: removeComments *input file* *output file*\n");
    exit(1);
  }

  inFile = openFile(argv[1], "r");
  outFile = openFile(argv[2], "w");

  c = fgetc(inFile);
  int i = 0;
  while(c != EOF && i<10000){


    if (mode && c == '/'){
      c = fgetc(inFile);
      if (c == EOF);
      else if (c == '*'){
        mode = 0;
      }
      else{
        fprintf(outFile, "/%c", c);
        printf("%c", c);
      }
    }
    else if (mode){
      fprintf(outFile, "%c", c);
      printf("%c", c);
    }


    if (!mode && c == '*'){
      c = fgetc(inFile);
      if (c == EOF);
      else if (c == '/'){
        mode = 1;
      }
    }
    c = fgetc(inFile);
    i++;
    //sleep(0.0001);
  }
}

FILE *openFile(char *file, char *mode){
	FILE *fp = fopen(file, mode);
	if(fp == NULL) {
		fprintf(stderr, "Couldn't open input file %s\n", file);
		exit(0);
	}
	return fp;
}
