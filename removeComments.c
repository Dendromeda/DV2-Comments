#include <stdio.h>











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
  outFile = openFile(argv[2] "w");

  c = fgetc(inFile);
  while(c) != NULL);


    if (mode && c == '/'){
      if (c = fgetc(inFile) == NULL);
      else if (c == '*'){
        mode = 0;
      }
      else{
        fprintf(outfile, "/%c", c);
      }
    }
    else if (mode){
      fprintf(outfile, "%c", c);
    }


    if (!mode && c == '*'){
      if (c = fgetc(inFile) == NULL);
      else if (c == '/'){
        mode = 1;
      }
    }


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
