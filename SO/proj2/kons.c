#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/sem.h>
#include "utils.c"

struct bufor{
	int mtype;
	int mvalue;
};
int *pam;
#define MAX2 12
#define MAX 10
#define PELNY 2
#define PUSTY 1
#define zapis pam[MAX+1]
#define odczyt pam[MAX]

int main()
{
   key_t klucz, kluczm, kluczs;
   int msgID, shmID, semID;
   int i;
   char *data;
   struct bufor komunikat;

   // sleep(getpid() % 3);
   printf("konsument sie budzi\n");
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
   // printf("sem: %d\n",semID);

   pam=(int*)shmat(shmID,NULL,0);

  

while (1)
{
      //odbiorpowiedniego komunikatu
   if(msgrcv(msgID, &komunikat, sizeof(komunikat.mvalue), PELNY, 0) == -1)
      printf("blad odbioru komunikatu przez konsumenta\n");

   printf("kons otrzymal kom %d\n", komunikat.mtype);
   printf("kons czeka na wolna pamiec\n");
   waitSemafor(semID, 0, 0);
   struct bufor komOut;
   komOut.mtype = PUSTY;
   komOut.mvalue = 0;

   pid_t readPID = pam[odczyt];
   odczyt = (odczyt + 1) % MAX;
   signalSemafor(semID, 0);
   printf("kons wzial z pamieci %d\n", readPID);
   if(msgsnd(msgID, &komOut, sizeof(komOut.mvalue), 0) == -1){
      printf("kons nie mogl wyslac\n");
      exit(1);
   };
   printf("kons wyslal kom %d\n\n", komOut.mtype);    
}

   shmdt(pam);

   
}

