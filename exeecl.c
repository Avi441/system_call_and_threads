
#include<stdio.h>
#include<unistd.h>
int main()
{
 	printf("Before\n");
	execl("/bin/ls","ls","-1",NULL);
	printf("after");


}

