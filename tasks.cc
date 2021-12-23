#include <cstdlib>
#include <cstring>
#include <mpi.h>
#include <fstream>
#include <iostream>
using namespace std;
#include "tasks.h"

/***
 * Master process. 
 * Reads the text file and sends words to other processes,
 * receives the results, and outputs them.
***/
void Master(int num_proc)
{
    ofstream fout("output.txt");
    MPI_Status status;
    int n, tag = 0, source;
    MPI_Recv(&n, 1, MPI_INT, MPI_ANY_SOURCE, tag, MPI_COMM_WORLD, &status);
    source = status.MPI_SOURCE;
    cout << "Received the value " << n << " from process " << source << endl;

    /* Add your solution here */

}


/***
 * Worker process. 
 * Receives a word from the master process, encrypts
 * it, then sends it back to the master.
***/
void Worker(int my_id, int num_proc)
{
    int n = 4, tag = 0, dest = 0;
    if (my_id == 2)
        MPI_Send(&n, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);
    
    /* Add your solution here */
    
}
