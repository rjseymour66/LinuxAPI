/*
 * Dereferences all symbolic links in pathname and resolves 
 * all references to /. and /.. to provide a null-terminating
 * string containing the absolute pathname
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <linux/limits.h>	/* PATH_MAX */

#include "tlpi_hdr.h"

#define BUF_SIZE PATH_MAX

/*
char *
t_realpath(const char *pathname, char *resolved_path);
*/

int
main(int argc, char **argv)
{
	if (argc < 2 || strcmp(argv[1], "--help") == 0)
		usageErr("%s usage [file]\n", argv[0]);

	char buf[BUF_SIZE];

	if (realpath(argv[1], buf) == NULL)
		errExit("realpath");

	printf("resolved path: %s\n", buf);

	exit(EXIT_SUCCESS);
}


/*
t_realpath(const char *pathname, char *resolved_path) {

}
*/
