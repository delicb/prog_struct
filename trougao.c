/*******************************************
*   Ime i Prezime: Bojan Delic
*   Broj indexa: 11510
*   Godina studija: 1
*   Datum: 16.11.2005
*   Verzija: 0.1
********************************************/

/*******************************************
*
*  Program koji na osnovu unesenih duzina
*  stranica trougla odredjuje tip trpugla
*  (jednakostranicni, jednakokraki, ranokraki)
*
********************************************/
#include <stdio.h>

main () {
    /*******************************************
    *
    *  a, b i c su stranie trougla
    *  tip je promenljiva u kojoj se pamti vrednost tipa trougla
    *  0 je jednakostranicni
    *  1 je jednakokraki
    *  2 je raznokraki
    *
    *******************************************/
    double a, b, c;
    char tip, again='y', greska='1';

    /*******************************************
    *
    *  Uvodna konverzacija
    *
    *******************************************/
    printf("**Program za odredjivanje tipa trougla na osnovu unesenih stranica**");

    /******************************************
    *
    *  Prva petlja sluzi za ponavljanje programa
    *  onoliko puta koliko to korisnik zeli
    *
    *******************************************/
    while (again=='y') {
        while (greska=='1') {
                /**********************************
                *
                *  Unos stranice a
                *  Unkoliko je stranica manja ili
                *  jednaka nuli upit se ponavlja
                *  dok god uslov ne bude zadovoljen
                *
                ***********************************/
                printf("\n\n Unesite stranicu a: ");
                scanf("%lf", &a);
                while (a<=0) {
                    printf("\nDuzina stranice mora biti veca od nule!");
                    printf("\nUnesite ponovo stranicu a: ");
                    scanf("%lf", &a);
                    }

                /**********************************
                *
                *  Unos stranice b
                *  Unkoliko je stranica manja ili
                *  jednaka nuli upit se ponavlja
                *  dok god uslov ne bude zadovoljen
                *
                ***********************************/
                printf("\n\n Unesite stranicu b: ");
                scanf("%lf", &b);
                while (b<=0) {
                    printf("\nDuzina stranice mora biti veca od nule!");
                    printf("\nUnesite ponovo stranicu b: ");
                    scanf("%lf", &b);
                    }

                /**********************************
                *
                *  Unos stranice c
                *  Unkoliko je stranica manja ili
                *  jednaka nuli upit se ponavlja
                *  dok god uslov ne bude zadovoljen
                *
                ***********************************/
                printf("\n\nUnesite stranicu c: ");
                scanf("%lf", &c);
                while (c<=0) {
                    printf("\nDuzina stranice mora biti veca od nule!");
                    printf("\nUnesite ponovo stranicu c: ");
                    scanf("%lf", &c);
                    }

                /****************************************************
                *
                *  u odnosu na usesene stranice prvera da li je moguc takav trougao
                *
                *****************************************************/
                if (a+b<=c) {
                    greska='1';
                    printf("\n\nNemoguc trougao! Unesite stranice ponovo!\n");
                    }
                    else {
                        if (a+c<=b) {
                            greska='1';
                            printf("\n\nNemoguc trougao! Unesite stranice ponovo!\n");
                            }
                            else {
                                if (b+c<=a) {
                                    greska='1';
                                    printf("\n\nNemoguc trougao! Unesite stranice ponovo!\n");
                                    }
                                    else greska='0';
                                }
                            }
            }

                /******************************************************
                *
                *  ako je trougao jedankostranicni promenljivoj tip dajemo vrednost 0
                *  ako je trougao raznokraki promenljivoj tip dajemo vrednost 2
                *  ako je trougao jednakostranicni promenljivoj tip dajemo vrednost 1
                *
                ******************************************************/

                if (a==b && b==c) tip = '0'; //jednakostranicni
                    else {tip = 'x';
                        if (a!=b && b!=c && a!=c) tip = '2'; //raznokraki
                            else tip = '1'; //jednakokraki
                            }




                /********************************************
                *
                *  U zavisnosti od vrednosti promenljive tip program ispisuje vrstu trougla
                *
                **********************************************/
                if (tip=='0') printf("\n\nTrougao je jednakostranicni!\n");
                if(tip=='1') printf("\n\nTrougao je jednakokraki!\n");
                if(tip=='2') printf("\n\nTrougao je raznokraki!\n");


                /********************************************
                *
                *  provera da li korinsik zeli da se opet izvrsi program
                *
                **********************************************/
                scanf("%c", &again);
                printf("\nDa li zelite da ponovo izvrsite program? (y/n) ");
                scanf("%c", &again);
                while (again!='y' && again!='n') {
                    printf("\n\tMorate uneti y ili n!");
                    printf("\nDa li zelite da ponovo izvrsite program? (y/n) ");
                    scanf("%c", &again);
                    }
                /**********************************************
                *
                *  Greska se postavlja na 1 da bi program prosao ponovo
                *  kroz petlju za prveru ako korisnik ponovi program
                *
                ***********************************************/
                greska='1';

        }



    }
