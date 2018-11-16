#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mpi.h"
#include <time.h>


double getRandom()
{
  return (double)rand() / (double)RAND_MAX;
}

int main(int argc, char *argv[])
{

  
  int true = 1; /* to force the loop */
  int n,        /* number of intervals */
      rank,     /* rank of the MPI process */
      size,     /* number of processes */
      i,        /* variable for the loop */
      len;      /* name of the process */
  double INTEGRAL_VAL = 155.0 / 6.0;
  /* reference value of pi */
  double mypi, /* value for each process */
      pi,      /* value of pi calculated */
      h,
      sum, /*sum of the area */
      x;
  double start_time, /* starting time */
      end_time,      /* ending time */
      /* time for computing value of pi */
      computation_time;
  char name[80]; /* char array for storing the name of
the node where is located the
process */
  /*Initialization */
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  /* We ask for the name of the node */
  MPI_Get_processor_name(name, &len);

  srand(time(NULL) + rank);

  if (rank == 0)
  {
    n = atoi(argv[1]);
  }
  /* We are broadcasting to everybody the number of interval */
  MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

  int myPoints = n / size;
  

  sum = 0.0;
  for (i = 0; i < myPoints; i += 1)
  {
    
    double x1 = getRandom();
    double x2 = getRandom();
    double x3 = getRandom();
    double x4 = getRandom();
    double x5 = getRandom();
    double x6 = getRandom();
    double x7 = getRandom();
    double x8 = getRandom();
    double x9 = getRandom();
    double x10 = getRandom();

    sum += (x1+x2+x3+x4+x5+x6+x7+x8+x9+x10)*(x1+x2+x3+x4+x5+x6+x7+x8+x9+x10);
  }
  mypi = sum;

  // printf("This is my sum: %.16f from rank: %d in: %s\n", mypi,
  //        rank, name);
  MPI_Reduce(&mypi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
  if (rank == 0)
  {
    printf("%d %.16f\n",n,
           pi/n );
    end_time = MPI_Wtime();
    computation_time = end_time - start_time;
    // printf("Time of calculating integral is: %f\n", computation_time);
  }

  MPI_Finalize();
  return 0;
}