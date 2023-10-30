#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

/*

linux:

typedef void (*sighandler_t)(int);

sighandler_t signal(int signum, sighandler_t handler);


mac:

void (*
     signal(int sig, void (*func)(int));
     )(int);
or

typedef void (*sig_t) (int);

sig_t	signal(int sig, sig_t func);
*/



void signal_handler(int signum) 
{
  printf("Received SIGINT! %d\n", signum);
  exit(0);
}

int main() 
{
  // Set the signal handler for the SIGINT and SIGTERM signals
  // to the signal_handler function
  
  signal(SIGINT, signal_handler);
  signal(SIGTERM, signal_handler);

  while (1) {
    // Do some work here...
  }

  return 0;
}
