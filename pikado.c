/*******************************************
*   Ime i Prezime: Bojan Delic
*   Broj indexa: 11510
*   Godina studija: 1
*   Datum: 21.11.2005
*   Verzija: 0.1
********************************************/

/********************************************
*
*  Program koji racuna broj bodova u pikadu na
*  osnovu unesenih kooridata pogotka i ispisuje
*  ih na ekranu!
*
*********************************************/

#include <stdio.h>
#include <math.h>

main () {
    /***************************************
    *
    *  Deklaracija promenljivih
    *  n je broj koncentricnih krugova na meti
    *  i je pomocna promenljiva za ciklus
    *  bodovi sluze za cuvanje broja bodova
    *  x i y su promenljive za koordinate
    *  d je rastojanje pogotka od koordinatnog pocetka
    *  again je pomocna promenljiva za ponovo izvrsavanje programa
    *                   ako korisnik to zeli
    *
    ***************************************/
    int n, i, bodovi;
    double x, y, d;
    char again='y';

    /**************************************
    *
    *  Pocenta konverzavija
    *
    **************************************/
    printf("**Program za racunanje bodova na meti u pikadu!**\n");


    while (again == 'y') {
        /*************************************
        *
        *  Unos broja krugova na meti
        *
        **************************************/
        printf("\n\tUnesite broj koncentricnih krugova na meti: ");
        scanf("%d", &n);


        /*************************************
        *
        *  Unos prve koordinate mete
        *
        **************************************/
        printf("\n\tUneste prvu koordinatu pogotka: ");
        scanf("%lf", &x);

        /*************************************
        *
        *  Unos druge koordinate mete
        *
        **************************************/
        printf("\n\tUnesite drugu koordinatu pogotka: ");
        scanf("%lf", &y);

        /*************************************
        *
        *  Racunanje rastojanja pogotka od
        *  sredine mete (koordinatnog pocetka)
        *
        **************************************/
        d = sqrt(pow(x,2) + pow(y,2));

        /*************************************
        *
        *  Petlja za proveravanje lokacije pogotka
        *  na meti i racunanje broja bodova
        *
        *  Ukoliko se pogodak nalazi na liniji
        *  racuna se krug blizi centru, odnosno
        *  veci broj bodova
        *
        *************************************/
        for(bodovi=0, i=0; i<n; i++) {
            /****************************
            *
            *  Provera da li se pogodak
            *  nalazi izmedju dva kruga
            *  i na osnovu toga racunanje
            *  broja bodova
            *
            *****************************/
            if ((d<=(i+1)) && (d>i)) bodovi = n-i;

         }

        /*************************************
        *
        *  Ispis rezultata
        *
        **************************************/
        printf("\nBroj bodova je: %d\n", bodovi);

        /*************************************
        *
        *  Provera da li korisnik zeli ponovo da
        *  pokrene program
        *
        **************************************/
        scanf("$c", &again);  /*Zbog buffera sa tastature */
        printf("\n\n\tDa li zelite da ponovo izvrsite program? (y/n) :");
        scanf("%c", &again);
        while (again != 'y' && again != 'n') {
            printf("\n\t***POGRESAN UNOS***\n\t\tUnesite 'y' za DA ili 'n' za NE!");
            printf("\n\tda li zelite da ponovo izvrsite program? (y/n) :");
            scanf("%c", &again);
            }

    }

    /***********************************
    *
    *  KRAJ PROGRAMA
    *
    ************************************/
    printf("\n\n\t\t***KRAJ PROGRAMA***\n\n");
 }
