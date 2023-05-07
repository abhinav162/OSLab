#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ARRAY_SIZE 10

int unsorted_array[ARRAY_SIZE] = {4, 3, 6, 7, 2, 1, 5, 10, 9, 8};
int sorted_array[ARRAY_SIZE];

struct thread_args
{
    int *array;
    int start;
    int end;
};

void *sort_array(void *arg);
void *merge_sorted_arrays(void *arg);

int main()
{
    pthread_t tid[3];
    struct thread_args args[2];

    args[0].array = unsorted_array;
    args[0].start = 0;
    args[0].end = ARRAY_SIZE / 2 - 1;

    args[1].array = unsorted_array;
    args[1].start = ARRAY_SIZE / 2;
    args[1].end = ARRAY_SIZE - 1;

    pthread_create(&tid[0], NULL, sort_array, &args[0]);
    pthread_create(&tid[1], NULL, sort_array, &args[1]);

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);

    struct thread_args merge_args = {sorted_array, 0, ARRAY_SIZE - 1};

    pthread_create(&tid[2], NULL, merge_sorted_arrays, &merge_args);

    pthread_join(tid[2], NULL);

    printf("Sorted array:\n");
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%d ", sorted_array[i]);
    }
    printf("\n");

    return 0;
}

void *sort_array(void *arg)
{
    struct thread_args *args = (struct thread_args *)arg;
    int *array = args->array;
    int start = args->start;
    int end = args->end;

    for (int i = start; i <= end; i++)
    {
        for (int j = i + 1; j <= end; j++)
        {
            if (array[j] < array[i])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    pthread_exit(NULL);
}

void *merge_sorted_arrays(void *arg)
{
    struct thread_args *args = (struct thread_args *)arg;
    int *array = args->array;
    int start = args->start;
    int end = args->end;

    int mid = (start + end) / 2;
    int i = start, j = mid + 1, k = 0;

    while (i <= mid && j <= end)
    {
        if (array[i] < array[j])
        {
            sorted_array[k++] = array[i++];
        }
        else
        {
            sorted_array[k++] = array[j++];
        }
    }

    while (i <= mid)
    {
        sorted_array[k++] = array[i++];
    }

    while (j <= end)
    {
        sorted_array[k++] = array[j++];
    }

    pthread_exit(NULL);
}
