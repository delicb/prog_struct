/*
    Ime i Prezime: Bojan Delic
    Broj indexa: 11510
    Godina studija: 1
    Datum: 09.11.2005
    Verzija: 0.1
*/
/*

Program koji na osnovu unetih sekundi ispisuje vreme u obliku hh:mm:ss

*/
#include <stdio.h>

main () {

    int s, m, h, s1;        //s - broj unetih sekundi, m-broj minuta, h - broj sati, s1 - broj sekundi na izlazu
    char again = 'y';       //za proveravanje da li korinsik zeli da ponovi program
    printf("***Program za pretvaranje broja sekundi u sate i minute***");

    while(again =='y') {

        printf("\n\tUnesite broj sekundi: ");
        scanf("%i", &s);        //ucitava se broj sekundi
        /*ako je broj sekundi manji od nule ucitavaj ih
        ponovo dok ne bude veci od nule*/
        while (s<0) {
            printf("***GRESKA*** \n\tBroj sekundi ne moze biti negativan");
            scanf("%i", &s);
            }

        h = s/3600;     //racunanje broja sati

        s1 = s%60;      //racunanje broja sekundi

        m = (s-h*3600)/60;  //racunanje broja minuta

        if (s1+60*m+3600*h == s)        //ako zbir sati, minuta i sekundi daje broj unetih sekundi

        printf("\nVreme je %02i : %02i : %02i!\n\n ", h, m, s1);    //onda ispisi rezultat


        else {                              //a ako nije isti zbir
            printf("\n\n\t\t****GRESKA U PROGRAMU****\n\n");        //pojavila se greska u racunanju
        }

        /*
        pitanje da li korisnik zeli da ponovi program
        */
        scanf("%c", &again);    //zbog entera, ucicemo posle detaljnije
        printf("\n\n\tDa li zelite da ponovite program (y/n)? ");
        scanf("%c", &again);

        /*
        petlja zbog moguceg neispravnog unosa
        */
        while (again!='y' && again!='n') {
            printf("\t***GRESKA***. Unesite 'y' ili 'n'!");
            printf("\n\n\tDa li zelite da ponovite program (y/n)? ");
            scanf("%c", &again);
        }
    }
    printf("\t\t*******KRAJ PROGRAMA*******\n\n");              //KRAJ PROGRAMA
}
