/*******************************************
*   Ime i Prezime: Bojan Delic
*   Broj indexa: 11510
*   Godina studija: 1
*   Datum: 16.11.2005
*   Verzija: 0.1
********************************************/

/*******************************************
*
*  Program koji za unesena dva vremena u formatu
*  hh:mm:ss racuna koje je vreme manje i ispisuje
*  razliku veceg i manjeg u istom formatu
*
********************************************/

#include <stdio.h>


main () {
    /*********************************************
    *
    *          Deklaracija promenljivih
    *  h, m i s sluze za sate, minute i sekunde razlike vremena
    *  h1, m1 i s1 sluze za sate minute i sekunde prvog vremena
    *  h2, m2 i s2 sluze za sate i minute drugog vremena
    *  sek1 je prvo vreme u sekundama
    *  sek2 je drgo vreme u seknudama
    *  sek je razlika ova dva vremena
    *  again je pomocna promenljiva za ponavljanje programa ako to korisnik zeli
    *
    **********************************************/
    int h, m, s, h1, m1, s1, h2, m2, s2, sek1, sek2, sek;
    char again='y';

        /************************************
        *
        *  uvodna konverzacija
        *
        *************************************/
        printf("\n**Program za racunanje razlike dva vremena**");

        while (again=='y') {
            /********************************
            *
            *  unos prvog vremena
            *
            ********************************/
            printf("\n\tUnesite prvo vreme u obliku hh:mm:ss: ");
            scanf("%2d:%2d:%2d", &h1, &m1, &s1);

            /********************************
            *
            *  unos drugog vremena
            *
            ********************************/
            printf("\tUnesite drugo vreme u obliku hh:mm:ss: ");
            scanf("%2d:%2d:%2d", &h2, &m2, &s2);

            /*********************************
            *
            *  racunanje oba vremena u sekundama
            *
            **********************************/
            sek1 = h1*3600+m1*60+s1;
            sek2 = h2*3600+m2*60+s2;

            /***********************************
            *
            *  racunanje razlike veceg od manjeg vremena u sekundama
            *
            *************************************/
            if (sek1>sek2) {
                sek = sek1 - sek2;
                }
                else {
                    if (sek2>sek1) {
                        sek = sek2 - sek1;
                        }
                        else {
                            sek = 0;
                            }
                        }




            /**************************************
            *
            * vracanje razlike u normalan oblik vremena
            *
            ***************************************/
            h = sek/3600;       //racunanje broja sati

            s = sek%60;     //racunanje broja sekundi

            m = (sek-h*3600)/60;    //racunanje broja minuta



            /******************************************
            *
            *  ispisivanje razlike dva vremena
            *
            *******************************************/
            printf("\n\nRazlika vremena je : %02d:%02d:%02d !\n\n", h,m,s);


            /******************************************
            *
            *  provera da li korisnik zeli da ponovo izvrsi program
            *
            *******************************************/
            scanf("%c", &again);
            printf("Da li zelite da ponovo izvrsite program? (y/n)");
            scanf("%c", &again);
            while (again!='y' && again!='n') {
            scanf("%c", &again);
                printf("\n\tUnesite 'y' za da ili 'n' za ne!");
                printf("\n Da li zelite da ponovo izvrsite program? (y/n)");
                scanf("%c", &again);
                }

    }

    /********************************
    *
    *  KRAJ PROGRAMA
    *
    *********************************/
    printf ("\n\t****KRAJ PROGRAMA***\n\n");


}
