sigaction()  - Changing signal dispositions

An alternative to signal()

More complex than signal() but more flexibility.

Retrieves the signal disposition without changing it , and to set attributes controlling what happens when a signal handler is invoked.

More portable.
~~~
int sigaction(int sig,
 const struct sigaction *act,
 struct sigaction *oldact);
~~~

 Returns 0 on success and -1 on error.

 sig: identifies the signal whose disposition we want to retrieve or change. Can be any signal except SIGKILL or SIGSTOP

 act: a pointer to a structure specifiing a new disposition for the signal. If what you want is ONLY to find existing disposition of the signal act can be specified as NULL.

 oldact: a pointer to a structure of used to return information about the signal's previous disposition. If this is not needed, oldact also can be set to NULL.

Simplified form of sigaction structure

~~~
 struct sigaction {
 	void		(*sa_handler)(int); // address of handler
 	sigset_t	sa_mask; // signals blocked during handler
 	int 		sa_flags; // flags controlling handler invocation
 	void		(*sa_restorer)(void); // Not for application use
 }
 ~~~

 sa_handler -  corresponds to the handler argument given to signal(). - Specifies the address of a signal handler or SIG_IGN or SIG_DFL

 sa_mask  - sa_flags - only interpreted if sa_handler is the address of a signal handler (a value other than SIG_IGN or SIG_DFL)

 sa_mask -  defines a set of signals to be blocked duwing invocation of the hander defined by the sa_handler. 

 sa_restorer - is used internally to ensure that on signal handler completion a call is made to the sigreturn() system call which restore the process's execution context.

