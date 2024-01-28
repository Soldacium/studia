#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{ 
    char cm[50];
    sprintf(cm, "pstree -ph %d", getpid());
    int x = getpid();
    int max = 3;
    for(int i = 0; i < max; i++){
        int pid1,pid2;

        if(pid1=fork()){
            // pid2=wait(NULL); // parent needs to exist, so waits for child to be done.
            
        }
        else{
            int pid = getpid(), ppid = getppid();
            printf("potomek - pid=%d  ppid=%d  pid1=%d\n",pid, ppid, pid1);
            printf("%d -> %d\n", ppid, pid);


        }
 
    }
    if(x== getppid()){
        for(int i = 0 ; i < max ; i++){
            wait(NULL);
        }
        system(cm);
    }else{
            sleep(1);
    }



} 

/*

Sytuacja prosta, bez sztuczek powstaje łącznie 7 dzieci, więc w sumie procesów będzie 8 (z macierzystym);

1 - 2 - 3 - 4
|   |
|   | - 5
|
| - 6 - 7
|
|
|
| - 8

pierwsza pętla:
tworzymy p2, p2 ma swoją pętlę z i = 1, też tworzy swoje dziecko, dziecko dalej ma pętlę, teraz z i=2, tworzy dziecko

druga pętla i trzecia:
tworzymy odpowiednie procesy analogicznie inkrementując stabilnie

tak więc:
proces macierzysty będzie miał troje dzieci bo przejdzie przez pętlę trzy razy,
pierwszy potomek będzie miał dwoje dzieci bo przejdzie już tylko dwa
drugi potomek będzie miał jedno
trzeci potomek żadnego
*/