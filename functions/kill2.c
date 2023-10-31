#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int errExit(char *str)
{
	printf("%s\n", str);
	return(-1);
}

int main (int argc, char **argv)
{
	int s;
	int sig;

	if (argc != 3 || strcmp(argv[1], "--help") == 0)
	{
		printf("Usage error: %s pid sig-num\n", argv[0]);
		return (0);
	}
	sig = atoi(argv[2]);
	s = kill(atol(argv[1]), sig);
	if (sig != 0)
	{
		if (s == -1)
			errExit("kill");
	}
	else /* NUll signal: process existance check*/
	{
		if (s == 0)
			printf("Process exists. we can send it a signal\n");
		else
		{
				printf("Process exists. No permission to send signal\n");
				printf("Process does not exist\n");
				errExit("kill");
		}
	}

	exit (EXIT_SUCCESS);

}