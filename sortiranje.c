/*******************************************
*   Ime i Prezime: Bojan Delic
*   Broj indexa: 11510
*   Godina studija: 1
*   Datum: 04.12.2005
*   Verzija: 0.1
********************************************/

/*******************************************
*
*  Napisati C program za sortiranje niza
*
********************************************/

#include <stdio.h>
#define MAX_NIZ 50

int main()
{
    /*****************************
    *
    *  definisanje enumeracije
    *
    ******************************/
    enum bool {FALSE, TRUE};

    /*****************************
    *
    *           Inicijalizacija promenljivih
    *  i, k, j, f su brojaci za petlje
    *  n je broj elemenata niza
    *  a je niz koji se unosi
    *  pom se koristi za zamenu vrednosti
    *  again sluzi za ponavljanje programa
    *  za z postoji detaljno objasnjenje u programu
    *  stop sluzi da zaustavi sortiranje ako je niz sortiran
    *
    ******************************/
    int i, k, f, j, n, z, stop;
    double a[MAX_NIZ], pom;
    char again='y';

    /*****************************
    *
    *  Uvodna konverzacija
    *
    *****************************/
    printf("\nProgram za sortiranje niza!\n");

    while (again=='y')
    {

            /*************************
            *
            *  Inicijalizacija niza
            *
            **************************/
            for (i=0; i<MAX_NIZ; a[i++]=0) ;

            /*************************
            *
            *  Unos broja elemenata niza
            *
            *************************/
            printf("Koliko imate elemenata niza? ");
            scanf("%d", &n);
            while ((n<=0) || (n>50))
            {
                printf("Pogresan unos! Koliko imate elemenata niza? ");
                scanf("%d", &n);
            }

            /*************************
            *
            *  Unos niza
            *
            *************************/
            printf("\nUnos niza: \n");
            for (i=0; i<n; i++)
            {
                printf("Unesite %d. clan niza: ", i+1);
                scanf("%lf", &a[i]);
            }

            /***********************************
            *
            *  Ako je niz sortiran, petlja se ni ne izvrsava
            *
            ***********************************/
            stop = TRUE;
            for (f=1; f<n; f++) if (a[f-1]>a[f]) stop = FALSE;
            if (stop)   printf("\n\n\tUneli ste vec sortiran niz!");
                else {

                        /************************
                        *
                        *  Sortiranje niza
                        *
                        ************************/
                                /*******************************
                                *
                                *  Glavna petlja prolazi samo do polovine niza
                                *  jer se istovremeno trazi i najveci i namanji
                                *  u nizu i stavlja na odgovarajuce mesto
                                *
                                *******************************/
                                for (i=0; i<(n/2); i++)
                                {

                                    /*********************************
                                    *
                                    *  Pomocna petlja se krece unutar dva fixsna
                                    *  clana ('i' i 'n-1-i') i uporedjuje svaki clan
                                    *  iz te unutrasnjosti sa rubnim clanivuma
                                    *  i zamenjuje vrednosti, ako je potrebno.
                                    *  Tako na rubna mesta dolaze najmanji i najveci
                                    *  clanovi iz unutrasnjosti!
                                    *
                                    *********************************/

                                    for (k=i+1; k<(n-i); k++)
                                    {


                                                    /***********************************
                                                    *
                                                    *  Prekida petlju ako je niz vec sortiran
                                                    *
                                                    ***********************************/
                                                    stop = TRUE;
                                                    for (f=1; f<n; f++) if (a[f-1]>a[f]) stop = FALSE;
                                                    if (stop) break;

                                                    /****************************************
                                                    *
                                                    *  Ispisuje trenutno stanje niza pre prolaska kroz petlju
                                                    *
                                                    *****************************************/
                                                    printf("\nTrenutno stanje za i = %d i k = %d!\n", i, k);
                                                    for (j=0; j<n; printf("%.2lf\t", a[j++]) ) ;


                                                    /***************************************************
                                                    *
                                                    *  Moze da se desi da ukoliko clan koji posmatramo nije manji
                                                    *  od clana 'i', a jeste veci od clana 'n-1-i'. Ako je tako moze
                                                    *  da se desi da posle zamene novi clan koji se nalazio na
                                                    *  lokaciji 'n-1-i' bude manji od clana na lokaciji 'i', a ta provera
                                                    *  je vec zavrsena. Zvog toga se uvodi promenljiva z1, koja
                                                    *  pamti da li se druga zamena vrednosti desila. Ukoliko jeste
                                                    *  ponavlja se provera da li je taj novi clan manji od clana 'i'.
                                                    *
                                                    *  Na pocetku z1 ima vrednost FALSE jer se ni jedna zamena nije
                                                    *  izvrsila. Kasnije moze da promeni vrednost u drugoj if naredbi!
                                                    *
                                                    *
                                                    ***************************************************/
                                                    z = FALSE;

                                                    /*************************************************
                                                    *
                                                    *  Ako je clan koji posmatramo manji od clana koji se nalazi na mestu
                                                    *  gde treba da bude najmanji, vrsi se zamena vrednosti!
                                                    *
                                                    *************************************************/
                                                    if (a[k]<a[i])
                                                    {
                                                        pom = a[k];
                                                        a[k] = a[i];
                                                        a[i] = pom;
                                                    }


                                                    /*************************************************
                                                    *
                                                    *  Ako je clan koji posmatramo veci od clana koji se nalazi na mestu
                                                    *  gde treba da bude najveci, vrsi se zamena vrednosti, i postalja se
                                                    *  promenliva z1 na TRUE da bi se posle ponovila prva if naredba!
                                                    *
                                                    *************************************************/
                                                    if (a[k]>a[n-1-i])
                                                    {
                                                        pom = a[k];
                                                        a[k] = a[n-1-i];
                                                        a[n-1-i] = pom;
                                                        z = TRUE;
                                                    }

                                                    /************************************************
                                                    *
                                                    *  z1 pamti da i se prethodna if naredba izvrsila. Ukoliko jeste ponovo
                                                    *  proverava da li je clan koji posmatramo veci od clana koji se
                                                    *  nalazi na mestu gde treba da se nadje  najveci! Ako jeste, ponovo
                                                    *  proverava da li je tekuci clan manji od clana koji se nalazi
                                                    *  na mestu gde treba da bude najmanji i ako jeste, menja se vrednost!
                                                    *
                                                    ************************************************/
                                                    if (z)
                                                    {
                                                        if (a[k]<a[i])
                                                        {
                                                            pom = a[k];
                                                            a[k] = a[i];
                                                            a[i] = pom;
                                                            }
                                                    }

                                    }
                            }
                    }

            /*******************
            *
            *  Ispis sortiranog niza
            *
            *******************/
            printf("\n\nSortirani niz: \n");
            for (i=0; i<n; printf("%.2lf\t", a[i++])) ;



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

    /***********************
    *
    *  KRAJ PROGRAMA
    *
    ************************/
    printf("\n\n**KRAJ PROGRAMA**\n\n");
    return 0;
}
