#include <sys/types.h>
#include <sys/stat.h>

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "tlpi_hdr.h"

int
main(void)
{
	int fd;
	char template[] = "/tmp/somestringXXXXXX";

	fd = mkstemp(template);
	if (fd == -1)
		errExit("mkstemp");
	printf("Generated filename was: %s\n", template);
	sleep(5);		/* sleep so I can see the file in /tmp folder */

	unlink(template);	/* Name disappears immediately, but the file
				   is removed only after close(); */

	/* Use file I/O system calls - read(), write(), and so on */

	if (close(fd) == -1)
		errExit("close");


	exit(EXIT_SUCCESS);
}
