#include <signal.h>
#include "libft/libft.h"

void	handler(int sig)
{
	if (sig ==SIGUSR1)
		ft_printf("1\n");
	else
		ft_printf("0\n");
}

int	main(void)
{
	struct sigaction act;


	ft_printf ("server pid: %d\n", getpid());
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_handler = &handler;
	//signal(SIGUSR1, handler);
	sigaction(SIGUSR2, &act, NULL);
	sigaction(SIGUSR1, &act, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
