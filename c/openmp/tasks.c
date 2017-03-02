#include <stdio.h>
#include <omp.h>

int sum(const int *arr, int size){
  int half;

  if(size == 0){
    return 0;
  } else if (size == 1) {
    return *arr;
  }

  half = size / 2;
  return sum(arr, half) + sum(arr + half, size - half);
}

int main(){
  const int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  printf("Sum is: %d\n", sum(arr, 10));
  return 0;
}
