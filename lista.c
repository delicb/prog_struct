/*******************************************
*   Ime i Prezime: Bojan Delic
*   Broj indexa: 11510
*   Godina studija: 1
*   Datum: 11.1.2006
*   Verzija: 0.1
********************************************/

#include <stdio.h>
#define MAX 5
/************************************************************************************
*
*  Napisati C program koji demonstrira realizaciju osnovnih operacija sa dinamickom strukturom podataka
*  oblika jednostruko spregnute liste. Element liste se sastoji od dva polja: podatak koji predstavlja ceo broj
*  i pokazivac na sledeci element liste.
*  Operacije koje treba realizovati sa jednostruko spregnutom listom su:
*  - unos novog broja, po izboru korisnika (na pocetak ili kraj liste) (NAPOMENA: Zadovoljiti uslov da se u listi
*       ne moze nalaziti vise od 5 istih brojeva)
*  - modifikacija (umesto jednog broja treba upisati drugi broj)
*  - trazenje broja u listi
*  - brisanje broja iz liste (ako ima vise istih, izbrisati ih sve)
*  DODATNO: Napraviti tabelarni prikaz pojavljivanja brojeva u listi
*
*************************************************************************************/

/**************************************************
*
*  struktura podataka za listu
*  broj sadrzi podatak
*  sledeci je pokazivac na sledeci elenetan liste
*
**************************************************/
typedef struct cvor {
    int broj;
    struct cvor *sledeci;
    } Tcvor;

/*************************
*
*  Pokazivac na cvor
*
**************************/
typedef Tcvor *Pcvor;

/**************************************************
*
*  Prototipovi funkcija (detalji su u samim funkcijama)
*
**************************************************/
void ini (Pcvor *);
void unosKr (Pcvor *);
void unosPoc (Pcvor *);
void unosPrvi (Pcvor *);
void ispis (Pcvor);
void mod (Pcvor);
void trazi (Pcvor);
void brisi (Pcvor *);
void osobodiMem (Pcvor *);
int opcije(void);
int prebroj(Pcvor, int);
void brPov(Pcvor);


main () {
    /********************************************************************************
    *
    *  Definicija promenljivih
    *  glava je pokazivac na prvi element liste (kad je lista prazna glava pokazuje na NULL
    *  izbor je promenljiva koja sluzi za biranje opcija iz menija
    *
    ********************************************************************************/
    Pcvor glava;
    int izbor;

    /**********************************************************
    *
    *  Uvodna konverzacija
    *
    **********************************************************/
    printf("\nProgram za prezentaciju osnovnih operacija jednostruko spregnute liste!\n\n");

    /***************************************
    *
    *  Inicijalizacija liste
    *
    ***************************************/
    ini (&glava);

    /*******************************************************************
    *
    *  Prikazivanje menija na ekranu i izvrsavanje operacija koje korisnik zahteva
    *  sve dok korisnik ne izabere kraj
    *
    ********************************************************************/
        do {
            izbor = opcije();
            switch (izbor) {
                case 1: unosPoc(&glava);
                            break;
                case 2: unosKr(&glava);
                            break;
                case 3: mod(glava);
                            break;
                case 4: trazi(glava);
                            break;
                case 5: brisi(&glava);
                            break;
                case 6: ispis(glava);
                            break;
                case 7: brPov(glava);
                            break;
                case 8: ;

            }
        } while (izbor!=8);

        /***************************************
        *
        *  Oslobadjanje zauzete memorije
        *
        ****************************************/
        osobodiMem(&glava);

/************************************
*
*  Kraj programa
*
************************************/
printf("\n\n***KRAJ PROGRAMA***\n\n\n");
return 0;

}





/******************************************************************
*
*  Funkcija: ini
*  Svrha: postavlja vodeci pokazivac (glava) na NULL, odnosno inicijalizuje listu
*
******************************************************************/
void ini (Pcvor *glava) {
    *glava = NULL; /*postavljanje glave liste da pokazuje na NULL, odnosno na nista*/
}





/******************************************************************
*
*  Funkcija: unosKr
*  Svrha:  unos novog clana liste i smestanje na kraj
*
******************************************************************/
void unosKr (Pcvor *glava) {
    /***************************************************************************
    *
    *  Definicija lokalnih promenljivih
    *  tek je tekuci element liste, a pret je prethodni (prethodni uvek kasni za 1 u odnosu na tekuci)
    *  novi je element koji je unosi
    *  k je broj koji se unosi
    *
    ****************************************************************************/
    int k;
    Pcvor tek, pret, novi;

        printf("\nUnos elementa na kraj liste!\n");

        /*ako se utvrdi da je lista prazna poziva se funkcija za unos prvog clana*/
        if (*glava==NULL) unosPrvi (glava);
            /*a ako lista nije prazna clan se dodaje na kraj*/
            else {
                /*prolazak kroz listu i dolazak do poslednjeg unesenog elementa*/
                tek = *glava;
                while (tek != NULL) {
                    pret = tek;
                    tek = tek->sledeci;
                }

                /*********************************************************************
                *
                *  Zauzimanje dinamicke memorije za novi clan liste, ucitavanje
                *  broja sa tastature, postaljanje pokazivaca na sledeci element
                *  na NULL i pokazivaca prethodnog elementa na upravo uneseni element
                *
                ********************************************************************/
                printf("Unesite sledeci element (smesta se na kraj): ");
                scanf("%d", &k);
                if (prebroj(*glava, k)<MAX) {
                        novi = (Tcvor *)malloc(sizeof(Tcvor));
                        novi->broj = k;
                        novi->sledeci = NULL;
                        pret->sledeci = novi;
                }
                else printf("\n\tBroj se pojavljivao maximalan broj puta! Nije dozvoljen unos ovog broja!");
    }
}





/******************************************************************
*
*  Funkcija: unosPoc
*  Svrha:  unos novog clana liste i smestanje na pocetak
*
******************************************************************/
void unosPoc(Pcvor *glava) {
    /**************************************************************
    *
    *  Definisanje lokalnih promenljivih
    *  novi je element koji se dodaje u listu
    *  k je novi broj koji se unosi
    *
    **************************************************************/
    int k;
    Pcvor novi;

    printf("\nUnos elementa na pocetak liste!\n");

    /*ako se utvrdi da je lista prazna poziva se funkcija za unos prvog clana*/
    if (*glava==NULL) unosPrvi(glava);
        /*a ako lista nije prazna, elemet se unosi na pocetak liste*/
        else {
        /********************************************************
        *
        *  Zauzimanje dinamicke memorije za novi element liste, ucitavanje novog
        *  elementa sa tastature, postavljanje glave da pokazuje na taj novi element,
        *  i postavljanje pokazivaca novog elementa da pokazuje da dosadasnji
        *  prvi element, koji je sad drugi
        *
        ********************************************************/
        printf("Unesite sledeci elementa liste (smesta se na pocetak): ");
        scanf("%d", &k);
        if (prebroj(*glava, k)<MAX) {
                novi = (Tcvor *)malloc(sizeof(Tcvor));
                novi->broj = k;
                novi->sledeci = *glava;
                *glava = novi;
                }
                else printf("\n\tBroj se pojavljivao maximalan broj puta! Nije dozvoljen unos ovog broja!");
    }

}






/********************************************************
*
*  Funkcija: unosPrvi
*  Svrha:  Sluzi za unos elementa ukoliko je lista prazna
*           nema je smisla pozivati bez prethode prove da li glava pokazuje
*           na NULL
*
*********************************************************/
void unosPrvi (Pcvor *glava) {
        /**************************************************************
        *
        *  Definisanje lokalnih promenljivih
        *  novi je element koji se dodaje u listu
        *
        **************************************************************/
        Pcvor novi;

        /*************************************************************
        *
        *  Zauzimanje dinamicke memorije za prvi element u listi, unos sa tastature,
        *  postavljanje njegovog pokazivaca na NULL i postavljanje glave da pokazuje
        *  ne njega
        *
        *************************************************************/
        novi = (Tcvor *)malloc(sizeof(Tcvor));
        printf("Unesite prvi element liste: ");
        scanf("%d", &novi->broj);
        novi->sledeci = NULL;
        *glava = novi;

}





/*********************************************************
*
*  Funckija: ispis
*  Svrha:  ispisivanje na ekranu svih clanova liste
*
*********************************************************/
void ispis (Pcvor glava) {
    /***************************************************************************
    *
    *  Definicija lokalnih promenljivih
    *  tek je tekuci element liste, a pret je prethodni (prethodni uvek kasni za 1 u odnosu na tekuci)
    *
    ****************************************************************************/
    Pcvor tek, pret;

    /*lista je prazna ako glava pokazuje na NULL*/
    if (glava==NULL) printf("\nLista je prazna\n");
    /*a ako nije prazna ispisujemo listu*/
    else {

        /*************************************************************
        *
        *  tek se krece kroz listu dok ne naidje na pokazivac sa vrednoscu NULL, a
        *  pret ga prati i ispisuje se broj na koji pokazuje prethodni.
        *  Ispis se zavrsava kad tek dodje do poslednjeg elementa. Tada pret pokazuje
        *  na poslednji element, a tek ima vrednost pokazivaca poslednjeg elementa,
        *  odnosno NULL.
        *
        *************************************************************/
        printf("\nIspis liste:\n");
        tek = glava;
        while (tek !=NULL) {
            pret  = tek;
            printf("\t%d", pret->broj);
            tek = tek->sledeci;
            }
    }
}





/******************************************************************
*
*  Funkcija: mod
*  Svrha: menja zadati broj za drugim zadatim brojem na svakom mestu gde se pojavljuje
*
******************************************************************/
void mod (Pcvor glava) {
    /*************************************************************
    *
    *  Definicjia lokalnih promenljivih
    *  k je broj koji se modifikuje
    *  n je broj koji zamenjuje k
    *  tek je tekuci element liste, a pret je prethodni (prethodni uvek kasni za 1 u odnosu na tekuci)
    *  br je broj modifikovanih elemenata
    *
    *************************************************************/
    int k, n, br=0;
    Pcvor tek, pret;

    printf("\nModifikacija broja iz liste!\n\n");

    /*ako glava pokazuje na NULL lista je prazna, pa nema sta da se modifikuje*/
    if (glava==NULL) {
        printf("\n\tLista je prazna. Nema elemenata za modifikovanje!\n");
    }
    /*a ako nije prazna, unosi se broj koji treba modifikovati, i broj u koji se modifikuje taj broj*/
    else {
            printf("\tUnesite broj koji hocete da promenite\n\t (promenice se na svim lokacijama gde se pojavljuje): ");
            scanf("%d", &k);
            printf("\tUnesite broj sa kojim hocete da zamenite broj %d : ", k);
            scanf("%d", &n);

            if ((prebroj(glava, k) + prebroj(glava, n))<=MAX) {

                    /*************************************************************
                    *
                    *  tek prolazi kroz celu listu dok ne naidje na element sa pokazivacom NULL
                    *  (poslednji element), a pret ga prati i proverava da li je element jednak
                    *  broj koji treba modifikovati, i ako jeste menja mu vrednost.
                    *  Petlja se prekida kad tek dobije vrednost NULL. Tada pret pokazuje na posednji
                    *  element, a tek ima vrednost pokazivaca poslednjeg elementa, odnosno NULL.
                    *
                    *************************************************************/
                    tek = glava;
                    while (tek != NULL) {
                            pret = tek;
                            if (pret->broj==k) {
                                pret->broj = n;
                                br++;
                                }
                            tek = tek->sledeci;
                        }

                    if (br==0) printf("\n\tNi jedan element nije modifikovan!\n");
                        else printf("Broj elemenata koji su modifikovani je: %d!\n", br);
            }
            else printf("\n\n\tUkoliko se izvrsi modifikacija, broj %d ce se\n\tpojavljivati u listi vise puta nego sto je to dozvoljeno!", n);

        }
}






/*******************************************************
*
*  Funkcija: trazi
*  Svrha: proverava da li se odredjeni broj nalazi u listi
*
*******************************************************/
void trazi (Pcvor glava) {
    /********************************************************************************
    *
    *  Definisanje lokalnih promenljivih i enumeracije
    *  k je broj koji se trazi
    *  n pamti da li je broj pronadjen broj u listi
    *  tek je tekuci element liste, a pret je prethodni (prethodni uvek kasni za 1 u odnosu na tekuci)
    *  br je broj pojavljivanja trazenog elementa u listi
    *
    ********************************************************************************/
    int k, br=0;
    Pcvor tek, pret;


    printf("\nPretraga liste!\n\n");

    /*ako glava pokazuje na NULL lista je prazna i nema sta da se pretrazuje*/
    if (glava==NULL) {
        printf("\n\tLista je prazna. Nema elemenata za pretragu!\n");
        }
        /*a ako nije prazna unosi se broj koji se trazi*/
        else {

                printf("\tKoji broj zelite da nadjete u listi? ");
                scanf("%d", &k);
                tek = glava;

                /**********************************************************
                *
                *  tek i pret prolaze kroz listu (pret kasni za tek) i proverava se za svaki
                *  element liste da li je jedank trazenom broju. Ako jeste brojac se uvecava
                *  za jedan.
                *
                **********************************************************/
                while (tek != NULL) {
                    pret = tek;
                    if (pret->broj==k) {
                            br++;
                        }
                        tek = tek->sledeci;
                }

                /***********************************************************
                *
                *  Ako je brojac jedank nuli, ne postoji u listi element koji se trazi, a ako nije
                *  ispisuje se koliko puta se taj element pojavljuje
                *
                ***********************************************************/
                if (br==0) printf("\n\tTrazeni broj ne postoji u listi!\n");
                    else printf("\n\tBroj puta koliko se broj %d pojavljuje u listi je: %d!\n", k, br);


    }
}





/**********************************************************
*
*  Funkcija: brisi
*  Svrha: brise broj koji je korisnik zadao iz liste gde god se pojavi
*
**********************************************************/
void brisi (Pcvor *glava) {
    /*****************************************************************
    *
    *  Definisanje lokalnih promenljivih
    *  enumeracija sluzi za lakse pamcenje da li jos ima elementa u listi koje treba brisati
    *  k je broj koji treba obrisati
    *  n pamti da li ima jos elemenata koje treba brisati
    *  br je broj obrisanih
    *  tek i pret su pokazivaci na cvorove koji prolaze kroz listu
    *
    ******************************************************************/
    enum {NEMA, IMA};
    int k, n=IMA, br=0;
    Pcvor tek, pret;

    printf("\nBrisanje elementa iz liste!\n\n");

    /*ako je lista prazna, nema sta da se brise*/
    if (*glava==NULL) {
        printf("\n\tLista je prazna. Nema elemenata za brisanje!\n");
        }

        /*a ako nije, unosi se broj koji treba obrisati*/
        else {

            printf("\n\tKoji broj zelite da obrisete (bice obrisan sa svih lokacija)? ");
            scanf("%d", &k);

            /*ova petlja se ponavlja dok ima elemenata za brisanje*/
            while (n==IMA) {
                    /*trazi element koji odgovara uslovima za brisanje*/
                    tek = *glava;
                    pret = *glava;
                    while ((tek!=NULL) && (tek->broj !=k)) {
                        pret = tek;
                        tek = tek->sledeci;
                    }

                    /*ako tek pokazuje na NULL znaci da je pretraga dosla do kraja i da nije
                    pronadjen ni jedan element za brisanje, pa se n postavlja na vresnost nema*/
                    if (tek==NULL) {
                        n = NEMA;
                        }
                        /*u suprotnom ako je element za brisanje prvi element liste, glava se postavlja da pokazuje na drugi
                        element, a pokazivacu prvog se dodeljuje vrenost NULL*/
                        else {
                            if (tek==*glava) {
                                *glava = tek->sledeci;
                                tek->sledeci = NULL;

                            }
                            /*ako nije brvi element u pitanju, pokazivacu njegovog prethodnika se daje vrednost njegovog pokazivaca
                            (njegov sledbenik), a njegov pokazivac se postavlja na NULL*/
                            else  {
                                pret->sledeci = tek->sledeci;
                                tek->sledeci = NULL;
                            }
                            /*i na kraju i fizicki oslobadjamo memoriju koju je zauzimao taj element*/
                            free(tek);
                            /*povecavamo broj obrisanih za jedan*/
                            br++;
                        }

            }
        if (br==0) printf("\n\tNi jedan element nije obrisan\n");
            else printf("\n\tBroj lokacija sa kojih je broj %d izbrisan je: %d!\n", k, br);
        }
}





/*********************************************************
*
*  Funkcija osobodiMem
*  Svrha: brise celu listu iz dinamicke memorije
*
*********************************************************/
void osobodiMem (Pcvor *glava) {
    /**************************************************
    *
    *  Definisanje lokalnih promenljivih
    *  tek je cvor koji se trenutno brise (prvi clan liste)
    *
    ***************************************************/
    Pcvor tek;

        /****************************************************************
        *
        *  Oslobadjanje memorije se vrsi tako sto se brise prvi element iz liste, drugi se
        *  postavlja da bude prvi i to se ponavlja dok svi elementi ne budu izbrisani.
        *  Posto glava uzima vrednost pokazivaca prvog elementa, imace vrednost NULL kada
        *  se poslednji element obrise. Samim tim i znamo da je lista prazna, jer glava ima
        *  vrednost NULL.
        *
        *****************************************************************/
        if (*glava!=NULL) {
            while (*glava!=NULL) {
                tek = *glava;
                *glava = tek->sledeci;
                free(*glava);
            }
    }
}





/**********************************************************
*
*  Funkcija: opcije
*  Svrha:  prikazijavnje osnovnog menije za izbor
*
**********************************************************/
int opcije () {
    /***********************************************************************************
    *
    *  Definicija lokalnih promenljivih
    *  izbor je promenljiva koji pamti sta je izabrano iz menija i to je vrednost koju f-ja vraca
    *
    ************************************************************************************/
    int izbor;

    /*ispisivanje menija i ucitavanje vredosti koju je korisnik uneo sa tastature*/
    printf("\n\t1) Dodaj na pocetak\n\t2) Dodaj na kraj\n\t3) Modifikuj\n\t4) Pretrazi\n\t5) Obrisi\n\t6) Ispisi\n\t7) Tabelarni prikaz\n\t8) Kraj\n");
    printf("\n\tIzaberite opciju: ");
    scanf("%d", &izbor);
    //izbor = getchar();

    while ((izbor>8) && (izbor<1)) {
        printf("\t\tNe postoji ta opcija!");
        printf("\n\t1) Dodaj na pocetak\n\t2) Dodaj na kraj\n\t3) Modifikuj\n\t4) Pretrazi\n\t5) Obrisi\n\t6) Ispisi\n\t7) Tabelarni prikaz\n\t8) Kraj\n");
        printf("\n\tIzaberite opciju: ");
        scanf("%d", &izbor);
        //izbor = getchar();

    }

    /*vracanje ucitane vrednosti*/
    return izbor;

}






/*********************************************************************
*
*  Funkcija: prebroj
*  Svrha: broji koliko puta se u listi pojavljuje neki clan
*
*********************************************************************/
int prebroj (Pcvor glava, int broj) {
    /*******************************************************
    *
    *  Definisanje lokalnih promenljivih
    *  br pamti broj ponavljanja nekog broja u listi
    *  tek i pret sluze za prolazak kroz listu
    *
    *******************************************************/
    int br=0;
    Pcvor tek, pret;

    tek = glava;
    while (tek!=NULL) {
        pret = tek;
        if (pret->broj==broj) br++;
        tek = tek->sledeci;

    }

    return br;

}






/********************************************************************
*
*  Funkcija: brPov
*  Svrha: prikazuje tabelarni prikaz koliko se puta koji broj pojavljivao u listi
*
********************************************************************/
void brPov(Pcvor glava) {
    int k;
    Pcvor tek, pret;

    printf("\n\tTablearni prikaz broja pojavljivanja elemenata u listi!\n");

    tek = glava;
    while (tek!=NULL) {
        pret = tek;
        k = prebroj(glava, pret->broj);
        printf("%d se pojavljivao %d", pret->broj, k);
        if (k==1) printf("put!\n\n");
            else printf("puta!\n\n");
        tek = tek->sledeci;

    }
}
