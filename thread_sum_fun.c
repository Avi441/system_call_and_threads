#include<stdio.h>
#include<pthread.h>
void * sum(void *num)
{

printf("enter to thread\n");
static int sum_;
int *x = num;
sum_=x[0]+x[1];
printf("sum of=%d",sum_);

pthread_exit(&sum_);

}


int main(){
int num[2]={2,3};
void *total;
pthread_t thread;
pthread_create(&thread,NULL,sum,(void*)num);
pthread_join(thread,&total);
printf("total sum=%d",*(int *) total);



}

