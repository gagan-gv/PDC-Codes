#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#define LENGTH 10
#define numOfThreads 5

void main(){
  printf("Gagan Chordia - 19BCE0788\n");

  int *a, *b;
  a = (int*) malloc(LENGTH * sizeof(int));
  b = (int*) malloc(LENGTH * sizeof(int));

  int prod = 0, threads = numOfThreads;
  int jj, tid;

  for(int ii = 0; ii < LENGTH; ii++){
    a[ii] = (ii + 1);
    b[ii] = (ii + 3);
  }

  #pragma omp parallel private(jj, tid) num_threads(threads)
  {
    tid = omp_get_thread_num();

    #pragma omp for reduction(+: prod)
    for(jj = 0; jj < LENGTH; jj++){
      prod += (a[jj] * b[jj]);
    }
    printf("Thread ID = %d\n", tid);
  }

  printf("Dot Product = %d\n", prod);

  free(a);
  free(b);
}
