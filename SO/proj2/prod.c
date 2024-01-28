#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <time.h>
#include <sys/sem.h>
#include "utils.c"

struct bufor{
	int mtype;
	int mvalue;
};

int *pam;

#define MAX 10
#define MAX2 12
#define PELNY 2
#define PUSTY 1
#define odczyt pam[MAX]
#define zapis pam[MAX+1]
int main()
{
   key_t klucz, kluczm,kluczs;
   int msgID;
   int shmID, semID;
   time_t czas;
   struct bufor komunikat;
   char* data;

   if ( (klucz = ftok(".", 'A')) == -1 )
   {
      printf("Blad ftok (main)\n");
      exit(1);
   }

   msgID=msgget(klucz,IPC_CREAT|0666);
   if (msgID==-1)
	{printf("blad kolejki komunikatow\n"); exit(1);}

   kluczm=ftok(".",'B');
   shmID=shmget(kluczm, MAX2*sizeof(int), IPC_CREAT|0666);
   if (shmID==-1) {printf("blad pamięci dzielonej\n"); exit(1);}

   kluczs=ftok(".",'C');
   semID=semget(kluczs,1,IPC_CREAT|0666);
   if(semID==-1) {printf("blad semaforów \n");exit(1);}

   // printf("sem: %d\n", semID);
   pam=(int*)shmat(shmID, NULL, 0);

   while (1)
   {
      /* code */   
   if (msgrcv(msgID,&komunikat,sizeof(komunikat.mvalue),PUSTY,0)==-1)
      printf("błąd odczytu wiadomosci\n");

   printf("prod dostał: %d\n", komunikat.mtype);
   printf("prod czeka na wolna pamiec\n");
   waitSemafor(semID, 0, 0);

   struct bufor komOut;
   komOut.mtype = PELNY;
   komOut.mvalue = 0;
   komunikat.mvalue = 0;
   sleep(getpid() % 2);
   pam[zapis] = getpid();
   zapis = (zapis + 1) % MAX;
   signalSemafor(semID, 0);

   printf("prod zapisal w pamięci %d\n", getpid());
   if(msgsnd(msgID, &komOut, sizeof(komOut.mvalue), 0) == -1){
      printf("blad komunikatu z pid %d\n",getpid());
      exit(1);
   };
   printf("producent wysłał komunikat %d\n\n", komOut.mtype);
   }
   

         
   shmdt(pam);

  // w sekcji krytycznej  zapis PID-u (getpid()) do puli buforow pod indeks zapis

 }

