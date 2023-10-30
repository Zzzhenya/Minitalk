#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
		return (kill(atoi(argv[1]), 1));
	else
		return (0);
	return (0);
}