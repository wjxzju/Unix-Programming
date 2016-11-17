#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>

#define BUF_SIZE 4096
int main(int argc, char const *argv[])
{
	int n;
	char buf[BUF_SIZE];

	while( (n = read(STDIN_FILENO,buf,BUF_SIZE)) >0){
		printf(" n = %d\n",n );
		if(write(STDOUT_FILENO, buf, n)!=n){
			printf("write error\n");
			exit(-1);
		}
	}
		
	if(n<0){
		printf("read error\n");
		exit(-1);
	}
	return 0;
}