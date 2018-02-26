#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//TJA









FILE *openFile(char *file, char *mode);

int main(int argc, char **argv){
  bool mode = 1;
  char c;
  FILE *inFile;
  FILE *outFile;

  if (argc != 3){
    printf("USAGE: \nremoveComments [INPUT FILE] [OUTPUT FILE]\n");
    exit(1);
  }

  inFile = openFile(argv[1], "r");
  outFile = openFile(argv[2], "w");

  c = fgetc(inFile);
  while(c != EOF){
    if (mode && c == '/'){
      c = fgetc(inFile);
      if (c == EOF);
      else if (c == '*'){
        mode = 0;
      }
      else{
        fputc(c, outFile);
        printf("%c", c);
      }
    }
    else if (mode){
      fputc(c, outFile);
      printf("%c", c);
    }
    else if (!mode && c == '*'){
      c = fgetc(inFile);
      if (c == EOF);
      else if (c == '/'){
        mode = 1;
      }
    }
    c = fgetc(inFile);
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
