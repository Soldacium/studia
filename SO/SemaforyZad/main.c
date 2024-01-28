#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <wait.h>
#include <pthread.h>
#include <sys/sem.h>
#define P 3    // ilosc procesow

int main()
{
   key_t klucz;
   int semID;
   int N = 5;  // ilosc semaforow
   char *procesy[P] = {"P1", "P2", "P3"};
   char sciezka[5];
   int i;

    // could be in utils
   if ( (klucz = ftok(".", 'B')) == -1 )
   {
      printf("Blad ftok (main)\n");
      exit(1);
   }
   // tworzymy N = 5 semafory
   if ( (semID = semget(klucz, N, IPC_CREAT | IPC_EXCL | 0666)) == -1)
   {
      perror("Blad semget (alokujSemafor): ");
      exit(1);
   }
   
   for (i = 0; i < N; i++){
    semctl(semID, i, SETVAL, 0); // zera, zeby sobie procesy nie pozwalały na za dużo
   }

   fflush(stdout);
   for (i = 0; i < P; i++){
        switch (fork())
        {
         case -1:
            perror("Blad fork (mainprog)");
            semctl(semID, N, IPC_RMID, NULL);
            exit(2);
         case 0:
            sciezka[0] = '\0';
            strcat(sciezka, "./");
            strcat(sciezka, procesy[i]);
            execl(sciezka, procesy[i], NULL);
        }
   }

   for (i = 0; i < P; i++)
      wait( (int *)NULL );

    semctl(semID, N, IPC_RMID, NULL);
}

/*
Jest pięć par (t21,t31),(t32,t22),(t22,t11),(t12,t23),(t23,t33) dlatego też tworzymy 5 semaforów
I tak:
gdy wezmiemy na przykład pierwszą parę, oznacza ona, że t21 musi być poprzedzone t31 tj.
program ma wypisać "text t31" zanim wypisze "text t21". Kiedy to zrobi nie ma większego znaczenia.
W procesie P3 więc dajemy jeden z semaforów który będzie dzielić z P2. Ma dostęp do operacji pierwszy
więc blokuje dostęp P2, P2 w tym czasie czeka aż bedzie uwolniony. Proces P3 po zablokowaniu, robi
co ma do zrobienia i odblokowuje semafor który uwalnia proces P2.

W każdym z programów-procesów wywołujemy sobie semID i klucz (w teorii mogłoby być to przekazane przez *argv)
*/
