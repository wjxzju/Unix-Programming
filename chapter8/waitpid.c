#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	pid_t pid;


	if( (pid = fork() ) < 0){
		printf("fork error\n");
		exit(-1);
	}else if(pid == 0){  // first child 
		if( (pid = fork() ) < 0 ){
			printf("fork error\n");
			exit(-1);
		} else if (pid > 0 )   // second child's parent == first children
			exit(0); 
		sleep(5);
		printf("second child, parent id = %ld \n", (long)getppid());
		exit(0);
	        
	}
	if (waitpid(pid, NULL, 0) != pid){
		printf("wait pid error\n");
		exit(-1);

	}

	exit(0);



}
