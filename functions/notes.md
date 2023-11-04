notes.md

get_pid() - man

#include <unistd.h>

pid_t	getpid(void);

getpid() returns the process ID of the calling process.  The ID is guaranteed to be unique and is useful for constructing temporary file names.
getppid() returns the process ID of the parent of the calling process.

#include <sys/types.h>

pid_t is defined in sys/types.h. The include file <sys/types.h> is necessary.

In GNU, getpid() returns an int.

The getpid() and getppid() functions are always successful, and no return value is reserved to indicate an error.

