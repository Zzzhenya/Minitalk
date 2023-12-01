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
/*
static char	*char_to_str(char c)
{
	char	str[2];
	char	*s;

	s = NULL;
	str[0] = c;
	str[1] = '\0';
	s = str;
	return (s);
}*/

//static char	*char_collector(char *str, char c, int sig)
void char_collector(char *str, char c, int sig)
{
	if (c)
	{
		//str = gnl_ft_strjoin(str, char_to_str(c));
		str[g_msg.j] = c;
		g_msg.j++;
	}
	else if (!c)
	{
		str[g_msg.j] = '\0';
		ft_printf("msg_size: %d\n", g_msg.j);
		ft_putstr_fd(str, 1);
		ft_putchar_fd('\n', 1);
		ft_memset(str, '\0', MSG_SIZE);
		str = NULL;
		kill (g_msg.pid, sig);
		g_msg.pid = 0;
		g_msg.j = 0;
	}
	//return (str);
}

/* take a stream of bits and convert it to a string of chars */
void	bit_handler(int sig, siginfo_t *info, void *x)
{
	//static char	*str = NULL;
	static char	str[MSG_SIZE];

	(void)x;
	if (g_msg.pid == 0)
		g_msg.pid = info->si_pid;
	if (g_msg.pid != info->si_pid)
	{
		kill (info->si_pid, SIGUSR1);
		return ;
	}
	else
	{
		if (sig == SIGUSR2)
			g_msg.c += (1 << g_msg.i);
		else if (sig == SIGUSR1)
			g_msg.c += (0 << g_msg.i);
		g_msg.i++;
		if (g_msg.i == 7)
		{
			char_collector(str, g_msg.c, SIGUSR2);
			//str = char_collector(str, g_msg.c, SIGUSR2);
			g_msg.c = 0;
			g_msg.i = 0;
		}
	}
}

int	main(void)
{
	struct sigaction	act;

	g_msg.pid = 0;
	g_msg.c = 0;
	g_msg.i = 0;
	g_msg.j = 0;
	ft_printf("Server pid: %d\n", getpid());
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &bit_handler;
	if (sigaction(SIGUSR2, &act, NULL) < 0)
		ft_errexit("sigaction() failed for SIGUSR2.");
	if (sigaction(SIGUSR1, &act, NULL) < 0)
		ft_errexit("sigaction() failed for SIGUSR1.");
	while (1)
		pause();
	return (0);
}
