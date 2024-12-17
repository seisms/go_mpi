/*
*   go.c: Determine the winner of a GO match. The program uses private memory
*         to solve the problem 
*
*   Programmer: Diego Cuevas
*
*   Santiago de Chile, 9/12/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>
#include "go.h"

void parse_args(int argc, char *argv[], struct RuntimeInfo *runtime)
{
    int i;

    if (argc != 3) {
        printf("%s\n", USAGE);
        exit(EXIT_SUCCESS);
    }

    if (strncmp(argv[1], "-V", CMP_MAX) == 0)
        runtime->mode = VERTICAL;
    else if (strncmp(argv[1], "-H", CMP_MAX) == 0)
        runtime->mode = HORIZONTAL;
    else {
        printf("invalid option: %s\n", argv[1]);
        exit(EXIT_SUCCESS);
    }

    if (strncmp(argv[2], "-V", CMP_MAX) == 0)
        runtime->log = VERBOSE;
    else if (strncmp(argv[2], "-S", CMP_MAX) == 0)
        runtime->log = SILENT;
    else {
        printf("invalid option: %s\n", argv[2]);
        exit(EXIT_SUCCESS);
    }
}

int main(int argc, char *argv[])
{
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int allwe, whoami, me;
    struct RuntimeInfo runtime;

    parse_args(argc, argv, &runtime);

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &allwe);
    MPI_Comm_rank(MPI_COMM_WORLD, &whoami);
    MPI_Get_processor_name(processor_name, &me);
    printf("Process [%d] Alive on %s\n", whoami, processor_name);
    fflush(stdout);
    MPI_Barrier(MPI_COMM_WORLD);

    MPI_Finalize();
    return EXIT_SUCCESS;
}
