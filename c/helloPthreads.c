#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define N 4

void * printHello(void *id) {

    long threadId = (long) id;

    printf("Hello from thread %ld \n", threadId);
    pthread_exit(NULL);
}

int main(){

    pthread_t thread[N];
     long i, isErr;

    for(i=0; i<N; i++){
        isErr = pthread_create(&thread[i], NULL, printHello, (void *) i);
        if(isErr) {
            printf("Error while creating thread %ld - Error code %ld\n", i, isErr);
            exit((int)isErr);
        }
    }
    pthread_exit(NULL);
    return 0;
}
