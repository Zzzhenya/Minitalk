/*pseudocode and notes*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void	(*signal(int sig, void (*handler)(int)))(int);
/* Returns previous signal disposition on success or
SIG_ERR on error*/

void	handler (int sig)
{
	/*code for handler*/
}

/* Following can be used to temporarily 
establish a handler for a signal, and then reset 
the disposition of the signal to whatever it was 
before*/

void	(*old_handler)(int);

	old_handler = signal(SIGINT, new_handler);
	if (old_handler == SIG_ERR)
		exit(printf("signal"));
/* Do something else here. During this time, if
SIGINT is delivered, new_handler will be utilized to 
handle the signal */

	if (signal(SIGINT, old_handler) == SIG_ERR)
		exit(printf("signal"));

/* It is not possible to use signal() to get the current
disposition of a signal without at the same time changing 
that disposition. For this sigaction() is needed*/

/*making signal() protoype more comprehensible*/

// Pointer to a signalhandler function
typedef	void(*sighandler_t)(int);

sighandler_t	signal(int sig, sighandler_t handler);

/* Instead of specifying the address of a function as
the handler argument of signal(), it can be specified
as
	SIG_DFL : reset disposition of the signal
			to its default
	or
	SIG_IGN : ignore the signal

In which case signal() can be defined as 
when successful returning previous disposition of 
the signal (the address of previously installed 
handler function OR one of 
SIG_DFL or SIG_IGN constants)*/

