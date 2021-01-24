#include <sys/types.h>
#include <sys/stat.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

static void usageErr(const char *progName);
static void errExit(const char *msg); 


int
main(int argc, char **argv)
{
	// var setup
	int fd, openFlags;
	mode_t filePerms;
	off_t offset;
	ssize_t numRead;
	char *buf[BUF_SIZE];

	// check argc
	if (argc != 2 || (strcmp(argv[1], "--help") == 0))
		usageErr(argv[0]);

	// flags setup
	openFlags = O_WRONLY | O_APPEND;
	filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
		    S_IROTH | S_IWOTH;	/* rw-rw-rw */

	// opens file to append
	fd = open(argv[1], openFlags, filePerms);
	if (fd == -1)
		errExit("open");

	// seek to beginning of file
	offset = lseek(fd, 0, SEEK_SET);
	if (offset == -1)
		errExit("lseek");

	// read from STDIN_FILENO
	while((numRead = read(STDIN_FILENO, buf, BUF_SIZE)) > 0)
		if (write(fd, buf, numRead) != numRead)
			errExit("write");

	if (numRead == -1)
		errExit("read");

	// close files
	if (close(fd) == -1)
		errExit("close");

	exit(EXIT_SUCCESS);
}

static void
usageErr(const char *progName) {
  fprintf(stderr, "Usage: %s\n", progName);
  fflush(stderr);
  exit(EXIT_FAILURE);
}

static void
errExit(const char *msg) {
  perror(msg);
  fflush(stderr);
  exit(EXIT_FAILURE);
}
