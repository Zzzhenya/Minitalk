#include "minitalk.h"

t_data	g_msg;
/* take a stream of bits and convert it to a string of chars */

static int	errexit(char *str)
{
	ft_printf(str);
	return (0);
}

static void	bit_handler(int sig)
{
	g_msg.c = g_msg.c + ((sig & 1) << g_msg.i);
	g_msg.i++;
	if (g_msg.i == 7)
	{
		ft_printf("%c", g_msg.c);
		if (!g_msg.c)
			ft_printf("\n");
		g_msg.c = 0;
		g_msg.i = 0;
	}
}

int	main(void)
{
	struct sigaction	act;

	ft_printf ("server pid: %d\n", getpid());
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_handler = &bit_handler;
	if (sigaction(SIGUSR2, &act, NULL) < 0)
		exit(errexit("sigaction() Error for SIGUSR2\n"));
	if (sigaction(SIGUSR1, &act, NULL) < 0)
		exit(errexit("sigaction() Error for SIGUSR1\n"));
	while (1)
	{
		pause();
	}
	return (0);
}
