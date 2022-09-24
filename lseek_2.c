// this program to read  from 5th  to 2oth chareter from one file to other file 


#include<unistd.h>

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>


int main(){

	int n, fd,fd1;
	char buffer[10];
	fd=open("test.txt",O_RDONLY);
	fd1=open("test1.txt",O_WRONLY);
	lseek(fd,15,SEEK_SET);
     n =read(fd,buffer,6);
	write(fd1,buffer,n);
}







