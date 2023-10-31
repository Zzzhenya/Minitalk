Many signal related system calls are able to represent a group of different signals

e.g.: sigaction() and sigprocmask() allow a program to specfy a group of signals that are to be blocked by a process.

Multiple signals are representated using a data structure called a signal set. 

*sigset_t* 

sigemptyset() initializes a signal set to contain no members.

int sigemptyset(sigset_t *set);


sigfillset() initializes a set to contain al signals (including all realtime signals)

*int sigfillset(sigset_t *set);


One of these functions MUST be used to initialize a signal set.


WHY? This is because C doesn't initialize automatic variables and the initialization of static variables to 0 can't portably be relied upon as indicating an empty signal set. (since signal sets may be implemented using structures other than bit masks)

(For the same reason it is incorrect to use memset to zero the contents of a signal set in order to mark it as empty)


After initializarion, individual signals ca be added to a set using sigaddset() and removed using sigdelset().

For both sig aregument is a signal number.

int sigaddset(const sigset_t *set, int sig);

int sigdelset(const sigset_t *set, int sig);


-- realtime signals

-- bit masks

-- async-signal-safe