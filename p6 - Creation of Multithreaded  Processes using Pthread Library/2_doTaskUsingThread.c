#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
void *thread_function(void *arg);
int i, n, j;

int main()
{
    char *m = "5";
    pthread_t a_thread; // thread declaration
    void *result;
    pthread_create(&a_thread, NULL, thread_function, m); // thread is created and thread_function is executed by the thread and m is passed as an argument to the thread_function and a_thread is used to store the thread id of the thread created by pthread_create function
    pthread_join(a_thread, &result); // thread is joined with main thread and result is stored in result variable which is of type void * and can store any type of data so we need to typecast it to the required type of data in our case it is char *
    printf("Thread joined\n");
    for (j = 20; j < 25; j++)
    {
        printf("%d\n", j);
        sleep(1);
    }
    printf("thread returned %s\n", (char *)result);
}

void *thread_function(void *arg) // thread_function is executed by the thread created by pthread_create function and arg is the argument passed to the thread_function
{

    int sum = 0;
    n = atoi(arg); // atoi is used to convert string to integer and arg is the string which is passed as an argument to the thread_function

    for (i = 0; i < n; i++)
    {
        printf("%d\n", i);
        sleep(1);
    }
    pthread_exit("Done"); // Thread returns "Done"
}