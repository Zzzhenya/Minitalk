/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:50:16 by sde-silv          #+#    #+#             */
/*   Updated: 2023/11/28 16:58:22 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_msg	g_msg;

static void	write_char(char c)
{
	write (1, &c, 1);
}

/* take a stream of bits and convert it to a string of chars */
static void	bit_handler(int sig, siginfo_t *info, void *x)
{
	(void)x;
	if (g_msg.pid == 0)
		g_msg.pid = info->si_pid;
	if (g_msg.pid == info->si_pid && g_msg.pid != 0)
	{
		if (sig == SIGUSR2)
			g_msg.c += (1 << g_msg.i);
		else if (sig == SIGUSR1)
			g_msg.c += (0 << g_msg.i);
		g_msg.i++;
		if (g_msg.i == 7)
		{
			if (g_msg.c)
				write_char(g_msg.c);
			if (!g_msg.c)
			{
				write_char('\n');
				g_msg.pid = 0;
			}
			g_msg.c = 0;
			g_msg.i = 0;
		}
	}
	else
	{
		if (kill (info->si_pid, SIGUSR1) < 0)
			ft_errexit("kill() failed.");
	}
}

int	main(void)
{
	struct sigaction	act;

	g_msg.pid = 0;
	g_msg.c = 0;
	g_msg.i = 0;
	ft_putstr_fd("Server pid: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &bit_handler;
	if (sigaction(SIGUSR2, &act, NULL) < 0)
		ft_errexit("sigaction() failed for SIGUSR2.");
	if (sigaction(SIGUSR1, &act, NULL) < 0)
		ft_errexit("sigaction() failed for SIGUSR1.");
	while (1)
	{
		pause();
	}
	return (0);
}
