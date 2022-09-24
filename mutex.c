#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>
#include<unistd.h>
void *fun1();
void *fun2();
int shared = 1;  //shared variable
pthread_mutex_t m; //mutex loca declear
int main(){
pthread_mutex_init(&m,NULL);//mutex lock initial 
pthread_t thread1,thread2;
pthread_create(&thread1, NULL, fun1,NULL);
pthread_create(&thread2,NULL,fun2,NULL);
pthread_join(thread1,NULL);
pthread_join(thread2,NULL);
printf("final value of shared variable is =%d",shared);

return 0;
}

void *fun1()
{ 
	int x;
	printf("thread1 tring acqure  locki\n");

	pthread_mutex_lock(&m);
	printf("thread1 acqured loack\n");
	x = shared;
	printf("thread1 reads the valuel as %d\n",x);
	x++;
	printf("local update by thread1 %d\n",x);
	sleep(1);
	shared=x;
	printf("value of shared variable update by threadis %d\n",shared);
        pthread_mutex_unlock(&m);
}

void *fun2()
{ 
	int y;
	printf("thread2 trying to acquire  lock\n");
	pthread_mutex_lock(&m);
	printf("thread2 acquired lock\n");
	y = shared;
	printf("thread2 reads the valuel as %d\n",y);
	y--;
	printf("local update by thread2 %d\n",y);
	sleep(1);
	shared=y;
	printf("value of shared variable update by threadis %d\n",shared);
        pthread_mutex_unlock(&m);
}













