/*******************************************
*   Ime i Prezime: Bojan Delic
*   Broj indexa: 11510
*   Godina studija: 1
*   Datum: 28.11.2005
*   Verzija: 0.1
********************************************/

/*******************************************
*
*  n.P. koji omogucava unos n brojeva i izracunava srednju vrednost
*  pozitivnih brojeva medju njima iskljucujuci sve one koji su minimalni
*  ili maximalni! (bez nizova)
*
********************************************/

#include <stdio.h>

main () {
    int n, i, br, brmin=0, brmax=0, brneg=0;
    double a, sum=0, min, max, p;
    char again = 'y';
    /****************************************
    *
    *  n je broj brojeva koji se unose
    *  i je pomocna promenljiva za bor petlju
    *  br je broj onih koji ispunjavaju uslov
    *  brmin je broj minimalnih
    *  brmax je broj maximalnih
    *  brneg je broj negativnih
    *  a je promenljiva za ucitavanje svakog broja
    *  sum je zbir svih pozitivnih brojeva, i posle onih koji ispunjavaju kriterijum
    *  min je najmanji od svih unesenih brojeva
    *  max je najveci od svih unesenih brojeca
    *  p je prosek brojeva koji zadovoljavaju kriterijum
    *
    ****************************************/


    /***************************************
    *
    *  Pocetna konverzacija
    *
    ***************************************/
    printf("Program za racunanje proseka pozitivnih brojeva bez minimuma i maximuma!\n");


    while (again=='y')
    {
                /********************************
                *
                *  Dodeljuje promenljivima vrednost nula
                *  da ne bi zadrzale vrednost iz prethodnog
                *  ponavljanja!
                *
                ********************************/
                br=0; brmin=0; brmax=0; brneg=0;
                sum=0;


                /**************************************
                *
                *  Unos broja brojeva za obradu
                *
                **************************************/
                printf("\nKoliko imate brojeva? ");
                scanf("%d", &n);
                while ((n<=0) && (n>=500))
                {
                    printf("Broj je izvan opsega! Unesite ponovo koliko imate brojeva: ");
                    scanf("%d", &n);
                }


                /*************************************
                *
                *  Petlja za unos brojeva i njihovu obradu
                *  U petlji se trazi minimalni, maximalni,
                *  broj minimalnih i maximalnih, zbir pozitivnih
                *  i broj negativnih!
                *
                *************************************/
                for (i=1; i<=n; i++) {

                    /*************************
                    *
                    * Unos svakog broja
                    *
                    *************************/
                    printf("\nUnesite %d. broj: ", i);
                    scanf("%lf", &a);

                    /***************************************
                    *
                    *  Ako se unosi prvi broj, on je i minimalan i maximalan
                    *
                    ****************************************/
                    if (i==1) {
                        min = a;
                        brmin = 1;
                        max = a;
                        brmax = 1;
                        }
                        /**************************************
                        *
                        *  a ako nije prvi, onda se proverava da li je unesen
                        *  broj  veci od maximuma ili manji od minimuma i na
                        *  osnovu toga odredjuje minimum i maximum!
                        *  Ako je unesen broj jedank minimumu ili maximumu
                        *  broj minimalnih ili maximalnih se povecava za jedan!
                        *
                        **************************************/
                        else
                        {
                            if (a==min) brmin++;
                            if (a==max) brmax++;
                            if (a>max) {
                                max = a;
                                brmax = 1;
                                }
                            if (a<min) {
                                min = a;
                                brmin = 1;
                                }

                        }
                    /************************************
                    *
                    *  Ako je unseseni broj pozitivan, dodaje ga sumi
                    *  a ako nije, povecava broj negativnih za jedan
                    *
                    ************************************/
                     if (a>=0) sum += a;
                        else brneg++;

                }



                /***************************************
                *
                *  U zavisnosti od toga da li su minimalni i maximalni
                *  pozitivni ili negativni, racuna se suma onih koji ispunjavaju
                *  kriterijum i broj onih koji ispunjavaju kriterijum!
                *
                ***************************************/
                if (min>0) sum -= brmin*min;
                if (max>0) sum -= brmax*max;
                if (min<0) br = n - (brneg + brmax);
                    else
                    br = n - (brneg + brmin + brmax);

                /**************************************
                *
                *  Moze da se desi da su svi brojevi isti
                *  pa ce tada broj onih koji ispunjavaju
                *  kriterijum biti negativan. Zbog toga se
                *  koristi sledeci uslov!
                *
                ***************************************/
                if (br<0) br = 0;
                 /***************************************
                 *
                 *  Ako je maximalnan manji od nule, broj onih koji
                 *  zadovoljavaju uslov je nula
                 *
                 ****************************************/
                if (max<0) br = 0;

                /****************************************
                *
                *  Proverava da li je broj onih koji ispunjavaju kriterijum
                *  razlicit od nule (jer deljenje nulom nije dozvoljeno)
                *  i racuna prosek!
                *
                ****************************************/
                if (br != 0) {
                    p = sum / br;
                    }

                /***************************************
                *
                *  Ako postoji trazeni prosek ispisuje ga, u suprotnom
                *  ispisuje odgovarajucu poruku!
                *
                ***************************************/
                if (br !=0) printf("\n\nProsek trazenih brojeva je %.2lf!\n\n", p);
                    else printf("\n\nne postoje brojevi koji ispunjavaju uslov!\n\n");


                /**************************************
                *
                *  Provera da li korisnik zeli da ponovi program
                *
                **************************************/
                printf("\nDa li zelite da ponovite program? (y/n) : ");
                scanf("%c", &again);
                scanf("%c", &again);
                while (again!='y' && again!='n')
                {
                    printf("\nPOGRESAn UnOS! Da li zelite da ponovite program? (y/n): ");
                    scanf("%c", &again);
                    scanf("%c", &again);
                }
    }
    /**************************
    *
    *  KRAJ PROGRAMA
    *
    **************************/
    printf("***KRAJ PROGRAMA***\n\n");

    return 0;
}
