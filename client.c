#include "minitalk.h"

/*takes a string and send each letter as a stream of bits*/

int	errexit(char *str)
{
	ft_printf(str);
	return (0);
}

void	send_letter(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		if (((c >> i) & 1) == 1)
		{
			if (kill (pid, SIGUSR2) < 0)
				exit(errexit("kill() Error\n"));
		}
		else
		{
			if (kill (pid, SIGUSR1) < 0)
				exit(errexit("kill() Error\n"));
		}
		if (usleep(100) < 0)
			exit(errexit("usleep() Error\n"));
		i ++;
	}
}

void	string_handler(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		send_letter(pid, str[i]);
		if (usleep(100) < 0)
			exit(errexit("usleep() Error\n"));
		i ++;
	}
	if (str[i] == '\0')
	{
		send_letter(pid, str[i]);
		if (usleep(100) < 0)
			exit(errexit("usleep() Error\n"));
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
		ft_printf("\nUsage : ./client <server_pid> ""Message""\n\n");
	return (0);
}
