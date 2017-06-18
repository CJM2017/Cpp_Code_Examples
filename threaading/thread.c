// 
//  Project : Managing Threads in C 
//  Author  : Connor McCann 
//  Date    : 17 Jun 2017
//  Source  : http://ashishagarwal.org/2011/02/13/multicore-programming-with-pthreads/
//
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>


// Global space
pthread_t tid[2];
int counter;

void* doSomeThing(void *arg) {
    unsigned long i = 0;
    counter += 1;
    printf("\n Job %d started\n", counter);

    for(i=0; i<(0xFFFFFFFF);i++);
    printf("\n Job %d finished\n", counter);

    return NULL;
}

int main() {
    int i = 0;
    int err;

    while (i < 2) {
        err = pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);
        if (err != 0) {
            printf("\ncan't create thread :[%s]", strerror(err));
        }
        i++;
    }

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    
    return 0;
}

/*
    The actual problem was the usage of the variable ‘counter’ 
    by second thread when the first thread was using or about to 
    use it. In other words we can say that lack of synchronization 
    between the threads while using the shared resource ‘counter’ 
    caused the problems or in one word we can say that this problem 
    happened due to ‘Synchronization problem’ between two threads.
*/

