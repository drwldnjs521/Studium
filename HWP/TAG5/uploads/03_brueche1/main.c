#include <stdio.h>
#include "bruch.h"

int main () {
    bruch a, b;

    printf("Geben Sie den Zähler von Bruch a ein: ");
    scanf("%d", &(a.zaehler));
    printf("Geben Sie den Nenner von Bruch a ein: ");
    scanf("%d", &(a.nenner));

    printf("Geben Sie den Zähler von Bruch b ein: ");
    scanf("%d", &(b.zaehler));
    printf("Geben Sie den Nenner von Bruch b ein: ");
    scanf("%d", &(b.nenner));

    printf("Bruch a lautet ");
    print(a);
    puts("");

    printf("Bruch b lautet ");
    print(b);
    puts("");

    printf("Das Produkt der beider Brüche lautet ");
    print(product(a, b));
    puts("");

    printf("Geben Sie einen neuen Wert für den Nenner von Bruch a ein: ");
    int nenner_new;
    scanf("%d", &nenner_new);
    set_nenner (&a, nenner_new);

    printf("Bruch a lautet nun: ");
    print(a);
    puts("");

    return 0;
}
