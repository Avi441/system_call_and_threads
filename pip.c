#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>


int main(){
char buffer[50];
int fd[2],n;
pid_t p;
pipe(fd);
p = fork();
if(p>0){
	//parent write to pipe
printf("passing value to child\n");
write(fd[1],"hello\n",6);

}
else{

printf("child received data\n");
n=read(fd[0],buffer,100);
write(1,buffer,n);

}

}
