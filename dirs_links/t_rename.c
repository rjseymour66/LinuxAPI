#include <stdio.h>
#include <unistd.h>

#include "tlpi_hdr.h"

int
main(int argc, char **argv)
{
	if (argc < 3 || strcmp(argv[1], "--help") == 0)
		usageErr("%s command args\n", argv[0]);

	printf("old file: %s\n", argv[1]);

	if (rename(argv[1], argv[2]) == -1)
		errExit("rename");

	printf("new file: %s\n", argv[2]);

	exit(EXIT_SUCCESS);
}
