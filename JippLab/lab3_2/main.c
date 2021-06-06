#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING 150
#define MAX_LINES 150


void program1(){
    char text[MAX_STRING];
    char searchedLetter = 97; // a
    printf("Text to seach: ");
    gets(text);
    printf("\nLetter to find: ");
    searchedLetter = getc(stdin);

    int found = 0;
    for(int i = 0; i < MAX_STRING; i++){
        if(text[i] == searchedLetter){
            found = 1;
            printf("found letter \n");
            return;
        }
    }
    printf("letter not found \n");
}

// 14
void program2(){
    char text[MAX_STRING];
    char searchedLetter = 97; // a
    printf("Text to seach: ");
    gets(text);
    printf("\nLetter to delete: ");
    searchedLetter = getc(stdin);
    getc(stdin);

    int found = 0;
    char newText[MAX_STRING];
    for(int i = 0; i < strlen(text); i++){
        if(text[i] == searchedLetter){
            found = 1;
        }

        if(text[i] != searchedLetter && found == 0){
            newText[i - found] = text[i];
        }
    }
    printf("\n%s",newText);
}
// 15
void program3(){
    char text[MAX_STRING];
    char searchedLetter = 97; // a
    char changeLetter = 97;
    printf("Text to seach: ");
    gets(text);
    printf("\nLetter to change: ");
    // scanf("%c",&searchedLetter);
    searchedLetter = getc(stdin);
    getc(stdin);
    printf("\nLetter to change into: ");
    // scanf("%c",&changeLetter);
    changeLetter = getc(stdin);

    for(int i = 0; i < MAX_STRING; i++){
        if(text[i] == searchedLetter){
            text[i] = changeLetter;
        }
    }
    printf("\n%s",text);
}
// 16
void program5(){
    char text1[MAX_STRING] = "text 1";
    const char *text2 = "text 2";

    strcat (text1, text2);
    printf("\n%s",text1);
}

// 17
void program6(){
    char textFirst[MAX_STRING]="text 1 text";
    int insertPosition = 4;
    const char *textSecond="i am text 2";

    char combinedText[MAX_STRING];
    char leftString[MAX_STRING];
    for(int i = 0; i < strlen(textFirst); i++){
        if(i < insertPosition){
            combinedText[i] = textFirst[i];
        } else {
            leftString[i - insertPosition] = textFirst[i];
        }

    }
    strcat (combinedText, textSecond);
    strcat(combinedText,leftString);

    printf("%s",combinedText);
}
// 28
void program7(){
    FILE *fp;
    char line[MAX_STRING];
    int len;
    if (!(fp = fopen("text.txt", "r"))){
        printf("Blad otwarcia zbioru\n");
        exit(2);
    }

    int i = 0;
    printf("Big - Small - Other -------text---------- \n");
    while (i < MAX_LINES && fgets(line, MAX_STRING, fp)){
        len = strlen(line);
        int big = 0, small = 0, other = 0;
        for(int j = 0; j < len; j++){
            if(line[j] > 64 && line[j] < 91){
                big++;
            }else if(line[j] > 96 && line[j] < 123){
                small++;
            }else{
                other++;
            }
        }
        printf("%d     %d      %d     %s",big,small,other,line);
        i++;
    }
    fclose(fp);
}

// 32
void program8(){
    FILE *fp;
    char *d[MAX_LINES], lineText[MAX_STRING];
    int len, i, l;
    int lineNum1 = 1, lineNum2 = 2;
    char lineTextSwap1[MAX_STRING],lineTextSwap2[MAX_STRING];

    if (!(fp = fopen("string.txt", "r"))){
        printf("Blad otwarcia zbioru\n");
        exit(2);
    }
    i = 0;
    l = 0;
    while (i < MAX_LINES && fgets(lineText, MAX_STRING, fp)){
        len = strlen(lineText);
        printf("%s",lineText);

        if(i == lineNum1 - 1){
            strcpy(lineTextSwap1,lineText);
            // lineTextSwap1 = lineText;
        }
        if(i == lineNum2 - 1){
            strcpy(lineTextSwap2,lineText);
        }
        i++;
    }
    fclose(fp);
    FILE *fp2;
    if (!(fp2 = fopen("string.txt", "w"))){
        printf("Blad otwarcia\n");
        exit(2);
    }

    i = 0;
    while (i < MAX_LINES ){
        if(i == lineNum1 - 1){
            fprintf (fp2, "%s\n",lineTextSwap1);
            printf("\n%s",lineTextSwap1);
        }
        if(i == lineNum2 - 1){
            fprintf (fp2, "%s\n",lineTextSwap2);
            printf("\n%s",lineTextSwap2);
        }
        i++;
    }
    fclose(fp2);
}

// 33
void program9(){
    FILE *fp;
    char line[MAX_STRING];
    char startText[MAX_STRING] = "ab";
    int len;
    if (!(fp = fopen("text.txt", "r"))){
        printf("Blad otwarcia pliku\n");
        exit(2);
    }

    int i = 0;
    int searchLineLen = strlen(startText);
    printf("Searched starting word: %s \n",startText);
    printf("Found lines: \n");
    while (i < MAX_LINES && fgets(line, MAX_STRING, fp)){
        int correct = 0;
        for(int j = 0; j < searchLineLen; j++){
            if(line[j] == startText[j]){
                correct++;
            }
        }
        if(correct == searchLineLen){
            printf("%s",line);
        }
        i++;
    }
    fclose(fp);
}

// 34
void program10(){
}
// 35 done
void program11(){
    char str[] = "word1:word2:word3:word4:word5";
    int wordIndex = 1;
	int init_size = strlen(str);
	char delim[] = ":";

	char *ptr = strtok(str, delim);

	int i = 0;
	while(ptr != NULL)
	{
	    if(i == wordIndex){
           printf("word of index %d: %s\n", wordIndex, ptr);
	    }
		ptr = strtok(NULL, delim);
		i++;
	}
}
// 36
void program12(){

}

int main()
{
    printf("Current max text length: %d \n",MAX_STRING);
    // program6();
    program2();
    return 0;
}
