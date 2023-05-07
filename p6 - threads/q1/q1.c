// write a program using pthread to concatenate the strings, where multiple strings are passed to thread function

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

void *concatString(void *arg);

int main()
{
    char *m = "5";
    pthread_t a_thread; // thread declaration
    void *result;
    pthread_create(&a_thread, NULL, concatString, m); 
    pthread_join(a_thread, &result); 
    printf("thread returned %s\n", (char *)result);
}

void *concatString(void *arg)
{
    char *str1 = "Hello";
    char *str2 = "World";
    char *str3 = "!";
    char *str4 = malloc(strlen(str1) + strlen(str2) + strlen(str3) + 1);
    strcpy(str4, str1);
    strcat(str4, str2);
    strcat(str4, str3);
    pthread_exit(str4); // Thread returns "Done"
}