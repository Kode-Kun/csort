#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define MAXLINES 5000
#define MAXLEN 1000

char *lineptr[MAXLINES];

void swap(void *v[], int i, int j)
{
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

int main(int argc, char **argv)
{
	char *filename = NULL;
	ssize_t linelen;
	int nlines;

	int num = 0;
	int c;
	opterr = 0;

	// parsing command line arguments
	while ((c = getopt(argc, argv, "nf:")) != -1)
	{
		switch(c){
		case 'n':
			num = 1;
			break;	
		case 'f':
			filename = optarg;
			break;
		case '?':
			if (optopt == 'f')
				fprintf(stderr, "Option -%c requires an argument.\n", optopt);
			else if(isprint(optopt))
				fprintf(stderr, "Unknown option -%c.\n", optopt);
			break;
		default:
			abort();
		}	
	}
	if(filename != NULL){
		FILE *fp = fopen(filename, "r");
		if(fp == NULL){
			perror("fopen");	
			exit(EXIT_FAILURE);
		}
		char *p;
	  char *line = NULL;
		size_t len = 0;
		nlines = 0;
		while((linelen = getline(&line, &len, fp)) > 0)
		{
			if(nlines >= MAXLINES || (p = malloc(linelen)) == NULL)	
				return -1;
			else{
				line[linelen - 1] = '\0';	
				strcpy(p, line);
				lineptr[nlines++] = p;
				free(line);
				line = NULL;
			}
		}			
		fclose(fp);
	}

	printf("filename: %s\nnum: %d\n\n", filename, num);
	printf("unsorted lines:\n\n");
	//print lines unsorted
	for(int i = 0; i < nlines; i++){
		int x = i + 1;
		printf("%d: %s\n", x, lineptr[i]);	
	}
	
	for(int i = 0; i < nlines; i++){
		free(lineptr[i]);		
	}
  return 0;
}

