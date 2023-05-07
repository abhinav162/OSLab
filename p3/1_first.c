#include<unistd.h>
#include<stdio.h>

int main()
{
	char buffer[50];
	int record;
	record=read(0,&buffer,30);
	write(1,&buffer,record);
}
