#include <stdio.h>
#include <unistd.h>


int main(int argc, char const *argv[])
{
	printf("current process ID: %ld\n",(long)getpid());
	return 0;
}

