#include <sys/types.h>
#include <pwd.h>
#include <string.h>
#include <stdio.h>

#include "tlpi_hdr.h"

/* Implement getpwnam() using setpwent(), getpwent(), and endpwent() */

struct passwd *t_getpwnam(const char *name);
void print_pwd(struct passwd *pwd);

int
main(int argc, char **argv)
{
	if (argc < 2 || (strcmp(argv[1], "--help")) == 0) 
		usageErr("%s username\n", argv[0]);

	struct passwd *pwd;
	pwd = t_getpwnam(argv[1]);

	if (pwd != NULL)
		print_pwd(pwd);
	
	/*
	print_pwd(t_getpwnam(argv[1]));
	*/

	exit(EXIT_SUCCESS);
}

/* Returns a pointer to a structure on success, NULL on error */

struct passwd *
t_getpwnam(const char *name)
{
	struct passwd *pwd, *result;

	result == NULL;

	if (name == NULL || *name == '\0')
		return -1;

	setpwent();

	while ((pwd = getpwent()) != NULL) 
		if (strcmp(name, pwd->pw_name) == 0) 
			return pwd;

	endpwent();

	return NULL;
}

void print_pwd(struct passwd *pwd) {
	printf("struct passwd {\n");
	printf("    pw_name: %s\n", pwd->pw_name);
	printf("    pw_passwd: %s\n", pwd->pw_passwd);
	printf("    pw_uid: %d\n", pwd->pw_uid);
	printf("    pw_gid: %d\n", pwd->pw_gid);
	printf("    pw_gecos: %s\n", pwd->pw_gecos);
	printf("    pw_dir: %s\n", pwd->pw_dir);
	printf("    pw_shell: %s\n", pwd->pw_shell);
	printf("}\n");
}
