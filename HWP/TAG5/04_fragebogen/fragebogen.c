#include <stdio.h>
#include <string.h>

typedef enum {Informatik = 1, Mathematik, Physik} faecher;
typedef enum {sehr_gut = 1, gut, befriedigend, ausreichend, mangelhaft, ungenuegend} benotung;

typedef struct {
    faecher fach;
    unsigned int semester:4;
    benotung note;
    char anmerkung[120];
} datei;

int main(){
    unsigned int fach = 0;
    unsigned int semester = 0;
    unsigned int note;
    char anmerkung[120];
    datei datei1;

    printf("Welches Fach studieren Sie? (1: Informatik, 2: Mathematik, 3: Physik)\n");
    scanf("%i", &fach);
    while(getchar() != '\n');
    
    printf("In welchem Fachsemester studieren Sie? (1-12)\n");
    scanf("%i", &semester);
    while(getchar() != '\n');

    printf("Bitte benoten Sie Ihre Übung in Schulnoten. (1-6)\n");
    scanf("%i", &note);
    while(getchar() != '\n');

    printf("Haben Sie weitere Anmerkungen?\n");
    fgets(anmerkung, 120, stdin);

    datei1.fach = fach;
    datei1.semester = semester;
    datei1.note = note;
    strcpy(datei1.anmerkung, anmerkung);
   
    printf("Fach (1 = Informatik, 2 = Mathematik, 3 = Physik): %d\n", datei1.fach);
    printf("Semester: %d\n", datei1.semester);
    printf("Note (sehr_gut = 1, gut = 2, befriedigend = 3, ausreichend = 4, mangelhaft = 5, ungenuegend = 6): %d\n", datei1.note);
    printf("Anmerkung: %s", datei1	.anmerkung);  

    
}


