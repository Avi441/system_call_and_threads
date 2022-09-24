#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>


int main(){

	int n, fd;
	char buffer[10];
	fd=open("test.txt",O_RDONLY);
	lseek(fd,-6,SEEK_END);
     n =read(fd,buffer,5);
	write(1,buffer,n);
}







