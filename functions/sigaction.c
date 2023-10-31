#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	/*int n;
	int numSecs;
	sigset_t pendingMask;
	sigset_t blockingMask;
	sigset_t emptyMask;*/

	printf("%s: PID is %ld\n", argv[0], (long)getpid());
	return (0);
}