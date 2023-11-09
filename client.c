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

static int	errexit(char *str)
{
	ft_printf ("%s\n", str);
	exit (EXIT_FAILURE);
}

static void	send_letter(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		if (((c >> i) & 1) == 1)
		{
			if (kill (pid, SIGUSR2) < 0)
				errexit("kill() error.");
		}
		else
		{
			if (kill (pid, SIGUSR1) < 0)
				errexit("kill() error.");
		}
		if (usleep(100) < 0)
			errexit("usleep() error.");
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
		if (usleep(100) < 0)
			errexit("usleep() error.");
		i ++;
	}
	if (str[i] == '\0')
	{
		send_letter(pid, str[i]);
		if (usleep(100) < 0)
			errexit("usleep() error.");
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
