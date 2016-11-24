 #include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int globvar = 6;

int main(int argc, char const *argv[])
{
	int var =88;
	pid_t pid;

	var = 88;
	printf("before vfork\n");

	if((pid = vfork())<0){
		printf("vfork failed\n");
		exit(-1);
	}else if (pid ==0){  // child 
		globvar++;
		var ++;
		_exit(0);
	}

	// go back parent
	printf("pid = %d, globvar = %d, var = %d\n", getpid(), globvar, var);
}