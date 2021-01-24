#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "tlpi_hdr.h"

int
main(int argc, char *argv[])
{
	int fd;
	struct stat sb;

	if (argc < 2 || strcmp(argv[1], "--help") == 0)
		usageErr("%s file\n", argv[0]);

	if (stat(argv[1], &sb) == -1)
		errExit("fstat");

	printf("inode:     %ld\n", (long) sb.st_ino);	
	printf("file size: %lld\n", (long long) sb.st_size);	
	printf("User ID:   %ld\n", (long) sb.st_uid);	
	printf("Device ID: %ld\n", (long) sb.st_dev);	

	exit(EXIT_SUCCESS);
}
