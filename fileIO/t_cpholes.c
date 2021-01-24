#include <sys/types.h>
#include <sys/stat.h>

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "tlpi_hdr.h"

#ifndef BUF_SIZE
#define BUF_SIZE	1024
#endif

int
main(int argc, char *argv[])
{
	/* write a program like 'cp' that copies holes in a file (null bytes)
	 * to the new file */

	// var setup
	int inFd, outFd, openFlags;
	mode_t filePerms;
	ssize_t numRead;
	char buf[BUF_SIZE];

	// setup return error if incorrect args 
	if (argc != 3 || strcmp(argv[1], "--help") == 0)
		usageErr("%s Usage: old-file new-file\n");

	// setup file permissions
	openFlags = O_CREAT | O_WRONLY | O_TRUNC;
	filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
		    S_IROTH | S_IWOTH;	/* rw-rw-rw */
	
	// connect to the inFd
	inFd = open(argv[1], O_RDONLY);
	if (inFd == -1)
		errExit("opening file %s", argv[1]);

	// connect to the outFd
	outFd = open(argv[2], openFlags, filePerms);
	if (outFd == -1) 
		errExit("opening file %s", argv[2]);

	// loop through and read the bytes
	while ((numRead = read(inFd, buf, BUF_SIZE)) > 0)
		if (write(outFd, buf, numRead) != numRead)
			fatal("could not write entire buffer");

	if (numRead == -1)
		errExit("read");
	
	// close the files
	if (close(inFd) == -1)
		errExit("close input");
	if (close(outFd) == -1)
		errExit("close output");


	exit(EXIT_SUCCESS);
}
