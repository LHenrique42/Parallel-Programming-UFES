// Para compilar, você pode usar o seguinte comando (no linux):
// g++ pi.cpp -o pi
// Para executar no cluster: qsub pratica11.sh
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <sys/time.h>

using namespace std;

double MyClock() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000) + tv.tv_usec;
}


int main(int argc, char *argv[]){
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int number;
    if (world_rank == 0) {
        number = -1;
        MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    } else if (world_rank == 1) {
        MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD,
                 MPI_STATUS_IGNORE);
        printf("Process 1 received number %d from process 0\n",
               number);
    }
    return 0;
}
