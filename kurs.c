/*
    Ime i Prezime: Bojan Delic
    Broj indexa: 11510
    Godina studija: 1
    Datum: 04.11.2005
    Verzija: 0.1
*/
#include <stdio.h>
const float kurs = 86.0333;

main () {
    float din, eur;
    printf("**Program za racunanje kursa!**\n\n");
    printf("Koliko imate eura? ");
    scanf("%f", &eur);
    din = eur * kurs;
    printf("\n\nImate %.2f dinara\n\n", din);
}
