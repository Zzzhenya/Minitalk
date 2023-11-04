#include "minitalk.h"

/*takes a string and send each letter as a stream of bits*/

void	send_letter(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		if (((c >> i) & 1) == 1)
		{
			if (kill (pid, SIGUSR2) < 0)
			{
				ft_printf("kill() Error\n");
				exit(0);
			}
		}
		else
		{
			if (kill (pid, SIGUSR1) < 0)
			{
				ft_printf("kill() Error\n");
				exit(0);
			}
		}
		usleep(100);
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
		usleep(100);
		i ++;
	}
	if (str[i] == '\0')
	{
		send_letter(pid, str[i]);
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
