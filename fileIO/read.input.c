#include <sys/types.h>
#include <sys/stat.h>

#include <stdio.h>
#include <unistd.h>
#include "tlpi_hdr.h"

#define	MAX_READ	25

int
main(void) {

	char buffer[MAX_READ + 1];
	ssize_t numRead;

	numRead = read(STDIN_FILENO, buffer, MAX_READ);
	if (numRead == -1)
		errExit("read");

	buffer[numRead] = '\0';
	printf("The input data was: %s\n", buffer);

	return 0;
}
