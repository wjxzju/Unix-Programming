#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

char * env_init[] = {"USER=unknown", "PATH=/tmp",NULL};

void err_sys(char * s){
	printf("%s\n", s);
	exit(-1);
	
}

int main(void){

	pid_t pid;

	if((pid = fork() ) < 0){
		err_sys("fork error");
	} else if( pid == 0) { //child
		if(execle("/home/wjx/Unix/chapter8/echoall", "echoall", "myarg1",
					"myarg2", (char *)0, env_init) < 0)
			err_sys("execle error");
	}  

	if(waitpid(pid, NULL, 0) < 0)
		err_sys("waitpid error");

	if((pid = fork()) < 0){
		err_sys("fork error");
	} else if(pid == 0){
		if( execlp("/home/wjx/Unix/chapter8/echoall", "echoall", "only 1 arg", (char *)0)< 0)
			err_sys("execlp error");
	}

	exit(0);
	
}
