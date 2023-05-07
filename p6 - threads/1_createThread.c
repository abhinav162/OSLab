#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *myThreadFun(void *vargs)
{
    printf("\nThread created successfully");
    // pthread_exit("Thread Exit");

    // return integer value from thread
    int *ptr = (int *)malloc(sizeof(int));
    *ptr = 10;
    pthread_exit(ptr);

    // return ptr; // we can use this also instead of pthread_exit(ptr); but we have to typecast the return value to void * and then we have to typecast it to int * in main function
}

int main()
{
    pthread_t thread_1;
    printf("Before Thread Creation");
    pthread_create(&thread_1,NULL,myThreadFun,NULL); // create thread, here first NULL is used because we are not passing any argument to the thread and second NULL is used because we are not returning any value from the thread
    
    // pthread_join(thread_1,NULL);  // this is used to wait for the thread to complete,NULL is used because we are not passing any argument to the thread
    
    void *result;
    pthread_join(thread_1,&result);
    printf("\nAfter Thread Completion");
    // printf("\nThread returned : %d",(int *)result);
    printf("\nThread returned : %d",*((int *)result));
    exit(0);
}