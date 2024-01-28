#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/sem.h>
#include "utils.c"

int main(int argc, char *argv[])
{
   key_t klucz;
   int semID;
   int N = 3;
   FILE *fp;
   pid_t pidNr;

   if ( (klucz = ftok(".", 'B')) == -1 )
   {
      printf("Blad ftok (P1)\n");
      exit(2);
   }

   semID = semget(klucz, N, IPC_CREAT | 0666);
   pidNr = getpid();

    // semafory zaczynają od 0
    waitSemafor(semID, 2, 0);
    printf("Sekcja t1_1 procesu PID=%i\n", getpid());
    fflush(stdout);
    fp = fopen("wynik.txt","a");
    fprintf(fp,"Sekcja t1_1 procesu PID=%i\n", getpid());
    fclose(fp);
    sleep(1);

    printf("Sekcja t1_2 procesu PID=%i\n", getpid());
    fflush(stdout);
    fp = fopen("wynik.txt","a");
    fprintf(fp,"Sekcja t1_2 procesu PID=%i\n", getpid());
    fclose(fp);
    sleep(1);
    signalSemafor(semID, 3);
        


}

