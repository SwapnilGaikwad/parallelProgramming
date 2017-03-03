#include <stdio.h>
#include <omp.h>

int main(){
  #pragma omp parallel
  {
    #pragma omp sections
    {
      #pragma omp section
      {
          printf("This is section 1 executed by thread %d/%d\n", omp_get_thread_num(), omp_get_num_threads());
      }

      #pragma omp section
      {
          printf("This is section 2 executed by thread %d/%d\n", omp_get_thread_num(), omp_get_num_threads());
      }

      #pragma omp section
      {
          printf("This is section 3 executed by thread %d/%d\n", omp_get_thread_num(), omp_get_num_threads());
      }
      #pragma omp section
      {
          printf("This is section 4 executed by thread %d/%d\n", omp_get_thread_num(), omp_get_num_threads());
      }
    }
  }
  return 0;
}
