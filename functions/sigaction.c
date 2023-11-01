#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	sigint_handler(int signal)
{
	if (signal == SIGINT)
		printf("\n Intercepted SIGINT\n");
}

void set_signal_action(void)
{
	struct sigaction act;

	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	//bzero(&act, sizeof(act));

	act.sa_handler = &sigint_handler;
	sigaction(SIGINT, &act, NULL);
}


int main(void)
{
	set_signal_action();

	while (1)
		pause();
	return (0);
}