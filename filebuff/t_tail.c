#include <sys/types.h>
#include <sys/stat.h>

#include <fcntl.h>
#include <unistd.h>
#include "tlpi_hdr.h"

#define BUF_SIZE 1024

int
main(int argc, char *argv[])
{
	// var setup
	int fd;
	char *optStr, *buf[BUF_SIZE];
	ssize_t numWritten, numRead;
	off_t offset;

	// check args 
	if (argc < 2 || strcmp(argv[1], "--help") == 0)
		usageErr(argv[0]);

	fd = open(argv[1], O_RDONLY);

	if (fd == -1)
		errExit("open");
	
	// seek to offset 
	offset = -10;
	if (lseek(fd, offset, SEEK_END) == -1)
		errExit("lseek");

	// char *fgets(char *str, int n, FILE *stream)
	


	// read in bytes
	while((numRead = read(fd, buf, BUF_SIZE)) > 0)
		if (write(STDOUT_FILENO, buf, numRead) != numRead)
			errExit("write");

	if (numRead == -1)
		errExit("read");

	if (close(fd) == -1)
		errExit("close");

	exit(EXIT_SUCCESS);

/*
	if (argc == 3) {
		// get opt
		while ((opt = getopt(argc, argv, "n:")) != -1){
			switch(opt){
			case 'n': optStr = optarg;
			break;
			default: fatal("Unexpected case in switch()");
			}
		}
		if (opStr == NULL)
			errExit("getopt()");
		lines = getInt(optStr, GN_GT_0, "getInt");
	} else 
		lines = 10;
*/
}
