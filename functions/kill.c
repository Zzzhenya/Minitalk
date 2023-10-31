#include <stdlib.h>
#include <signal.h>

int main (int argc, char **argv)
{
	if (argc == 2)
	{
		kill(atoi(argv[1]), SIGQUIT);
	}
	return (0);
}