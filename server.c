#include "minitalk.h"

t_data   message;

/* take a stream of bits and convert it to a string of chars */

void	bit_handler(int sig)
{
	//ft_printf("step: %d", message.a);
	message.a = message.a + ((sig & 1) << message.c);
	message.c++;
	if (message.c == 7)
	{
		ft_printf("%c", message.a);
		if (!message.a)
			ft_printf("\n");
		message.a = 0;
		message.c = 0;
	}
}

int	main(void)
{
	struct sigaction act;

	ft_printf ("server pid: %d\n", getpid());
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_handler = &bit_handler;
	sigaction(SIGUSR2, &act, NULL);
	sigaction(SIGUSR1, &act, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
