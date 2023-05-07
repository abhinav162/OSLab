// WAP to create two threads, one will check weather the number is armstrong or not and other will print prime number.

#include <stdio.h>
#include <pthread.h>
#include <math.h>

void *checkArmstrong(void *vargp);
void *printPrimeNumber(void *vargp);

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    pthread_t thread_id[2];

    pthread_create(&thread_id[0], NULL, checkArmstrong, &n);
    pthread_create(&thread_id[1], NULL, printPrimeNumber, &n);

    pthread_join(thread_id[0], NULL);
    pthread_join(thread_id[1], NULL);

    return 0;
}

void *checkArmstrong(void *vargp)
{
    int num, originalNum, r, n = 0, res = 0;
    num = *(int *)vargp;
    originalNum = num;

    while (originalNum != 0)
    {
        originalNum /= 10;
        ++n;
    }

    originalNum = num;
    while (originalNum != 0)
    {
        r = originalNum % 10;
        res += pow(r, n);
        originalNum /= 10;
    }

    if (res == num)
        printf("%d is an Armstrong number.\n", num);
    else
        printf("%d is not an Armstrong number.\n", num);

    pthread_exit(NULL);
}


void *printPrimeNumber(void *vargp)
{
    int i, j, flag, n = *(int *)vargp;

    for (i = 2; i < n; i++)
    {
        flag = 1; 
        for (j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                flag = 0;
                break;
            }
        }

        if (flag == 1)
            printf("%d ", i);
    }

    pthread_exit(NULL);
}