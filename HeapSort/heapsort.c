
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int PARENT(int i){
  return i/2;
}
int LEFT(int i){
  return 2*i;
}
int RIGHT(int i){
  return (2*i+1);
}

void MAX_HEAPIFY(int A[], int i,int N){//O(log n)
  int l = LEFT(i);
  int r = RIGHT(i);
  int largest;
  if (l<= N && A[l] > A[i]) {
    largest = l;
  }else{
    largest = i;
  }
  if (r <= N && A[r] > A[largest]) {
    largest = r;
  }
  if (largest != i) {
    int temp;
    temp = A[largest];
    A[largest] = A[i];
    A[i] = temp;
    MAX_HEAPIFY(A,largest,N);
  }
}

void BUILD_MAX_HEAP(int A[],int N){//O(n)
  for (size_t i = N/2; i > 0; i--) {
    MAX_HEAPIFY(A,i,N);
  }
}

void HEAPSORT(int A[],int N){//O(n log n)
  BUILD_MAX_HEAP(A,N);
  for (size_t i = N; i > 1; i--) {
    int temp;
    temp = A[1];
    A[1] = A[i];
    A[i] = temp;
    N--;
    MAX_HEAPIFY(A,1,N);
  }
}

int main(int argc, char const *argv[]) {
  int N;
  scanf("%d",&N );
  int A[N+1];
  for (size_t i = 1; i <= N; i++) {
    scanf("%d",A+i );
  }


  HEAPSORT(A,N);
  for (size_t i = 1; i <= N; i++) {
    printf("%d\n",A[i] );
  }
  return 0;
}
