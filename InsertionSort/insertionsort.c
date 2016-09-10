#include<stdio.h>
#include<stdlib.h>


//declare a function for insertion sort
int * insertsort(int *A,int N){
  int key,i;
  for (size_t j = 1; j < N; j++) {
    key = *(A+j);
    i = j-1;
    while (i>=0 && *(A+i) > key) {//insert key A[i] into the (already sorted) sub-array A[1 .. i-1].  by pairwise key-swaps down to its right position
      *(A+i+1) = *(A+i);
      i--;
    }
    *(A+i+1) = key;//new location of key
  }
  return A;
}

int main(int argc, char const *argv[]) {
  int N;
  scanf("%d",&N );
  int* A = (int*) malloc(sizeof(int)*N);//Allocate memort for array to be inserted
  for (size_t i = 0; i < N; i++) {
    scanf("%d",A+i );
  }
  A = insertsort(A,N);//return pointer to first element of sorted array
  for (size_t i = 0; i < N; i++) {
    printf("%d\n",*(A+i) );
  }
  return 0;
}
