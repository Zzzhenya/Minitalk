#include "minitalk.h"

/*takes a string and send each letter as a stream of bits*/
void	string_handler(int pid, char *str)
{
	int i;
	int c;

	i = 0;
	while (str[i] != '\0')
	{
		c = 0;
		while (c < 7)
		{
			if (((str[i] >> c) & 1) == 1)
				kill (pid, SIGUSR2);
			else
				kill (pid, SIGUSR1);
			usleep(100);
			c ++;
		}
		usleep(100);
		i ++;
	}
	if (str[i] == '\0')
	{
		c = 0;
		while (c < 7)
		{
			if (((str[i] >> c) & 1) == 1)
				kill (pid, SIGUSR2);
			else
				kill (pid, SIGUSR1);
			usleep(100);
			c ++;
		}
		usleep(100);
	}
	
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		string_handler(pid, str);
	}
	else
		ft_printf("\nUsage : ./client <server_pid> <Message>\n\n");
	return (0);
}
