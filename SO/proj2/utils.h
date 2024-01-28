#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/errno.h>

int waitSemafor(int semID, int number, int flags);
void signalSemafor(int semID, int number);