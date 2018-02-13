#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#if 0
int main(void)
{
	FILE* fptr = NULL;
	fptr = fopen("./test.txt", "rb");
	if (!fptr) {
		perror("open failed\n\n");
		return 0;
	}
	
	printf("open success\n");

	char buf[] = "global edge software ltd. Bangalore";
	
//	fwrite(buf, sizeof(buf), 1, fptr);
	
		rewind(fptr);
		char buff[100] = {0, };
		if (0 > fread(buff, sizeof(char), strlen(buff), fptr))
			perror("Failed to read from file\n");	
		perror("read\n");
		printf("\n%s\n", buff);
/*	
	int pid = fork();
	if (pid > 0) {
		memset(buf, 0, sizeof(buf));

		if (0 > read(fd, buf, sizeof(buf)))
			perror("Failed to read from file\n");	
		
		perror("read from file\n");	
		printf("\n%s\n", buf);
	}
	else if (pid == 0) {
		printf("child\n");
	}
	else
		perror("fork failed\n");		
*/
	fclose(fptr);	
	return 0;
}
#endif



#if 0
int main(void)
{
	pid_t (*p)();

	p = fork;

	pid_t ret = (*p)();

	if (ret == 0) {
		printf("parent [%d]\n", getpid());
		wait(NULL);
		printf("Exit parent\n");
	}
	else if (ret > 0) {
		printf("Child [%d]\n", getpid());
		sleep(10);
		printf("child woke up..\n");
	}
	else {
		printf("Fork failed!\n");
	}

	return 0;
}
#endif



#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main ()
{
	pid_t child_pid;
	/* Create a child process. */
	child_pid = fork ();
	if (child_pid > 0) {
		/* This is the parent process. Sleep for a minute. */
		sleep (60);
	}
	else {
		/* This is the child process. Exit immediately. */
		exit (0);
	}
	return 0;
}
