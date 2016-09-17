#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void bubblesort(int A[],int N){
  for (size_t i = 0; i < N; i++) {
    for (size_t j = N; j > i; j--) {
      if (A[j] < A[j-1]) {
        int temp;
        temp = A[j];
        A[j] = A[j-1];
        A[j-1] = temp;
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  int N;
  scanf("%d",&N );
  int A[N];
  for (size_t i = 0; i < N; i++) {
    scanf("%d",A+i );
  }
  bubblesort(A,N);
  for (size_t i = 0; i < N; i++) {
    printf("%d\n",A[i] );
  }
  return 0;
}
