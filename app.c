#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
	int fd;
	char *buffer = (char*)malloc(50);
	if (!buffer) {
		printf("malloc failed!\n");
		return 0;
	}

	fd = open("/dev/mychar", O_RDWR);

	if (fd < 0)
		perror("Unable to open the device ");
	else
		printf("File opened Sucessfully %d\n", fd);
	
	int ch;
	printf("Enter\n1.Read\n2.Write\n");
	scanf("%d", &ch);

	if (ch == 1) {
		read(fd, buffer, 50, NULL);
		printf("##%s\n",buffer);
	}
	else if (ch == 2) {
		strcpy(buffer, "bfverjfb");

		printf("##%s\n",buffer);
		write(fd, buffer, 50, NULL);
	}
	
	close(fd);
	return 0;
}

