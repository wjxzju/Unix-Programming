#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
#define MAXLINE 1028
static void sig_int(int signo){
	printf("interrupt hello\n%%");
}

int main(int argc, char const *argv[])
{
	char buf[MAXLINE];
	pid_t pid;
	int status;
    
    if(signal(SIGINT,sig_int) == SIG_ERR){
    	printf("signal error\n");
    	exit(-1);
    }

    printf("%% ");
	while ( fgets(buf, MAXLINE, stdin) != NULL) {
		if (buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = '\0';
		if ((pid = fork()) < 0) {
			printf("fork failed\n");
			exit(-1);
		} else if (pid == 0) {  //child process 
			execlp(buf, buf, NULL);
			printf("couldn't execute %s\n",buf );
			exit(127);
		}
		//parent process
		if ( (pid = waitpid(pid, &status, 0)) < 0) { 
			printf("waitpid error\n");
			exit(-1);
		}
		printf("%%\n");

	}
	return 0;
}