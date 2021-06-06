#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING 130

// proj 22
void func(){
    char oldString[MAX_STRING];
    char newString[MAX_STRING];
    char searchedLetter = 97; // 'a'
    gets(oldString);

    int deletedLetters = 0;

    for(int i = 0; i < MAX_STRING; i++){
        if(oldString[i] != searchedLetter){
            newString[i - deletedLetters] = oldString[i];
        }else{
            deletedLetters++;
        }
    }

    printf("%s \n",oldString);
    printf("%s \n",newString);
}

int main()
{
    func();
    return 0;
}
