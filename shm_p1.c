#include <stdio.h>
#include <errno.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

int main()
{

    //declaration section

    int *start_addr = NULL;
    int status;
    int fd;

    //creating a shared memory

    fd = shm_open("/raj", (O_CREAT | O_RDWR ), 777);

    if(-1 ==  fd) {
    
        perror("shm open");
    
    }

    //setting the size of shared memory

    status = ftruncate(fd, 4* 1024);

    if(-1 ==  status) {
    
        perror("ftruncate");
    
    }

    //mapping the memory to vas

    start_addr = mmap(NULL, 4 * 1024, (PROT_READ | PROT_WRITE | PROT_EXEC), MAP_SHARED, fd, 0);

    if(start_addr == (void*)-1) {
    
        perror("mmap");

    }


    *(start_addr + 100) = 100;
    
    getchar();
    return 0;

}
