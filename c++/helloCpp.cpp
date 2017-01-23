#include<iostream>
#include<pthread.h>
#include<cstdlib>
#include <unistd.h>

#define THREAD_COUNT 4
#define TEN_MILLISEC 10000
using namespace std;

void* printHello(void* threadId) {
    long tid = (long) threadId;
    usleep(TEN_MILLISEC * tid);
    std::cout << "Hello from Thread " << tid << std::endl;
    pthread_exit(NULL);
}

int main() {

    pthread_t threads[THREAD_COUNT];
    int retVal;

    for(long i=0; i < THREAD_COUNT; i++) {
        retVal = pthread_create(&threads[i], NULL, printHello, (void *)i);
        if(retVal != 0) {
            std::cout << "Error while creating a thread. Error - " << retVal << std::endl;
            exit(retVal);
        }
    }
    pthread_exit(NULL);
    return 0;
}
