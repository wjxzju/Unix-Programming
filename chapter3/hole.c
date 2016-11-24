#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define	FILE_MODE	(S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(int argc, char const *argv[])
{
	int fd;
	if((fd = creat("file.hole", FILE_MODE))==-1){
		printf("create error\n");
		exit(-1);
	}

	if(write(fd,buf1, 10)!=10){
		printf("write1 error\n");
		exit(-1);
	}
		
	if(lseek(fd,20,SEEK_SET)==-1){
		printf("seek error\n");
		exit(-1);
	}

	if(write(fd,buf2,10)!=10){
		printf("write2 error\n");
		exit(-1);
	}


	return 0;
	
}