#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 3)
		printf ("%s : %s\n", argv[1], argv[2]);
	else
		return (0);
	return (0);
}