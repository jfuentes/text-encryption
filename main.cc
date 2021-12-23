#include <mpi.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <unistd.h>
using namespace std;

#include "tasks.h"

int main(int argc, char **argv)
{
    double time;
    int my_id, num_proc;
    
    /* Initialize MPI */
    MPI_Init (&argc, &argv);
    
    /* Get the rank of this process */
    MPI_Comm_rank (MPI_COMM_WORLD, &my_id);
    
    /* Get nb of processes */
    MPI_Comm_size (MPI_COMM_WORLD, &num_proc);
    
    time = MPI_Wtime();

    if (my_id == 0)
        Master(num_proc);
    else
        Worker(my_id, num_proc);

    time = MPI_Wtime() - time;
    
    if (my_id == 0) 
        cout << "Program has run on " << num_proc << " processes in " << time << " seconds." << endl;
    
    /* Finalize MPI */
    MPI_Finalize ();
    return 0;
}

