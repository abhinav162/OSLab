/*
A semaphore is a synchronization primitive that can be used to protect shared resources from concurrent access in a multi-threaded environment. Semaphores were first introduced by Edsger Dijkstra in 1962.

A semaphore typically has two operations: wait() and signal(). When a thread needs to access a shared resource, it first tries to acquire the semaphore by calling wait(). If the semaphore is available, the thread acquires it and can proceed to access the shared resource. If the semaphore is already held by another thread, the wait() call will block until the semaphore is released by the other thread.

Once a thread has finished accessing the shared resource, it must release the semaphore by calling signal(), which allows other threads to acquire the semaphore and access the shared resource.

A binary semaphore is a special case of a semaphore that only has two states: available and unavailable. This makes it functionally similar to a mutex. However, unlike a mutex, a binary semaphore can be released by any thread, not just the one that acquired it.

Semaphores are a powerful tool for concurrent programming, as they allow for more fine-grained control over access to shared resources than mutexes. However, it's important to use semaphores carefully to avoid deadlocks and other synchronization issues.
*/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int counter = 0;
sem_t semaphore;

void *increment_counter1(void *arg) {
    for (int i = 0; i < 10000; i++) {
        sem_wait(&semaphore); // wait for semaphore
        counter++; // increment counter
        sem_post(&semaphore); // signal semaphore
    }
    pthread_exit(NULL);
}

void *increment_counter2(void *arg) {
    for (int i = 0; i < 10000; i++) {
        sem_wait(&semaphore); // wait for semaphore
        counter++; // increment counter
        sem_post(&semaphore); // signal semaphore
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;

    // initialize the semaphore
    sem_init(&semaphore, 0, 1);

    // create two threads that call different functions to increment the counter
    pthread_create(&thread1, NULL, increment_counter1, NULL);
    pthread_create(&thread2, NULL, increment_counter2, NULL);

    // wait for the threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // destroy the semaphore
    sem_destroy(&semaphore);

    // print the final value of the counter
    printf("Counter value: %d\n", counter);

    return 0;
}


/*

In this modified code, we replaced the mutex variable with a semaphore variable semaphore, initialized it using sem_init(), and used sem_wait() to wait for the semaphore and sem_post() to signal the semaphore in both increment_counter1() and increment_counter2() functions.

Like a mutex, a semaphore is a synchronization primitive used to protect shared resources from concurrent access in a multi-threaded environment. However, semaphores are more flexible than mutexes, as they can allow multiple threads to access a shared resource simultaneously (up to a certain limit), while mutexes only allow one thread at a time. In this case, we initialize the semaphore with a value of 1, which effectively turns it into a mutex.

With this modification, we can ensure that only one thread can access the counter variable at a time, avoiding the race condition. When we run this code, we should see the correct final value of counter.
*/