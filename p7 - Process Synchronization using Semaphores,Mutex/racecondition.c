/*

A race condition is a type of concurrency bug that occurs when two or more processes or threads access shared data and attempt to modify it at the same time. In other words, the outcome of the program depends on the timing or sequence of events, which is unpredictable and can lead to incorrect or unexpected behavior.

Race conditions can occur in operating systems when multiple processes or threads try to access the same resource, such as a file or a network connection, without proper synchronization. For example, if two processes try to write to the same file at the same time, the contents of the file may be corrupted or lost.

To prevent race conditions, operating systems provide synchronization mechanisms, such as locks, semaphores, and monitors, that ensure that only one process or thread can access a shared resource at a time. By using these synchronization primitives correctly, developers can avoid race conditions and ensure the correct behavior of their programs.

*/

#include <stdio.h>
#include <pthread.h>

int counter = 0;

void *increment_counter1(void *arg) {
    for (int i = 0; i < 10000; i++) {
        counter++; // increment counter
    }
    pthread_exit(NULL);
}

void *increment_counter2(void *arg) {
    for (int i = 0; i < 10000; i++) {
        counter++; // increment counter
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;

    // create two threads that call different functions to increment the counter
    pthread_create(&thread1, NULL, increment_counter1, NULL);
    pthread_create(&thread2, NULL, increment_counter2, NULL);

    // wait for the threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // print the final value of the counter
    printf("Counter value: %d\n", counter);

    return 0;
}

/*

In this code, we have two functions increment_counter1() and increment_counter2(), each of which increments the counter variable 10,000 times. The main function creates two threads that call these functions, and then waits for the threads to finish. Finally, it prints the final value of the counter variable.

However, since both threads access the same global variable counter, there is a race condition. The final value of counter may be different from 20000 due to the race condition.

*/