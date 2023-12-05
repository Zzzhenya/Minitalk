/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:43:13 by sde-silv          #+#    #+#             */
/*   Updated: 2023/11/28 16:59:16 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*takes a char and send as a stream of bits*/
static void	send_letter(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		if (((c >> i) & 1) == 1)
		{
			if (kill (pid, SIGUSR2) < 0)
				ft_errexit ("kill() failed.");
			usleep (50);
		}
		else
		{
			if (kill (pid, SIGUSR1) < 0)
				ft_errexit ("kill() failed.");
			usleep (50);
		}
		i ++;
	}
}

/* take each char*/
static void	string_handler(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		send_letter (pid, str[i]);
		usleep (100);
		i ++;
	}
	if (str[i] == '\0')
	{
		send_letter (pid, str[i]);
		usleep (100);
	}
}

/* Receive signal from server when busy or message complete"*/
static void	busy(int sig)
{
	if (sig == SIGUSR1)
		ft_errexit ("\nServer is busy. Please wait.\n");
	else if (sig == SIGUSR2)
		ft_errexit ("\nMessage complete.\n");
}

int	main(int argc, char **argv)
{
	int					pid;
	char				*str;
	struct sigaction	act;

	sigemptyset (&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_handler = &busy;
	if (sigaction (SIGUSR1, &act, NULL) < 0)
		ft_errexit ("sigaction() failed for SIGUSR1.");
	if (sigaction (SIGUSR2, &act, NULL) < 0)
		ft_errexit ("sigaction() failed for SIGUSR1.");
	if (argc == 3)
	{
		pid = ft_atoi (argv[1]);
		if (pid < 1000)
			ft_errexit ("That's a system process, not a server.");
		str = argv[2];
		string_handler (pid, str);
		while (1)
			pause ();
	}
	else
		ft_printf ("\nUsage : ./client <server_pid> ""Message""\n\n");
	return (0);
}
/*		//if (ft_strlen (str) == 0)
		//	ft_errexit ("Empty message.");*/
