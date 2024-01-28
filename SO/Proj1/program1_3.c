#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{ 
    int max = 3;
    for(int i = 0; i < max; i++){
        int pid1,pid2;

        if(pid1=fork()){
            pid2=wait(NULL); // parent needs to exist, so waits for child to be done.
            if(pid2 == -1){
                perror("fork wait");
            }
            printf("done %d\n", pid2);
        }
        else{
            execl("getpids","program1_1",NULL);
            perror("execl failure program1_3:21");
        }
    }

} 

/*

Dlaczego inny wynik?

Bo każdy proces potomny nie może stać się rozgałęzieniem, bo wkonując instrukcję dziecka którym jest przestaje nim być
poprzez execl(); zmienia się w coś innego tj. przestaje być w pętli for.

parent wypisuje że jest "done"
dziecko wypisuje informacje o sobie
tylko jak wczesniej to dzieko po wypisaniu kontynuowało pętlę, tak teraz nie robi tego i kończy się całkowicie.

pętla przechodzi dokładnie 3 razy, bo każde rozwidlenie fork-iem tworzy kontunuację parenta, która, teraz będąc
dzieckiem, wypisuje od razu co ma wypisać i się zakańcza nie dając swoich dzieci

orginalnie drzewko jest takie

1 - 2 - 3 - 4
|   |
|   | - 5
|
| - 6 - 7
|
|
|
| - 8

a w tym programie wypisuje się jedynie:
2, 6 i 8, bezpośrednie dzieci programu macierzystego powstałe z orginalnej pętli for().

*/