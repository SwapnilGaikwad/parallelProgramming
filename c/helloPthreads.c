#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#include<unistd.h>

#define THREAD_COUNT 4
#define TEN_MILLISEC 10000

void * printHello(void *id) {

    long threadId = (long) id;

    // Sleeping for threadId milliseconds
    // To ensure deterministic order of printing the output
    usleep(TEN_MILLISEC * threadId);

    printf("Hello from thread %ld \n", threadId);
    pthread_exit(NULL);
}

int main(){

    pthread_t thread[THREAD_COUNT];
     long i, isErr;

    for(i = 0; i < THREAD_COUNT; i++){
        isErr = pthread_create(&thread[i], NULL, printHello, (void *) i);
        if(isErr) {
            printf("Error while creating thread %ld - Error code %ld\n", i, isErr);
            exit((int)isErr);
        }
    }
    pthread_exit(NULL);
    return 0;
}
