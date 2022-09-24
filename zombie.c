#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>


int main(){


pid_t p;
p = fork();
if(p==0){

	//sleep(2);//here child whent for sleep for while parent proccess first 
	printf("I am child havr PID =%d\n",getpid());
	printf("my parent PID is %d\n", getppid());
}
else{
//wait(NULL);//prevnet process to went to zombie process 
sleep(3);	

printf("I am parent having PID %d\n",getpid());
printf("My child PID is %d \n",p);

}

}
