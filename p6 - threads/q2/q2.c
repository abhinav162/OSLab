#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

void *find_string_length(void *arg);

int main()
{
    char string[100];

    printf("Enter a string: ");
    scanf("%s", string);

    pthread_t tid;
    pthread_create(&tid, NULL, find_string_length, string);

    int *result;
    pthread_join(tid, (void **)&result);

    printf("Length of string: %d\n", *result);

    free(result);

    return 0;
}

void *find_string_length(void *arg)
{
    char *string = (char *)arg;

    int *length = (int *)malloc(sizeof(int));
    *length = strlen(string);

    pthread_exit((void *)length);
}
