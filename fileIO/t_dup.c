#include <sys/types.h>
#include <sys/stat.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

/* 
 * dup and dup2 return a new file descriptor on success or -1 on error 
 */

int new_dup(int fd);
int new_dup2(int oldfd, int newfd);

int
main(int argc, char **argv)
{	
	(void)argc;
	(void)argv;

	exit(EXIT_SUCCESS);
}

int
new_dup(int fd)
{
	return fcntl(fd, F_DUPFD, 0);
}

int
new_dup2(int oldfd, int newfd)
{
	int save;

	if (newfd < 0) {
		errno = EBADF;
		return -1;
	}

	/* Check to see if they are equal */
	if (fcntl(oldfd, F_GETFL) < 0)
		return -1;

	if (oldfd == newfd)
		return newfd;

	save = errno;
	(void) close (newfd);
	errno = save;

	return fcntl(oldfd, F_DUPFD, newfd);
}
