/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:43:13 by sde-silv          #+#    #+#             */
/*   Updated: 2023/11/04 16:44:11 by shenya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*takes a string and send each letter as a stream of bits*/
static void	send_letter(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		if (((c >> i) & 1) == 1)
		{
			kill (pid, SIGUSR2);
			usleep(300);
		}
		else
		{
			kill (pid, SIGUSR1);
			usleep(300);
		}
		i ++;
	}
}

static void	string_handler(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		send_letter(pid, str[i]);
		usleep(300);
		i ++;
	}
	if (str[i] == '\0')
	{
		send_letter(pid, str[i]);
		usleep(300);
	}
}

static void busy(int sig)
{
	if (sig == SIGUSR1)
		ft_errexit("\nServer is busy. Please wait.\n");
}

int	main(int argc, char **argv)
{
	int					pid;
	char				*str;
	struct sigaction 	act;

	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_handler = &busy;
	sigaction(SIGUSR1, &act, NULL);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		if (ft_strlen(str) == 0)
			ft_errexit("Empty message.");
		string_handler(pid, str);
	}
	else
		ft_printf("\nUsage : ./client <server_pid> ""Message""\n\n");
	return (0);
}
