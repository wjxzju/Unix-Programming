#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	DIR *dp;
	struct dirent *dirp;
	if(argc!=2){
		printf("%s\n", "usage: ls directory_name");
		exit(-1);
	}
	if((dp = opendir(argv[1]))==NULL){
		printf("open dir:%s failed\n", argv[1]);
		exit(-1);
	}
	while((dirp = readdir(dp))!=NULL){
		printf("%s\n", dirp->d_name);
	}
	closedir(dp);
	return 0;
}