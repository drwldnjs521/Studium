typedef struct {

    int zaehler;
    int nenner;

} bruch; 
bruch product(bruch a, bruch b); // Hinweis: Ergebnis nicht kuerzen!
void set_nenner(bruch* a, int nenner);
void print(bruch a);
