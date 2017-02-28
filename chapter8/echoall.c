#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[]){

	extern char ** environ;

	for(int i = 0; i < argc; i++ )
		printf("argv[%d]: %s \n", i , argv[i]);

	for(char** ptr = environ; *ptr != 0; ptr++ )
		printf("env: %s\n", *ptr);

	exit(0);
}

