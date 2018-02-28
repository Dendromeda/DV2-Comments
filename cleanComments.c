/*
DV2: Algoritmer och problemlösning.
File: cleanComments.c
Name: Adam Lindgren & Jakob Lundin.
CS-user: dv17aln & c14jln
Date: 26 Februari 2018
Description: Goes through a given textfile and removes the comments in between
			the '/*' and '* /' (with no space inbetween, we had to include that
			because otherwise it would undo this comment).
input: A filepath for input file and a filepath for output file.
Output: Writes the the resulting text to the given output file.
Limitations: None.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


FILE *openFile(char *file, char *mode);

int main(int argc, char **argv){
	int state = 1;
	char c;
	FILE *inFile;
	FILE *outFile;

	if (argc != 3){
		printf("USAGE: \ncleanComments [INPUT FILE] [OUTPUT FILE]\n");
		exit(1);
 	}

	inFile = openFile(argv[1], "r");
	outFile = openFile(argv[2], "w");
	c = fgetc(inFile);
	while(c != EOF){
		switch(state) {
			//
			case 1:
				if(c == '/') {
					state = 2;
				} else {
					fputc(c, outFile);
				}
				break;
			//
			case 2:
				if(c == '*') {
					state = 3;
				} else {
					state = 1;
					fputc('/', outFile);
					fputc(c, outFile);
				}
				break;
			//
			case 3:
				if(c == '*') {
					state = 4;
				}
				break;
			//
			case 4:
				if(c == '/') {
					state = 1;
				} else {
					state = 3;
				}
				break;
		}
		c = fgetc(inFile);
	}

	fclose(inFile);
	fclose(outFile);
}


/* Function:	openFile
 * Description:	Opens a file, if not possible it exits the program and gives
 				an error message.
 * Input:		A string with the filepath.
 * Output:		File pointer.
 */
FILE *openFile(char *file, char *mode){
	FILE *fp = fopen(file, mode);
	if(fp == NULL) {
		fprintf(stderr, "Couldn't open input file %s\n", file);
		exit(2);
	}
	return fp;
}
