#include <mqueue.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	mqd_t desc;

	struct mq_attr queueAttr; 
	queueAttr.mq_flags = 0;
	queueAttr.mq_maxmsg = 5;
	queueAttr.mq_msgsize = 5000;

//	mq_unlink("/myQueue");
	desc = mq_open("/myQueue", O_CREAT|O_RDWR, S_IRUSR|S_IWUSR, &queueAttr);
	if (desc == -1) {
		perror("Failed to create queue\n");
		return 0;
	}

	int ret;
	struct mq_attr getAttr;	
	ret = mq_getattr(desc, &getAttr);
	if (ret == -1)
		perror("Failed to get attr\n");	
	
	printf("crMsgs[%ld]\tMaxmsg[%ld]\tMsgsize[%ld]\n", getAttr.mq_curmsgs, getAttr.mq_maxmsg, getAttr.mq_msgsize);

	ret = mq_setattr(desc, &queueAttr, NULL);
	if (ret == -1)
		perror("Failed to set attr\n");

	char buf[100] = {0, };
	printf("Enter i/p\n");	
	if (NULL == fgets(buf, sizeof(buf), stdin))
		perror("Failed to read i/p\n");	
	
	else {
		//ret = mq_send(desc, buf, sizeof(buf), 4);
		struct timespec wait_time;
		wait_time.tv_sec = time(NULL) + 5;	
		wait_time.tv_nsec = 0;	
		ret = mq_timedsend(desc, buf, sizeof(buf), 4, &wait_time);	
		if (ret == -1)
			perror("Failed to send\n");
	
		else
			printf("Send success\n");
	}
	mq_close(desc);

	return 0;
}
