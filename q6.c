#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

int main(){
    double procSum = 1.0, nappierConst, value = 1.0;
    int id, procs;

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &procs);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);

    for(int ii = 1; ii < 1001; ii++){
        value /= ii;
        procSum += value;
    }

    MPI_Reduce(&procSum, &nappierConst, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if(id == 0){
        printf("Napier's Constant = %.15f\n", nappierConst);
    }

    MPI_Finalize();

    return 0;
}
