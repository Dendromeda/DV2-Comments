#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//TJA









FILE *openFile(char *file, char *mode);

int main(int argc, char **argv){
  bool mode = 1;
  char c1;
  char c2;
  FILE *inFile;
  FILE *outFile;

  if (argc != 3){
    printf("USAGE: \nremoveComments [INPUT FILE] [OUTPUT FILE]\n");
    exit(1);
  }

  inFile = openFile(argv[1], "r");
  outFile = openFile(argv[2], "w");

  c1 = fgetc(inFile);
  while(c1 != EOF){
    c2 = fgetc(inFile);
    
    if (mode){
      if (c1 == '/' && c2 =='*'){
        mode = 0;
      }
      else {
        fputc(c1, inFile);
        printf("%c", c1);
      }
    }
    if (!mode){
      if (c1 == '*' && c2 == '/'){
        mode = 1;
        c2 = fgetc(inFile);
      }
    }
    c1 = c2;
  }
  fclose(inFile);
  fclose(outFile);
}

FILE *openFile(char *file, char *mode){
	FILE *fp = fopen(file, mode);
	if(fp == NULL) {
		fprintf(stderr, "Couldn't open input file %s\n", file);
		exit(0);
	}
	return fp;
}
