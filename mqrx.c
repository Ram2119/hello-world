#include <mqueue.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>

void notifyFun(union sigval val)
{
	printf("Notify\n");	
	printf(": %s\n", (char*)(val.sival_ptr));
}


int main(void)
{
	mqd_t desc;
	desc = mq_open("/myQueue", O_CREAT|O_RDWR);
	if (desc == -1) {
		perror("Failed to create queue\n");
		return 0;
	}
	
	struct sigevent noti;
	noti.sigev_notify = SIGEV_THREAD;
	noti.sigev_value.sival_ptr = "New message";
	noti.sigev_notify_function = notifyFun;
	
	int ret = mq_notify(desc, &noti);
	if (ret == -1)
		perror("Failed to reg noti\n");


	char buf[100] = {0, };
	int prio;
	ret = mq_receive(desc, buf, 8192, &prio);
	if (ret == -1)
		perror("Failed to send\n");
	else {
		printf("Rx data [%d]\n%s\n", prio, buf);
	}

	mq_close(desc);

	return 0;
}
