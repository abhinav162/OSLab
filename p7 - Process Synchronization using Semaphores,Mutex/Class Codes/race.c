#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *function1();
void *function2();
int var=1;
int main()
{
    pthread_t t1, t2; 
    pthread_create(&t1, NULL, function1, NULL);
    pthread_create(&t2, NULL, function2, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Shared Variable value is %d\n", var);
}

void *function1() 
{
    int x;
    x=var;
    printf("T1 has read value of shared variable as %d\n", x);
    x=x*10;// multiply the local variable by 10
    printf("T1 has updated it's copy of the shared variable to be %d\n", x);
    sleep(1); 
        var = x; // write the value of the local variable to the shared variable
    printf("Value of shared variable updated by T1 is %d\n", var);
}
void *function2()
{
    // read the shared value, store in in a local variable 
    int y;
    y=var;
        printf("T2 has read value of shared variable as %d\n", y);
    y=y-10; // subtract 10 from local variable
    printf("T2 has updated it's copy of the shared variable to be %d\n", y);
    sleep(1);
        var = y; // write the value of the local variable to the shared variable
    printf("Value of shared variable updated by T2 is %d\n", var);
}