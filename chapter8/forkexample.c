#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int globvar = 6;
char buf[] = "a write to stdout\n";

int main(int argc, char const *argv[])
{

	int var;
	pid_t pid;
	var = 88;
	if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1) {
		printf("write error\n");
		exit(-1);
	}
	printf("befor fork\n");
	if ((pid = fork()) < 0) {
		printf("fork failed\n");
		exit(-1);
	}else if (pid == 0) { //child 
		globvar++;
		var++;
	} else {   // parent
		sleep(2);
	}

	printf("pid = %d, globvar = %d, var = %d\n", getpid(), globvar, var);

	return 0;
}