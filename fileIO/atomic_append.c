#include <sys/types.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#include "tlpi_hdr.h"

#ifndef BUF_SIZE
#define BUF_SIZE 1000000
#endif

/* This program appends to a file and writes the number of bytes
 * specified by the command.
 *
 * If a third command line argument (x) is present, the program should 
 * lseek to the end of the file before each write.
 *
 * command format: atomic_append filename num-bytes [x]
 */

/*
static void usageErr(const char *progName);
static void errExit(const char *msg);
*/

int
main(int argc, char **argv)
{

	int numBytes, j, flags, fd;
	Boolean useLseek;

	if (argc < 3 || strcmp(argv[1], "--help") == 0)
	usageErr("%s file num-bytes [x]\n"
		 "        'x' means use lseek() instead of O_APPEND\n",
		 argv[0]);

	useLseek = argc > 3;
	flags = useLseek ? 0 : O_APPEND;
	numBytes = getInt(argv[2], 0, "num-bytes");

	fd = open(argv[1], O_RDWR | O_CREAT | flags, S_IRUSR | S_IWUSR);
	if (fd == -1)
		errExit("open");

	for (j = 0; j < numBytes; j++) {
		if (useLseek)
		    if (lseek(fd, 0, SEEK_END) == -1)
			errExit("lseek");
		if (write(fd, "x", 1) != 1)
		    fatal("write() failed");
	}

	printf("%ld done\n", (long) getpid());
	exit(EXIT_SUCCESS);
}

/*
static void usageErr(const char *progName) {
	fprintf(stderr, "Usage: %s\n", progName);
	fflush(stderr);
	exit(EXIT_FAILURE);
}

static void errExit(const char *msg) {
	perror(msg);
	fflush(stderr);
	exit(EXIT_FAILURE);
}
*/
