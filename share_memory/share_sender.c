#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>
int main()

{
	void*share_memory;
	char buffer[100];
	int shmid;
	shmid = shmget((key_t)11,1024,0666 |IPC_CREAT);
	printf("key of share memory is %d \n",shmid);
	share_memory = shmat(shmid,NULL,0);
	printf("process atteched at %p\n",share_memory);
	printf("Enter some data to write to share memory\n");
	read(0,buffer,100);
	strcpy(share_memory,buffer);
	printf("YOu wrote :%s \n",(char*) share_memory);


}
