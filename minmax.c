/*******************************************
*   Ime i Prezime: Bojan Delic
*   Broj indexa: 11510
*   Godina studija: 1
*   Datum: 22.11.2005
*   Verzija: 0.1
********************************************/

/*******************************************
*
*  Napisati program za unosenje brojeva A, B, C, D, E i na ekranu
*  ispisuje imena unesenih brojeva (A, B, C, D ili E) koji nisu
*  ni minimalni ni maximalni
*
*******************************************/
#include <stdio.h>

main () {
    /**************************************
    *
    *  Niz a sluzi da za cuvanje imana promenljivih
    *           (indexi imena su isti kao indexi unesenih brojeva)
    *  Niz b sluzi za unos brojeva
    *  min i max su najmanji i najveci clanovi niza b
    *  i je pomocna promenljiva za for petlju
    *  k je  broj onih koji nisu ni minimalni ni maximalni
    *           (sluzi za to da ako nema onih koji nisu ni minimalni ni maximalni
    *           onda ispisuje poruku da ih nema, a ne ostavlja prazan ekran)
    *  again je pomovna promenljiva za ponavljanje programa ako korisnik to zeli
    *
    **************************************/
    char a[5] = {'A', 'B', 'C', 'D', 'E'};
    float b[5], min, max;
    int i, k;
    char again = 'y';

    /*************************************
    *
    *  Uvodna konverzacija
    *
    **************************************/
    printf("Program za ispisivanje clanova koji nisu ni najmanji ni najveci!\n\n");

    /*************************************
    *
    *  while petlja koja sluzi za ponavljanje programa onoliko
    *  puta koliko to korinsik zeli
    *
    *************************************/
    while (again=='y') {

            /************************************
            *
            *  Unos clanova niza b
            *
            ************************************/
            for (i=0; i<5; i++) {
                printf("Unesite %c: ", a[i]);
                scanf("%f", &b[i]);
            }

            /***********************************
            *
            *  Petlja za odredjivanje najveceg i najmanjeg clana b niza
            *
            ***********************************/
            for (min=b[0], max=b[0], i=1; i<5; i++) {
                if (b[i]<min) min = b[i];
                if (b[i]>max) max = b[i];
                }

            /***********************************
            *
            *  Brojanje onih koji nisu ni minimalni ni maximalni
            *
            ***********************************/
            for (k=0, i=0; i<5; i++) if ((b[i]!=min) && (b[i]!=max)) k++;

            /**********************************
            *
            *  Ako je broj onih koji nisu ni minimalni ni maximalni
            *  veci od nule ispisuje njihova imena na ekraju,
            *  a ako je jedank nuli ispisuje odgovarajucu poruku
            *
            **********************************/
            if (k!=0) {
                printf("\Nisu ni minimalni ni maximalni: \n");
                for (i=0; i<5; i++) if ((b[i]!=min) && (b[i]!=max))
                    printf("\t%c", a[i]);
                }
                else
                     printf("\tSvi clanovi su ili minimalni ili maximalni!\n");

            /**********************************
            *
            *  Da li korisnik zeli da ponovi program?
            *
            ***********************************/
            scanf("%c", &again);
            printf("\n\n\tDa li zelite da ponovo izvrsite program? (y/n): ");
            scanf("%c", &again);
            while (again!='y' && again!='n') {
                scanf("%c", &again);
                printf("\n\n**POGRESAN UNOS** Unesite 'y' za DA i 'n' za NE!\n");
                printf("\n\n\tDa li zelite da ponovo izvrsite program? (y/n): ");
                scanf("%c", &again);
                }

            /**********************
            *
            *  KRAJ PROGRAMA
            *
            **********************/
            printf("\n\n***KRAJ PROGRAMA***\n\n");


    }
   }
