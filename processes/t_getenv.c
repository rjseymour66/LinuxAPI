#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void usageErr(const char *progName);

int
main(int argc, char **argv)
{
	if (argc != 2 || (strcmp(argv[1], "--help") == 0))
		usageErr(argv[0]);

	char *env;
	env = NULL;

	env = getenv(argv[1]);

	if (env != NULL)
		printf("%s\n", env);
	else {
		perror("No matching env var");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}

void usageErr(const char *progName) {
	fprintf(stderr, "Usage: %s incorrect number of args\n", progName);
	fflush(stderr);

	exit(EXIT_FAILURE);
}
