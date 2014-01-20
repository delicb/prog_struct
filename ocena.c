/*******************************************
*   Ime i Prezime: Bojan Delic
*   Broj indexa: 11510
*   Godina studija: 1
*   Datum: 14.12.2005
*   Verzija: 0.1
********************************************/

/**********************************************************************
*  Napisati C program koji za svakog studenta ucitava broj indexa i osvojene bodove za
*  tri zadatka A B i C, a zatim izracunava ukupan broj osvojenih bodova i na osnovu tog
*  pozivom funkcije odredjuje zakljcnu ocenu.
*
*  Obezbediti da se rezultati stampaju u po opadajucoj vrednosti broja bodova u obliku:
*
*  1.  11541  21  54  32  8
*  2.  11335  62  32  48  10
*
*  maximalan broj bodova po zadacima je 30, 30 i 40. Ocena se formiara po pravilu:
*  0-54 - 5
*  55-64 - 6
*  65-74 - 7
*  75-84 - 8
*  85-94 - 9
*  95-100 - 10
**********************************************************************/

#include <stdio.h>
#define MAX_NIZ 1000

/******************************************
*
*  Prototip funkcije
*
******************************************/
int ocena (int);


main () {

    /*******************************************************************
    *
    *       Inicijalizacija promenljivih
    *  stud je matrica u kojo se cuvaju brojevi indexa i bodovi svakog studenta
    *  i, j, k su brojaci za petlje
    *  n je broj studenata
    *  pom sluzi za menjanje vrednosti prilikom sortiranja
    *  again je promenljiva za ponavaljanje programa ako korisnik to zeli
    *
    *******************************************************************/
    int stud[MAX_NIZ][6], i, j, n, pom, k;
    char again='y';


    while (again=='y') {
            /******************************
            *
            *  Inicijalizacija matrice
            *
            *****************************/
            for (i=0; i<MAX_NIZ; i++) for (j=0; j<4; stud[i][j++] = 0) ;

            /*****************************
            *
            *  Uvodna konverzavija
            *
            ******************************/
            printf("Program za racunanje ocene studenata na osnovu bodova iz 3 testa\n");

            /****************************
            *
            *  Unos broja studenata
            *
            ****************************/
            printf("\n\tZa koliko studenta zelite da racunate ocenu? ");
            scanf("%d", &n);
            while (n<=0 || n>MAX_NIZ) {
                printf("Broj je van opsega! Za koliko studenata zelite da racunate ocenu? ");
                scanf("%d", &n);
                }


            /***************************
            *
            *  Unos matrice sa podacima
            *
            ***************************/
            /***************************
            *
            *  0 - broj indexa
            *  1 - broj bodova iz testa A
            *  2 - broj bodova iz testa B
            *  3 - broj bodova iz testa C
            *  4 - ukupan broj bodova
            *  5 - ocena
            *
            ***************************/
            for (i=0; i<n; i++) {

                /**********************************************
                *
                *  Unsos brojeva indexa
                *
                **********************************************/
                printf("\tUnesite broj indexa studenta za %d. studenta : ", i+1);
                scanf("%d", &stud[i][0]);

                /*********************************************
                *
                *  Unos bodova iz prvog testa
                *
                **********************************************/
                printf("\tUnesite broj bodova iz testa A za %d. studenta : ", i+1);
                scanf("%d", &stud[i][1]);
                while (stud[i][1]<0 || stud[i][1]>30) {
                    printf("\t\tBroj bodova je izvan osega\n\tUnesite broj bodova iz testa A za %d. studenta : ", i+1);
                    scanf("%d", &stud[i][1]);
                    }

                /**********************************************
                *
                *  Unos bodova iz drugog testa
                *
                **********************************************/
                printf("\tUnesite broj bodova iz testa B za %d. studenta : ", i+1);
                scanf("%d", &stud[i][2]);
                while (stud[i][2]<0 || stud[i][2]>30) {
                    printf("\t\tBroj bodova je izvan osega\n\tUnesite broj bodova iz testa B za %d. studenta : ", i+1);
                    scanf("%d", &stud[i][2]);
                    }

                /**********************************************
                *
                *  Unos bodova iz treceg testa
                *
                **********************************************/
                printf("\tUnesite broj bodova iz testa C za %d. studenta : ", i+1);
                scanf("%d", &stud[i][3]);
                while (stud[i][3]<0 || stud[i][3]>40) {
                    printf("\t\tBroj bodova je izvan osega\n\tUnesite broj bodova iz testa C za %d. studenta : ", i+1);
                    scanf("%d", &stud[i][3]);
                    }

                printf("\n\n");

                /***************************************
                *
                *  Racunanje ukupnog broja bodova
                *
                ***************************************/
                stud[i][4] = stud[i][1] + stud[i][2] + stud[i][3];

                /**************************************
                *
                *  Racunanje ocene pomocu funkcije ocena
                *
                ***************************************/
                stud[i][5] = ocena(stud[i][4]);

            }


            /**************************************
            *
            *  Sortiranje matrice na osnovu broja bodova
            *
            **************************************/
            for (i=0; i<n-1; i++) {
                for (j=i; j<n; j++) {
                    if (stud[j][4]>stud[i][4]) {
                        for (k=0; k<6; k++) {

                            pom = stud[i][k];
                            stud[i][k] = stud[j][k];
                            stud[j][k] = pom;

                        }
                    }
                }
            }

            /************************************
            *
            *  Ispis rezultata
            *
            ************************************/
            printf("\n\tBodovna lista: \n");
            printf("    Red.br     Br. indexa   Test A   Test B   Test C   Ukupno   Ocena\n");
            for (i=0; i<n; i++) {
                printf("%8d.%14d%9d%9d%9d%9d%8d\n", i+1, stud[i][0], stud[i][1], stud[i][2], stud[i][3], stud[i][4], stud[i][5]);


            }
            /************************************************
            *
            *  Provera da li korinik zeli da ponovi program
            *
            ************************************************/
            printf("\nDa li zelite da ponovite program? (y/n) ");
            scanf("%c", &again);
            scanf("%c", &again);
            while (again!='y' && again !='n') {
                printf("Pogresan unos! Da li zelite da ponovite program? (y/n) ");
                scanf("%c", &again);
                scanf("%c", &again);
                }

    }
    /*************************************
    *
    *  Kraj programa
    *
    *************************************/
    printf("\n\n***KRAJ PROGRAMA***\n\n\n");

}

/************************************************
*
*  funkcija za racunanje ocene
*
************************************************/
int ocena (int bodovi) {
    /**************************************************************
    *
    *       Definisanje lokalnih promenljivih
    *  o je ocena na onovu broja bodova (to je vrednost koju funkcija vraca)
    *
    **************************************************************/
    int o=0;
    switch (bodovi) {
        case 55: case 56: case 57: case 58: case 59: case 60: case 61: case 62:
        case 63: case 64: o = 6; break;
        case 65: case 66: case 67: case 68: case 69: case 70: case 71: case 72:
        case 73: case 74: o = 7; break;
        case 75: case 76: case 77: case 78: case 79: case 80: case 81: case 82:
        case 83: case 84: o = 8; break;
        case 85: case 86: case 87: case 88: case 89: case 90: case 91: case 92:
        case 93: case 94: o = 9; break;
        case 95: case 96: case 97: case 98: case 99: case 100: o = 10; break;
        default : o = 5; break;

        }


    return o;

    }

