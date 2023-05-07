#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_VALUES 10

struct thread_args
{
    int *values;
    int num_values;
};

void *calculate_average(void *arg);
void *calculate_maximum(void *arg);
void *calculate_minimum(void *arg);

int main()
{
    int values[NUM_VALUES];

    printf("Enter %d values:\n", NUM_VALUES);
    for (int i = 0; i < NUM_VALUES; i++)
    {
        scanf("%d", &values[i]);
    }

    struct thread_args args = {values, NUM_VALUES};

    pthread_t tid[3];
    pthread_create(&tid[0], NULL, calculate_average, &args);
    pthread_create(&tid[1], NULL, calculate_maximum, &args);
    pthread_create(&tid[2], NULL, calculate_minimum, &args);

    double *average;
    int *maximum;
    int *minimum;

    pthread_join(tid[0], (void **)&average);
    pthread_join(tid[1], (void **)&maximum);
    pthread_join(tid[2], (void **)&minimum);

    printf("Average: %f\n", *average);
    printf("Maximum: %d\n", *maximum);
    printf("Minimum: %d\n", *minimum);

    free(average);
    free(maximum);
    free(minimum);

    return 0;
}

void *calculate_average(void *arg)
{
    struct thread_args *args = (struct thread_args *)arg;
    int *values = args->values;
    int num_values = args->num_values;

    double *average = (double *)malloc(sizeof(double));

    double sum = 0.0;
    for (int i = 0; i < num_values; i++)
    {
        sum += values[i];
    }

    *average = sum / num_values;

    pthread_exit((void *)average);
}

void *calculate_maximum(void *arg)
{
    struct thread_args *args = (struct thread_args *)arg;
    int *values = args->values;
    int num_values = args->num_values;

    int *maximum = (int *)malloc(sizeof(int));
    *maximum = values[0];

    for (int i = 1; i < num_values; i++)
    {
        if (values[i] > *maximum)
        {
            *maximum = values[i];
        }
    }

    pthread_exit((void *)maximum);
}

void *calculate_minimum(void *arg)
{
    struct thread_args *args = (struct thread_args *)arg;
    int *values = args->values;
    int num_values = args->num_values;

    int *minimum = (int *)malloc(sizeof(int));
    *minimum = values[0];

    for (int i = 1; i < num_values; i++)
    {
        if (values[i] < *minimum)
        {
            *minimum = values[i];
        }
    }

    pthread_exit((void *)minimum);
}
