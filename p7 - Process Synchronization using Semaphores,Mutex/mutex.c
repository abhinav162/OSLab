/*

A mutex (short for "mutual exclusion") is a synchronization primitive used to protect shared resources from concurrent access in a multi-threaded environment. A mutex provides a way to ensure that only one thread can access a shared resource at any given time.

A mutex typically has two operations: lock() and unlock(). When a thread needs to access a shared resource, it first tries to acquire the mutex by calling lock(). If the mutex is available, the thread acquires it and can proceed to access the shared resource. If the mutex is already held by another thread, the lock() call will block until the mutex is released by the other thread.

Once a thread has finished accessing the shared resource, it must release the mutex by calling unlock(), which allows other threads to acquire the mutex and access the shared resource.

Using a mutex can help prevent race conditions and ensure that shared resources are accessed in a mutually exclusive manner, preventing conflicts between threads. However, it's important to use mutexes carefully to avoid deadlocks and other synchronization issues.

*/

#include <stdio.h>
#include <pthread.h>

int counter = 0;
pthread_mutex_t mutex;

void *increment_counter1(void *arg) {
    for (int i = 0; i < 10000; i++) {
        pthread_mutex_lock(&mutex); // acquire the lock
        counter++; // increment counter
        pthread_mutex_unlock(&mutex); // release the lock
    }
    pthread_exit(NULL);
}

void *increment_counter2(void *arg) {
    for (int i = 0; i < 10000; i++) {
        pthread_mutex_lock(&mutex); // acquire the lock
        counter++; // increment counter
        pthread_mutex_unlock(&mutex); // release the lock
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;

    // initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // create two threads that call different functions to increment the counter
    pthread_create(&thread1, NULL, increment_counter1, NULL);
    pthread_create(&thread2, NULL, increment_counter2, NULL);

    // wait for the threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // destroy the mutex
    pthread_mutex_destroy(&mutex);

    // print the final value of the counter
    printf("Counter value: %d\n", counter);

    return 0;
}


/*

In this modified code, we added a mutex variable mutex and initialized it using pthread_mutex_init(). In both increment_counter1() and increment_counter2() functions, we use pthread_mutex_lock() to acquire the lock before accessing the counter variable, and pthread_mutex_unlock() to release the lock after incrementing the counter variable.

With this modification, we can ensure that only one thread can access the counter variable at a time, avoiding the race condition. When we run this code

*/