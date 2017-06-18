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
#include <math.h>


#define bool int
#define true 1
#define false 0

/// Global space
pthread_t tid[2];
int numsToTest[10];
int primesFound[10];
int currentNum = 0;
int currentPrime = 0;

void* doSomeThing(void *arg) {
    while (currentNum < 10) {
        bool isPrime = true;
        int testNum = numsToTest[currentNum];
        printf("\n Job started with %d\n",testNum);
        currentNum++;
        int testRange = (int)ceil(sqrt(testNum));
        printf("test range %d\n",testRange);
        int i;

        for(i = 1; i < testRange; i++) {
            int rem = testNum % i;
            if (rem == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            printf("its prime\n");
            primesFound[currentPrime] = testNum;
            currentPrime++;
        }
    }
    
    printf("\n Job finished\n");

    return NULL;
}

int main() {
    int i = 0;
    int err;

    for (i = 1; i < 11; i++) {
        numsToTest[i-1] = i;
    }

    i = 0;
    while (i < 2) {
        err = pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);
        if (err != 0) {
            printf("\ncan't create thread :[%s]", strerror(err));
        }
        i++;
    }

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);

    for (i = 0; i < 10; i++) {
        printf("%d ",primesFound[i]);
    }
    printf("\n");
    
    return 0;
}
