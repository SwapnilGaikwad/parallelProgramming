#include<stdio.h>
#include<omp.h>

#define N 4
int main() {

    int i, threadId, threadCount;


    #pragma omp parallel for private (threadId, threadCount) default(none)
    for(i = 0; i < N; i++) {
        threadCount = omp_get_num_threads();
        threadId = omp_get_thread_num();
        printf("Hello from thread %d/%d\n", threadId, threadCount);
    }
    return 0;
}
