#include "tlpi_hdr.h"

/* NOT IMPLEMENTED */

/* Implement initgroups() using setgroups() and library functions for retrieving
 * information from the password and group files. A process must be privileged 
 * to call setgroups()
 */

int t_initgroups(const char *user, git_t group);

void print_pwd(struct passwd *pwd);

/* Initializes the calling process's group IDs by scanning /etc/group and building
 * a list of all groups that the *user is a member of
 */

int t_initgroups(const char *user, git_t group)
{
	// struct passwd *getpwnam(const char *name);	lots of user info in a struct
	// struct passwd *getpwuid(uid_t uid);		looks up by numeric user id
	// struct passwd *getgrnam(const char *name);	lookup by group name
	// struct passwd *getgruid(gid_t gid);		lookup by group id
	
	gid_t grouplist;
	struct passwd *pwd;
		

	pwd = getpwnam(user);

	if (pwd == NULL)
		errExit("getpwnam");



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

