/*******************************************
*   Ime i Prezime: Bojan Delic
*   Broj indexa: 11510
*   Godina studija: 1
*   Datum: 28.11.2005
*   Verzija: 0.1
********************************************/

/*********************************
*
*  Napisati program u jeziku C za vrtanje brodica
*  na osnovu unetog prirodnog neparnog broja
*  Na primer za n=5
*
*         *
*       **
*     ***
*    ****
*  *****
*  ******
*  *******
*  ********
*  *******
*  ******
*    *****
*      ***
*        **
*          *
*
*********************************/

#include <stdio.h>

main()
{
    int r, z, j, i, n, m;
    char again='y';
    /***************************
    *
    *  r je broj razmaka
    *  z je broj zvezdica
    *  i i j su brojaci za for petlje
    *  n je neparan broj koji koridnik unosi
    *  again je pomocna promenljiva koja
    *                       sluzi za ponavljanje programa
    *                       ako korinsik to zeli
    *  m se koristi kod crtanje drugog i treceg dela brodica
    *                   da podeli crtanje na dva dela!
    *
    ***************************/

    /***************************
    *
    *  Pocetna konverzacija
    *
    ***************************/
    printf("**Program za crtanje broda od zvezdica!**");

    while (again=='y')
    {

            /**************************
            *
            *  Unos broja n
            *
            **************************/
            printf("\n\tUnesite neparan broj veci od 3 i manji od 12: ");
            scanf("%d", &n);
            while ((n<=3) || (n>50) || ((n%2)==0))
            {
                printf("\nPogresan unos! Unesite broj ponovo: ");
                scanf("%d", &n);
            }


            /****************************
            *
            *  Ispisivanje prvog dela brodica
            *
            ****************************/
            for (i=1; i<=n; i++)
            {
                r = n - i;
                printf("\t");
                for (j=0; j<r;j++) printf(" ");
                for (j=0; j<i; j++) printf("*");
                printf("\n");

            }

            /****************************
            *
            *  Ispisivanje drugog dela brodica
            *
            ****************************/
            m = (n / 2) + 1;
            for (i=1; i<=m; i++)
            {
                z = n + i;
                printf("\t");
                for (j=0; j<z ; j++)
                {
                    printf("*");
                }
                printf("\n");
            }

            /**************************
            *
            *  Ispisivanje treceg dela brodica
            *
            **************************/
            m = n - m;

            for (i=1; i<=m; i++)
            {
                z = n + m - i;
                printf("\t");
                for (j=0; j<=z; j++)
                {
                    printf("*");
                }
                printf("\n");
            }

            /************************
            *
            *  Ispisivanje cetvrtog dela brodica
            *
            ************************/
            for (i=0; i<n; i++)
            {
                printf("\t");
                for (j=0; j<i; j++) printf(" ");
                for (j=0; j<(n-i); j++) printf("*");
                printf("\n");
            }

            /*********************************
            *
            *  Provera da li korinik zeli da ponovi program
            *
            *********************************/
            printf("\n\n Da li zelite da ponovite program? (y/n) ");
            scanf("%c", &again);
            scanf("%c", &again);
            while (again!='y' && again!='n')
            {
                printf("\n\tPOGRESAN UNOS! Da li zelite da ponovite program? (y/n) ");
                scanf("%c", &again);
                scanf("%c", &again);
            }
    }
    /********************
    *
    *  KRAJ PROGRAMA
    *
    ********************/
    printf("***KRAJ PROGRAMA***\n\n");
    return 0;
}
