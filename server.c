#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	handler(int sig)
{
	if (sig ==SIGUSR1)
		printf("1\n");
	else
		printf("0\n");
}

int	main(void)
{
	struct sigaction act;


	printf ("server pid: %d\n", getpid());
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
