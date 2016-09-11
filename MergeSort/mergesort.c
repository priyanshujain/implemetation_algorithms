// Recusive approach for merge sort from CLRS


#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


void merge(int A[],int p, int q, int r){
  int n1 = q-p+1;
  int n2 = r-q;
  int L[n1+1], R[n2+1];
  for (size_t i = 0; i < n1; i++) {
    L[i] = A[p+i];
  }
  for (size_t j = 0; j < n2; j++) {
    R[j] = A[q+j+1];
  }
  L[n1] = INT_MAX;
  R[n2] = INT_MAX;
  int i=0,j=0;
  for (size_t k = p; k <= r; k++) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    }else{
      A[k] = R[j];
      j++;
    }
  }
}

void mergesort(int A[],int p, int r){
  if (p < r) {
    int q = (p+r)/2;
    mergesort(A,p,q);
    mergesort(A,q+1,r);
    merge(A,p,q,r);
  }

}

int main(int argc, char const *argv[]) {
  int N;
  scanf("%d",&N );
  int A[N];
  for (size_t i = 0; i < N; i++) {
    scanf("%d",A+i );
  }


  mergesort(A,0,N-1);
  for (size_t i = 0; i < N; i++) {
    printf("%d\n",A[i] );
  }
  return 0;
}
