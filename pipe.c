#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int main(void)
{
	int pipefd[2];

	int ret = pipe(pipefd);
	if (ret == -1) {
		perror("Failed to create pipe\n");
		return 0;
	}

//	close(pipefd[1]);
	pid_t pid = fork();
	if (pid > 0) {
		close(pipefd[1]);
		
		char buf[100] = {0, };
		if (read(pipefd[0], buf, sizeof(buf)) <= 0)
			perror("read failed\n");
		else
			printf("Received : %s\n", buf);
	}
	else if (pid == 0) {
		close(pipefd[0]);
		char buf[100] = {0, };
		printf("Enter message to send\n");		

		if (NULL == fgets(buf, sizeof(buf), stdin)) 
			perror("failed to read i/p\n");
		else {
			ret = write(pipefd[1], buf, strlen(buf)+1);
			if (ret == -1)
				perror("Failed to write to pipe\n");	
		}
	}
	else
		perror("fork failed\n");

	return 0;
}
