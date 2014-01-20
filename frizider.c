/*******************************************
*   Ime i Prezime: Bojan Delic
*   Broj indexa: 11510
*   Godina studija: 1
*   Datum: 12.12.2005
*   Verzija: 0.1
********************************************/

/***********************************************************
*
*  Napisati program koji za N gradova, koji su povezani kruznim putem,
*  i za koje se zna cena putovanja od jednog do drugog grada i cena frizidera
*  u svakom gradu, odredjuje u kom gradu je najekonomicnije kupiti
*  frizider, ako se zna u kom gradu se kupac nalazi. U cenu puta uracunat
*  je i povratak. Program napisati na jeziku C!
*
************************************************************/


#include <stdio.h>
#define MAX_NIZ 50

main () {

    /******************************************
    *
    *  Definisanje enumeracije
    *
    ******************************************/
    enum pozneg {NEG, POZ};

    /***********************************************************************
    *
    *       Deklaracija promenljivih
    *  n je broj gradova
    *  fridz je niz sa cenama frizidera u svakom gradu
    *  put je niz sa cenom puta do svakog grada
    *  i, j je brojac za petlju
    *  grad je broj grada gde se kupac nalazi
    *  eko1 i eko2 su nizovi sa ukupnim cenama frizidera sa putovanjem
    *                   u oba smera (eko1 je pozitivan smer, a eko2 negativan)
    *  sumput je ukupna cena svih putovanja (putovanje u krug)
    *  min1 i min2 su najmanji clanovi nizova eko1 i eko2
    *  min je najmanja cena iz oba pravca
    *  pozneg pamti najekonomicniji smer kretanja kupca
    *  eko1grad i eko2grad pamte broj najekonomicnijeg grada
    *  ekograd je broj najekonomicnijeg grada uopste
    *  again je pomocna promenljiva za ponavljanje programa ako to korinsik zeli
    *
    **********************************************************************/
    float fridz[MAX_NIZ], put[MAX_NIZ], eko1[MAX_NIZ], eko2[MAX_NIZ], sumput, min1, min2, min;
    int n, i, j, grad, pozneg, eko1grad, eko2grad, ekograd;
    char again = 'y';

    /*****************************************
    *
    *  Uvodna konverzacija
    *
    *****************************************/
    printf("Program za odredjivanje najekonomicnije kupovine frizidera!");

    while (again=='y')
    {
            /*****************************************
            *
            *  Inicijalizacija niza
            *
            ******************************************/
            for (i=0; i<MAX_NIZ; i++) fridz[i] = put[i] = eko1[i] = eko2[i] = 0;

            /****************************************
            *
            *  Unos broja gradova
            *
            ****************************************/
            printf("\nUnesite broj gradova: ");
            scanf("%d", &n);
            while (n<=0 || n>MAX_NIZ) {
                printf("Unos je van opsega! Unesite ponovo broj gradova: ");
                scanf("%d", &n);
            }

            /**************************************
            *
            *  Unos cena frizidera u svakom gradu
            *
            **************************************/
            printf("\n\tUnos cena frizidera u svakom gradu\n");
            for (i=0; i<n; i++) {
                printf("Unesite cenu frizidera u gradu %d: ", i+1);
                scanf("%f", &fridz[i]);
                while (fridz[i]<0) {
                    printf("\n\tCena ne moze biti negativna! Unesite cenu frizidera u gradu %d: ", i+1);
                    scanf("%f", &fridz[i]);
                    }
                }

            /***************************************
            *
            *  Unos cena puta izmedju svakog grada i racunanje
            *  ukupne cene ako bi se obisao krug kroz sve gradove
            *
            ***************************************/
            printf("\n\tUnos cena puta izmedju svaka dva grada!\n");
            for (sumput = 0, i=0; i<n; i++) {
                if (i==(n-1)) {
                    printf("Unesite cenu puta izmedju gradova %d i 1 : ", i+1);
                    scanf("%f", &put[i]);
                    while (put[i]<0) {
                        printf("\n\tCena ne moze biti negativna. Unesite cenu puta izmedju gradova %d i 1 : ", i+1);
                        scanf("%f", &put[i]);
                    }

                }
                else {
                    printf("Unesite cenu puta izmedju gradova %d i %d : ", i+1, i+2);
                    scanf("%f", &put[i]);
                    while (put[i]<0) {
                        printf("\n\tCena ne moze biti negativna. Unesite cenu puta izmedju gradova %d i %d : ", i+1, i+2);
                        scanf("%f", &put[i]);
                    }
                }
                sumput += put[i];
            }

            /*****************************************
            *
            *  Unos grada gde se kupac nalazi
            *
            *****************************************/
            printf("\n\tU kom gradu se kupac nalazi? ");
            scanf("%d", &grad);
            while (grad<=0 || grad>n) {
                printf("Unesti grad je izvan opsega! U kom gradu se kupac nalazi? ");
                scanf("%d", &grad);
                }
                grad--; /*oduzimanjem jedinice od rednog broja grada dobijamo index grada u nizu */

            /*****************************************
            *
            *  Kreiranje niza cena u svim gradovima zajedno sa
            *  putovanjem do tih gradova u pozitivnom smeru
            *  (suprotan kretanju kazaljke na satu)
            *
            *****************************************/
            for (i=0; i<n; i++) {
                /*************************************
                *
                *  U gradu gde se kupac nalazi troskovi su jednaki
                *  ceni frizidera u tom gradu
                *
                **************************************/
                if (i==grad) {
                    eko1[i] = fridz[i];
                }
                else {

                    /**********************************************************************
                    *
                    *  Ako do nekog grada moramo stici prolazeci kroz kraj kruga (put od poslednjeg do
                    *  prvog grada) onda od ukupne cene putovanja kroz ceo krug oduzimamo cenu puta
                    *  koji kupac ne mora da predje da bi stigao do odredjenog grada i dodajemo cenu
                    *  frizidera u tom gradu
                    *
                    ***********************************************************************/
                    if (i<grad) {
                            eko1[i] = sumput;
                            for (j=i; j<grad; j++) eko1[i] -= put[j];
                            eko1[i] += fridz[i];
                            }
                    /***********************************************************************
                    *
                    *  Ako se do grada moze stici u pozitivnom smeru bez prolaska kroz kraj kruga (put
                    *  od poslednjeg do prvog grada) onda saberemo cenu svakog puta koji kupac treba
                    *  da prodje da bi stigao do odredjenog grada i dodamo cenu frizidera u tom gradu
                    *
                    ************************************************************************/
                    if (i>grad) {
                        for (j=grad; j<i; j++) eko1[i] += put[j];  ;
                        eko1[i] += fridz[i];

                        }
                    }
            }

            /*****************************************
            *
            *  Kreiranje niza cena u svim gradovima zajedno sa
            *  putovanjem do tih gradova u negativnom smeru
            *  (smer kretanja kazaljke na satu)
            *
            *****************************************/
            for (i=0; i<n; i++) {
                /*************************************
                *
                *  U gradu gde se kupac nalazi troskovi su jednaki
                *  ceni frizidera u tom gradu
                *
                **************************************/
                if (i==grad) {
                    eko2[i] = fridz[i];
                    }
                    else {
                        /**********************************************************************
                        *
                        *  Ako do nekog grada moramo stici prolazeci kroz kraj kruga (put od prvog do
                        *  poslednjeg grada) onda od ukupne cene putovanja kroz ceo krug oduzimamo cenu puta
                        *  koji kupac ne mora da predje da bi stigao do odredjenog grada i dodajemo cenu
                        *  frizidera u tom gradu
                        *
                        ***********************************************************************/
                        if (i>grad) {
                            eko2[i] = sumput;
                            for (j=grad; j<i; j++) eko2[i] -= put[j];
                            eko2[i] += fridz[i];
                    }
                    else
                        /***********************************************************************
                        *
                        *  Ako se do grada moze stici u pozitivnom smeru bez prolaska kroz kraj kruga (put
                        *  od prvog do poslednjeg) onda saberemo cenu svakog puta koji kupac treba
                        *  da prodje da bi stigao do odredjenog grada i dodamo cenu frizidera u tom gradu
                        *
                        ************************************************************************/
                        if (i<grad) {
                            for (j=i; j<grad; j++) eko2[i] += put[j];
                            eko2[i] += fridz[i];
                        }
                }
            }


            /*******************************************
            *
            *  Trazenje najmanjeg clana nizova eko1 i eko2
            *  i broja najekonomicnijeg grada
            *
            ******************************************/
            for (eko1grad = 0, eko2grad = 0, min1 = eko1[0], min2 = eko2[0], i=1; i<n; i++) {
                if (eko1[i]<min1) {
                    min1 = eko1[i];
                    eko1grad = i;
                    }
                if (eko2[i]<min2) {
                    min2 = eko2[i];
                    eko2grad = i;
                    }
            }

            /*******************************************
            *
            *  Odredjivanje najmanje cene kod oba smera i broja
            *  grada koji je najekonomicniji i odredjivanje pravca
            *  u kom kupac treba da se krece
            *
            *******************************************/
            if (min1<min2) {
                min = min1;
                ekograd = eko1grad;
                pozneg = POZ;
                }
                else {
                    min = min2;
                    ekograd = eko2grad;
                    pozneg = NEG;
                }


            /*****************************************
            *
            *  Ispis rezultata na ekranu
            *
            *****************************************/
            if (min1==min2) {
                printf("\n\n\tPostoji vise gradova za koje je cena frizidera ista! Na primer kupac moze ici u \n grad %d krecuci ", eko1grad);
                printf("se u smeru kazaljke na satu, a moze ici i u %d grad\n krecuci se u smeru su smeru suprotnom od smera ", eko2grad);
                printf("kretanja kazaljke na satu! Cena u oba grada je %.2f", min);

            }
            else {
                if (grad==ekograd) printf("\n\n\tNajekonomicnije je da kupac kupi frizider u svom gradu!\n");
                else {
                    printf("\n\n\tNajekonomicnije grad za kupovinu frizidera je %d, i treba da\n idete u smeru ", ekograd+1);
                    if (pozneg==NEG) printf("suprotnom od ");
                    printf("kretanja kazaljke na satu! Cena je %.2f", min);
                }
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


    /********************************
    *
    *  KRAJ PROGRAMA
    *
    ********************************/
    printf("\n\n\tKRAJ PROGRAMA\n\n");
    return 0;

}
