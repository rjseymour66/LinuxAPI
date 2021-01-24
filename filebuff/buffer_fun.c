#include <stdio.h>
#include <unistd.h>
#include "tlpi_hdr.h"

int
main(void)
{
	printf("To man the world is twofold, ");
	fflush(stdout);
	write(STDOUT_FILENO, "in accordance with his twofold attitude.\n", 41);

	return 0;
}
