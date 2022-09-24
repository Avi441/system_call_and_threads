#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
int n, fd, fd1;
char buf[69];
fd=open("test.txt",O_RDONLY);
n =read(fd,buf,10);
fd1=open("testt.txt",O_CREAT|O_WRONLY,0777);
write(fd1,buf,n);







}

