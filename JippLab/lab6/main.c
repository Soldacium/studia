#include <stdio.h>
#include <stdlib.h>

void program1(){
  FILE *fp;

  int num;

  fp = fopen("integers", "w");

  if (fp != NULL) {
    printf("File created successfully!\n");
  }
  else {
    printf("Failed to create the file.\n");
    return -1;
  }

  printf("Wpisz liczby (-1 wyjscie): ");
  while (1) {
    scanf("%d", &num);
    if (num != -1) {
      putw(num, fp);
    }
    else {
      break;
    }
  }

  fclose(fp);
  fp = fopen("integers", "r");

  printf("\nLiczby:\n");
  while ( (num = getw(fp)) != EOF ) {
    printf("%d\n", num);
  }

  fclose(fp);
}

void program2(){

    FILE *fp;

    fp = fopen("string.txt", "w");

    if (fp != NULL) {
        printf("File created successfully!\n");
    } else {
        printf("Failed to create the file.\n");
        return -1;
    }

    int dlugosc;

    printf("Podaj dlugosc tekstu:\n");
    scanf("%d",&dlugosc);

    char tab[dlugosc];

    printf("Podaj tekst (maksymalna dlugosc tekstu: %d ):\n", dlugosc);
    scanf("%s", &tab);

    fprintf(fp, "%s",tab);

    fclose(fp);
}


void program3(){

    FILE *fp1;
    FILE *fp2;

    fp1 = fopen("string.txt", "r");
    fp2 = fopen("stringCopy.txt", "w");

    if (fp1 != NULL) {
        printf("File 1 opened successfully!\n");
    } else {
        printf("Failed to open the file.\n");
        return -1;
    }

    if (fp2 != NULL) {
        printf("File 2 created successfully!\n");
    } else {
        printf("Failed to create the file.\n");
        return -1;
    }

    int string[50];


    int max_n= 50;
    int linie= 2;
    char napis[max_n], *result;
    for (int i = 1; i <= linie; ++i)
    {
        result = fgets (napis, max_n, stdin);   // czytamy ze standardowego wejœcia
        if (result != NULL)
        {
            printf ("%d %s", i, napis);
            if (feof (stdin))
                printf ("\n%d koniec pliku\n", i);
        }
        else
            printf ("\n%d blad odczytu\n", i);
    }
    fclose(fp1);
    fclose(fp2);
}

void program4(){

    FILE *fp;

    fp = fopen("string.txt", "r");

    if (fp != NULL) {
        printf("File 1 opened successfully!\n");
    } else {
        printf("Failed to open the file.\n");
        return -1;
    }

    fseek( fp, 0L, SEEK_END );
    int size = ftell(fp);

    printf("%d",size);
}

const int ASCII_CHARACTERS_COUNT = 128;
void program5(){
    int chars[ASCII_CHARACTERS_COUNT];
    memset( chars, 0, ASCII_CHARACTERS_COUNT*sizeof(int));
    FILE *fp;

    fp = fopen("string.txt", "r");

    if (fp != NULL) {
        printf("File 1 opened successfully!\n");
    } else {
        printf("Failed to open the file.\n");
        return -1;
    }

    int c;

    // zmienic char na int odpowiadajacy numerowi ascii
    while((c=fgetc(fp))) {

        if(c == EOF) { break; }
        chars[c] += 1;
    }

    for(int i = 0; i < ASCII_CHARACTERS_COUNT; i++) {
        if(chars[i] > 0) {
            printf("%c: %d\n", i, chars[i]);
        }
    }
    fclose(fp);
}


int main() {

    program5();
    return 0;
}
