#include <stdio.h>
#include <omp.h>

int sum(const int *arr, int size){
  int half, x, y;

  if(size == 0){
    return 0;
  } else if (size == 1) {
    return *arr;
  }

  half = size / 2;
 
  #pragma omp parallel
  #pragma omp single nowait
  { 
    #pragma omp task shared(x)
    x = sum(arr, half);
    #pragma omp task shared(y)
    y = sum(arr + half, size - half);
    #pragma omp taskwait
    x += y;
  }
  return x;
}

int main(){
  const int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  printf("Sum is: %d\n", sum(arr, 10));
  return 0;
}
