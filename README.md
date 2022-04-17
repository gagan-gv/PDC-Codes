# PDC-Codes
Parallel and Distributed Computing Codes

To run OpenMP codes (in cmd line)
```
gcc -o <file_name> -fopenmp <file_name>.c
./<file_name>
```

1. [Implement the OpenMP standard includes the following functions and data types using C and include the appropriate declarations of the routines in your source code and explain it.](https://github.com/gagan-gv/PDC-Codes/blob/main/q1.c)
   - omp_destroy_lock 
   - omp_get_dynamic 
   - omp_get_max_threads 
   - omp_get_nested 
   - omp_get_num_procs 
   - omp_get_num_threads 
   - omp_get_thread_num 
   - omp_get_default_device() 
   - omp_get_wtick 
   - omp_get_wtime 
   - omp_in_parallel 
   - omp_init_lock 
   - omp_init_nest_lock 
   - omp_set_dynamic 
   - omp_set_lock 
   - omp_set_nest_lock 
   - omp_set_nested 
   - omp_set_num_threads 
   - omp_test_lock 
   - omp_unset_lock

2. [Using OpenMP, Design, develop and run a multi-threaded program to perform dot product and explain it.](https://github.com/gagan-gv/PDC-Codes/blob/main/q2.c)

3. [Using OpenMP, Design, develop and run a multi-threaded program to perform sum of N elements (N=100) using Loop work Sharing with different schedule clause.](https://github.com/gagan-gv/PDC-Codes/blob/main/q3.c)

4. [Write an OpenMP program to find and sum the Palindromic numbers. Use some of threads to generate the numbers and sum the digits for the up to the 100 elements and other thread print them. Use omp reduction to protect the code region that might be updated by multiple threads concurrently. Measure the execution time for both versions (omp reduction and omp critical) varying the number of threads: 28 and 32.](https://github.com/gagan-gv/PDC-Codes/blob/main/q4.c)

5. [Write a parallel loop that computes the maximum and minimum values in an array using openMP.](https://github.com/gagan-gv/PDC-Codes/blob/main/q5.c)

6. [Using MPI, Design, develop and run Broadcast communication (MPI_Bcast) using MPI_Send and MPI_Recv.](https://github.com/gagan-gv/PDC-Codes/blob/main/q6.c)

7. [Write an MPI program to compute the value of Euler's number or Napier's constant (e = 2.718281828459046). Use a suitable collective communication function in it.](https://github.com/gagan-gv/PDC-Codes/blob/main/q7.c)