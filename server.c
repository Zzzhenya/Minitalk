#include <stdio.h>
#include <unistd.h>

/* 
	pid_t	getpid(void);

getpid() returns the process ID of the calling 
process.  The ID is guaranteed to be unique and 
is useful for constructing temporary file names.
*/

int main(void)
{
	pid_t	server_id;

	server_id = getpid();
	printf ("server pid: %d\n", server_id);
	return (0);
}