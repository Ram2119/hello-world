
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#define PAGE_SIZE 4096

int main(void)
{

	int fd = shm_open("/myShm", O_CREAT|O_RDWR, S_IRWXU);
	if (fd == -1)	 {
		perror("Failed to open shared memory object\n");
		return 0;
	}

	int ret;
	ret = ftruncate(fd, PAGE_SIZE);	
	if (ret == -1)
		perror("Failed to truncate to size\n");	
	else {
		int *p = mmap(NULL, 100, PROT_WRITE|PROT_READ, MAP_SHARED, fd, 4096);
		if (p == (void*)-1)
			perror("Failed to create mapping\n");
		else {
			printf("Mapped BA : %p\n", p);
		
			char *buf = "i am at the edge";
			
			if (0 > write(fd, buf, strlen(buf)+1))
				perror("Failed to write\n");
			else
				printf("write success\n");

			munmap(p, 100);
		}
	}

	return 0;
}

