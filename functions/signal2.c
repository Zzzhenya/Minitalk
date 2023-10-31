#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int errExit(char *str)
{
	printf("%s\n", str);
	return(-1);
}

static void sighandler(int sig)
{
	printf("Abcd\n");
	//exit(0);
}

int main(int argc, char **argv)
{
	int j;

	if (signal(SIGINT, sighandler) == SIG_ERR)
		errExit("signal");

	while (j>= 0)
	{
		printf("%d\n", j);
		j ++;
		sleep(3);
	}
	return (0);
}