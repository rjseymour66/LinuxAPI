#include <stdlib.h>

void myunsetenv(const char *name);
void mysetenv(const char *name, const char *value, int overwrite);

void usageErr(const char *progName);
void errExit(const char *msg);

int
main(int argc, char **argv)
{
	
	exit(EXIT_SUCCESS);
}

void mysetenv(const char *name, const char *value, int overwrite)
{
	char *es;

	if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL ||
			value == NULL) {
		errno = EINVAL;
		return -1;
	}

	if (getenv(name) != NULL && overwrite == 0)
		return 0;

	myunsetenv(name);	/* REmove all occurrences */

	es = malloc(strlen(name) + strlen(value) + 2);
					/* +2 for '=' and null terminator */

	if (es == NULL)
		return -1;

	strcpy(es, name);
	strcat(es, "=");
	strcat(es, value);

	return (putenv(es) != 0) ? -1 : 0;
}

void myunsetenv(const char *name)
{
	extern char **environ;
	char **ep, **sp;
	size_t len;

	if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL) {
		errno = EINVAL;
		return -1;
	}

	len = strlen(name);

	for (ep = environ; *ep != NULL; )
		if (strncmp(*ep, name, len) == 0 && (*ep)[len] == '=') {
			/* Remove found entry by shifting all successive entries
			 * back one element */

			for (sp = ep); *sp != NULL; sp++)
				*sp = *(sp + 1);

			/* Continue around the loop to further instances of 'name' */
		} else {
			ep++;
		}
	return 0;
}

void usageErr(const char *progName)
{
	fprintf(stderr, "Usage: %s\n", progName);
	fflush(stderr);
	exit(EXIT_FAILURE);
}

void errExit(const char *msg)
{
	perror(msg);
	fflush(stderr);
	exit(EXIT_FAILURE);
}
