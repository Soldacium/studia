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
      printf("Blad ftok (P2)\n");
      exit(2);
   }

   semID = semget(klucz, N, IPC_CREAT | 0666);
   pidNr = getpid();

    // semafory zaczynają od 0
    printf("Sekcja t2_1 procesu PID=%i\n", getpid());
    fflush(stdout);
    fp = fopen("wynik.txt","a");
    fprintf(fp,"Sekcja t2_1 procesu PID=%i\n", getpid());
    fclose(fp);
    sleep(1);
    signalSemafor(semID, 0); // odblokuj pierwszy
        
        

    waitSemafor(semID, 1, 0); // czekaj drugi
    printf("Sekcja t2_2 procesu PID=%i\n", getpid());
    fflush(stdout);
    fp = fopen("wynik.txt","a");
    fprintf(fp,"Sekcja t2_2 procesu PID=%i\n", getpid());
    fclose(fp);
    sleep(1);
    signalSemafor(semID, 2); // odblokuj 3
        

    waitSemafor(semID, 3, 0); // czekaj czwarty
    printf("Sekcja t2_3 procesu PID=%i\n", getpid());
    fflush(stdout);
    fp = fopen("wynik.txt","a");
    fprintf(fp,"Sekcja t2_3 procesu PID=%i\n", getpid());
    fclose(fp);
    sleep(1);
    signalSemafor(semID, 4); // odblokuj 5
        
}
