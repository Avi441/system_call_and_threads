#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>
#include<unistd.h>
void *fun1();
void *fun2();
int shared = 1;  //shared variable
sem_t s; //semaphore variable

int main(){
sem_init(&s,0,1);

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
	sem_wait(&s); //wait operation on s
	x = shared;
	printf("thread1 reads the valuel as %d\n",x);
	x++;
	printf("local update by thread1 %d\n",x);
	sleep(1);
	shared=x;
	printf("value of shared variable update by threadis %d\n",shared);
sem_post(&s);
}

void *fun2()
{ 
	int y;
	sem_wait(&s); //wait operation on s
	y = shared;
	printf("thread1 reads the valuel as %d\n",y);
	y--;
	printf("local update by thread1 %d\n",y);
	sleep(1);
	shared=y;
	printf("value of shared variable update by threadis %d\n",shared);
sem_post(&s);
}













