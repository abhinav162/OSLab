#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

int main()
{
    int shmid;
    char buffer[50];
    void *shared_memory;

    shmid = shmget((key_t)121,1024,0777); // IPC_CREAT flag is not used here as shared memory is already created by sender
    printf("Shared memory created with id : %d\n",shmid);

    shared_memory = shmat(shmid,NULL,0);
    printf("Shared memory attached at address : %p\n",shared_memory);

    printf("Reading data : \n");
    printf("Data read from shared memory : %s\n",(char *)shared_memory);
}