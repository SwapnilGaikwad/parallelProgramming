#!/usr/bin/env julia

@printf("Total number of processes: %d\n\n", nprocs())
@everywhere p=5
@everywhere println(@sprintf("My ID: %d, value of P: %d", myid(), p))
@everywhere p=p+myid()
@printf("\nAfter adding the current process id to %d\n",p)
@everywhere println(@sprintf(" ID: %d, value of P: %d", myid(), p))

