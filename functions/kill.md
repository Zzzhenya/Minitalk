kill() - Send signals

Send signals from one process to another

#include <signal.h>

int kill(pid_t pid, int sig);

Returns 0 on success and -1 on error.

pid:

	if pid > 0  : signal sent to the process identified by pid

	if pid == 0 : signal sent to every process in the same process group as the calling process

	if pid < -1 : signal sent to all processes in the same process group whose ID equals to the absolute value of pid. 

	if pid == -1 : signal is sent to every process for which the calling process has permission to send a signal, except init (process ID 1) and the calling process. 
	AKA Broadcast signals

	if no process matches the pid, kill() fails and sets errno to ESRCH("No such process")



killpg() - send signal to all the members of a process group


int killpg(pid_t pgrp, int sig);

Returns 0 on success and -1 on error

It's equivalent to kill(-pgrp, sig);