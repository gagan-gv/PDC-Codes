#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

void broadCast(void *data, int count, MPI_Datatype dt, int root, MPI_Comm c){
    int temp_rank;
    MPI_Comm_rank(c, &temp_rank);
    int temp_size;
    MPI_Comm_size(c, &temp_size);

    if(temp_rank == root){
        for(int ii = 0; ii < temp_size; ii++){
            if(ii != temp_rank){
                MPI_Send(data, count, dt, ii, 0, c);
            }
        }
    }
    else{
        MPI_Recv(data, count, dt, root, 0, c, MPI_STATUS_IGNORE);
    }
}

int main(){

    MPI_Init(NULL, NULL);
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int data;

    if(rank == 0){
        printf("Enter the data in integer form: ");
        scanf("%d", &data);
        printf("Broadcasting data from process 0: %d\n", data);
        broadCast(&data, 1, MPI_INT, 0, MPI_COMM_WORLD);
    }else{
        broadCast(&data, 1, MPI_INT, 0, MPI_COMM_WORLD);
        printf("Process %d receiving data %d\n", rank, data);
    }
    MPI_Finalize();

    return 0;
}
