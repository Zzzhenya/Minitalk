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
	static int count = 0;

	if (sig ==SIGINT)
	{
		count ++;
		printf("	Caught SIGINT (%d)\n", count);
		return;
	}
	printf("	Caught SIGQUIT - OK (%d)\n", count);
	exit(EXIT_SUCCESS);
}

int main(int argc, char **argv)
{
	int j;


	printf("pid: %d\n", getpid());
	if (signal(SIGINT, sighandler) == SIG_ERR)
		errExit("signal");
	if (signal(SIGQUIT, sighandler) == SIG_ERR)
		errExit("signal");
	while (j>= 0)
	{
		//printf("%d\n", j);
		pause();
		//sleep(3);
	}
	return (0);
}