#include <sys/types.h>
#include <sys/stat.h>

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

#include "tlpi_hdr.h"

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

#define printable(ch) (isprint((unsigned char) ch) ? ch : '#')

/*
 * Read from STDIN_FILENO until EOF and write to STDOUT_FILENO
 * and file specified in argv[2].
 *
 * If the file specified in argv[2] already exists, overwrite it.
 *
 * Implement -a flag using getopt() function to append text to a file
 * if it already exists.
 *
 * Ex: t_tee -a filename
 */

int
main(int argc, char **argv)
{
	// var setup
	int outFd, newFlags, appendFlags;
	mode_t filePerms;
	char buf[BUF_SIZE];
	ssize_t numRead;

	// getopt var setup
	int opt;
	char *astr;

	astr = NULL;

	// check argv count
	if (argc < 2 || (strcmp(argv[1], "--help") == 0))
		usageErr("%s usage: command or output-file\n", argv[0]);

	// permissions setup
	newFlags = O_CREAT | O_WRONLY | O_TRUNC;
	appendFlags = O_WRONLY | O_APPEND;
	filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
		    S_IROTH | S_IWOTH;	/* rw-rw-rw */
	
	// getopt setup
	while ((opt = getopt(argc, argv, "a:")) != -1) {
		switch(opt) {
		case 'a': astr = optarg;	break;
		default: fatal("Unexpected case in switch()");
		}
	}

	/* connect to the output file, depending on whether 
	 * there is an '-a' option present */
	if (astr != NULL) 
		outFd = open(astr, appendFlags, filePerms);
	else
		outFd = open(argv[1], newFlags, filePerms);
	
	
	if (outFd == -1)
		errExit("error opening %s", argv[2]);

	// read into buffer
	while ((numRead = read(STDIN_FILENO, buf, BUF_SIZE)) > 0) {
		if (write(STDOUT_FILENO, buf, numRead) != numRead)
			fatal("couldn't write to stdout");
		if (write(outFd, buf, numRead) != numRead)
			fatal("couldn't write to output file");
	}


	if (numRead == -1)
		errExit("read");
	

	// close outputfile, flush stdin/stdout
	if (close(STDOUT_FILENO == -1))
		errExit("close stdout");
	if (close(outFd == -1))
		errExit("output file");


	exit(EXIT_SUCCESS);
}
