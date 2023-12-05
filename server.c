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

/* Print all the chars at the end of the m*/
static void	char_collector(char *str, int sig, t_msg *msg)
{
	if (msg->c)
	{
		str[msg->j] = msg->c;
		msg->j++;
	}
	else if (!msg->c)
	{
		str[msg->j] = '\0';
		ft_putstr_fd(str, 1);
		ft_putchar_fd('\n', 1);
		ft_memset(str, '\0', MSG_SIZE);
		str = NULL;
		if (kill (msg->pid, sig) < 0)
			ft_errexit ("kill() failed.");
		msg->pid = 0;
		msg->j = 0;
	}
	msg->c = 0;
	msg->i = 0;
}

/* take a stream of bits and convert it to a string of chars */
void	bit_handler(int sig, siginfo_t *info, void *x)
{
	static t_msg	msg;
	static char		str[MSG_SIZE];

	(void)x;
	if (msg.pid == 0)
		msg.pid = info->si_pid;
	if (msg.pid != info->si_pid)
	{
		if (kill (info->si_pid, SIGUSR1) < 0)
			ft_errexit ("kill() failed.");
		return ;
	}
	else
	{
		if (sig == SIGUSR2)
			msg.c += (1 << msg.i);
		else if (sig == SIGUSR1)
			msg.c += (0 << msg.i);
		msg.i++;
		if (msg.i == 7)
			char_collector(str, SIGUSR2, &msg);
	}
}

int	main(void)
{
	struct sigaction	act;

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
