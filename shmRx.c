
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

int main(void)
{
	int fd = shm_open("/myShm", O_CREAT|O_RDWR, S_IRWXU);
	if (fd == -1)	 {
		perror("Failed to open shared memory object\n");
		return 0;
	}

	int *p = mmap(NULL, 100, PROT_WRITE|PROT_READ, MAP_SHARED, fd, 4096);
	if (p == ((void*)-1))
		perror("Failed to create mapping\n");

	else {
		printf("Mapped BA : %p\n", p);
		char buf[50] = {0, };
			
		if (0 > read(fd, buf, sizeof(buf)))
			perror("Failed to read\n");
		else
			printf("Read : %s\n", buf);

		munmap(p, 100);
	}

	return 0;
}

