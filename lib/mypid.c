#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv) {
	
	pid_t mypid;

	mypid = getpid();
	printf("My PID is %ld\n", (long) mypid);

	return 0;
}
