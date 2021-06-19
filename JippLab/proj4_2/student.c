
typedef struct student {
    char* imie;
    char* nazwisko;
    int rok;
} student;

typedef struct studentStos {
    student student;
    struct studentStos* next;
} studentStos;

typedef struct studentKolejka {
    student student;
    struct studentStos* next;
} studentKolejka;