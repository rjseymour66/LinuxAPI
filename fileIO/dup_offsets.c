#include <sys/types.h>
#include <sys/stat.h>

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include "tlpi_hdr.h"

/*
 * Program that verifies that duplicated file descriptors share 
 * a file offset value and open file status flags               
 */

int
main(void)
{
	int oldfd, newfd, flags, checkFlags;
	mode_t filePerms;
// 	off_t offset;

	flags = O_RDWR | O_CREAT | O_TRUNC;
	filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;	/* rw-rw-rw */


	// create a file descriptor
	oldfd = open("verified", flags, filePerms);
	
	printf("Created oldfile: %d\n", oldfd);
	
	// duplicate the file descriptor
	newfd = dup(oldfd);
	
	printf("Created newfile: %d\n", newfd);
	
	// check the file status flags
	checkFlags = fcntl(newfd, F_GETFL);
	if (checkFlags == flags)
		printf("flags are equal");
	else
		perror("flags not equal");

	exit(EXIT_SUCCESS);
}
