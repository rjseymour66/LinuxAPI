#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include "tlpi_hdr.h"

int
main(int argc, char *argv[])
{
	if (argc < 2 || strcmp(argv[1], "--help") == 0)
		usageErr("%s usage no file", argv[0]);

	if (access(argv[1], F_OK) == 0)
		printf("File exits.\n");
	else
		printf("File does not exist.\n");

	if (access(argv[1], R_OK) == 0)
		printf("File can be read.\n");
	else
		printf("File cannot be read.\n");

	if (access(argv[1], W_OK) == 0)
		printf("File can be written.\n");
	else
		printf("File cannot be written.\n");

	if (access(argv[1], X_OK) == 0)
		printf("File is an executable.\n");
	else
		printf("File is not an executable.\n");

	exit(EXIT_SUCCESS);
}
