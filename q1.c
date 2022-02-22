#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<unistd.h> //instead use #include<windows.h> if you are using windows

void main(){
    int x = 0, y = 10;

    double start = omp_get_wtime();
    sleep(1);

    printf("Gagan Chordia - 19BCE0788\n");

    omp_set_dynamic(6);
    omp_set_num_threads(5);
    omp_set_nested(10);
    printf("Number of Threads = %d\n", omp_get_num_threads());
    printf("Dynmaic Threads = %d\n", omp_get_dynamic());
    printf("Number of processors = %d\n", omp_get_num_procs());
    printf("Nested = %d\n", omp_get_nested());
    printf("Max Threads = %d\n", omp_get_max_threads());

    double end = omp_get_wtime();
    double tick = omp_get_wtick();

    printf("Start = %g\nEnd = %g\nWTick = %g\n", start, end, tick);

    omp_lock_t writeLock;
    omp_init_lock(&writeLock);

    omp_nest_lock_t nest;
    omp_init_nest_lock(&nest);

    #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        printf("Number of Threads = %d\n", omp_get_num_threads());
        
        printf("Default Device = %d\n", omp_get_default_device());
        
        printf("%d\n", omp_test_lock(&writeLock));
        omp_unset_lock(&writeLock);
        omp_set_lock(&writeLock);
        x += 1;
        omp_unset_lock(&writeLock);

        omp_set_nest_lock(&nest);
        y *= 2;
        omp_unset_nest_lock(&nest);

        printf("Parallel Threads = %d\n", omp_in_parallel());
    }

    printf("X = %d\n", x);
    printf("Y = %d\n", y);

    omp_destroy_lock(&writeLock);
    omp_destroy_nest_lock(&nest);
}
