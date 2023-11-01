#include <signal.h>
#include "libft/libft.h"

void	send_one(int pid, char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '1')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		i ++;
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
		send_one(pid, str);
	}
	else
		ft_printf("\nUsage : ./client server_pid ""String""\n\n");
	return (0);
}
