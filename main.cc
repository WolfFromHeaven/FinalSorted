#include <iostream>
#include <mpi.h>

#include "Master.h"
#include "Worker.h"

using namespace std;

int main()
{
  MPI::Init();
//  int nodeRank = MPI::COMM_WORLD.Get_rank();
//  int nodeTotal = MPI::COMM_WORLD.Get_size();
  int nodeRank, nodeTotal;
  MPI_Comm_rank(MPI_COMM_WORLD, &nodeRank);
  MPI_Comm_size(MPI_COMM_WORLD, &nodeTotal);
  
  if ( nodeRank == 0 ) {
    Master masterNode( nodeRank, nodeTotal );
    masterNode.run();
  }
  else {
    Worker workerNode( nodeRank );
    workerNode.run();
  }

  MPI::Finalize();
  
  return 0;
}
