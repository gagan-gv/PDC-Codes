#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define chunk 100
#define n 100

void main(){
    printf("Gagan Chordia --> 19BCE0788\n");

    int nThreads, tID, ii;
    float a[n], b[n], sum = 0.0;

    for(ii = 0; ii < n; ii++){
        a[ii] = ii * 1.5;
    }

    #pragma omp parallel shared(a, b, nThreads) private(tID, ii)
    {
        tID = omp_get_thread_num();
        if(tID == 0){
            nThreads = omp_get_num_threads();
            printf("Number of threads = %d\n", nThreads);
        }

        #pragma omp for schedule(dynamic, chunk)
        for(ii = 0; ii < n; ii++){
            b[ii] = a[ii] + sum;
            sum += a[ii];
            printf("Thread = %d --> b[%d] = %.2f\n", tID, ii, b[ii]);
        }
    }
    printf("Final sum = %.2f\n", sum);
}