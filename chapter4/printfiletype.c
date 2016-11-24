#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char const *argv[])
{
	int i;
	struct stat buf;
	char* ptr;
	for (int i = 1; i <  argc; ++i)
	{
		printf("%s: ", argv[i] );
		if(lstat(argv[i], &buf)==-1){
			printf("lstat errror\n");
			continue;
		}
		if(S_ISREG(buf.st_mode))
			ptr = "regular file";
		else if (S_ISDIR(buf.st_mode))
			ptr = "directory";
		else if (S_ISCHR(buf.st_mode))
			ptr = "character special";
		else if(S_ISBLK(buf.st_mode))
			ptr = "block special";
		else if(S_ISFIFO(buf.st_mode))
			ptr = "fifo";
		else if(S_ISLNK(buf.st_mode))
			ptr = "symbolic link";
		else if(S_ISSOCK(buf.st_mode))
			ptr = "socket";
		else 
			ptr = "unknkown mode **";
		printf("%s\n", ptr);
	}
	return 0;
}