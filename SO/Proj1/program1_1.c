#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{ 
    printf("process - PID: %d | PPID: %d | UID: %d | GID: %d\n", getpid(),getppid(), getuid(), getgid());
    printf("%d -> %d\n", getppid(), getpid());
} 