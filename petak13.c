/**
 *  Autor: Bojan Delic
 *  Datum: 13. 11.2007.
 *  Program: Racunanje datuma sledeceg petka 13.
 */


#include <stdio.h>

#define DAN_START 13
#define MESEC_START FEB
#define GODINA_START 2004

#define STEP 7

int main() {
    enum meseci { JAN, FEB, MAR, APR, MAJ, JUN, JUL, AVG, SEP, OKT, NOV, DEC };
    int brojDana[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    enum { FALSE, TRUE };

    int i;

    int dan = DAN_START;
    int mesec = MESEC_START;
    int godina = GODINA_START;

    int pronadjen_petak = FALSE;
    while (pronadjen_petak == FALSE) {
        switch (mesec) {
            case JAN:
                dan += STEP;
                if (dan > brojDana[JAN]) {
                    dan -= brojDana[JAN];
                    mesec = FEB;
                }
                break;
            case FEB:
                dan += STEP;
                if (dan > brojDana[FEB]) {
                    dan -= brojDana[FEB];
                    // provera da li je godina prestupa
                    if ((godina % 4 == 0) && (godina % 100 != 0)) dan--;
                    mesec = MAR;
                }
                break;
            case MAR:
                dan += STEP;
                if (dan > brojDana[MAR]) {
                    dan -= brojDana[MAR];
                    mesec = APR;
                }
                break;
            case APR:
                dan += STEP;
                if (dan > brojDana[APR]) {
                    dan -= brojDana[APR];
                    mesec = MAJ;
                }
                break;
            case MAJ:
                dan += STEP;
                if (dan > brojDana[MAJ]) {
                    dan -= brojDana[MAJ];
                    mesec = JUN;
                }
                break;
            case JUN:
                dan += STEP;
                if (dan > brojDana[JUN]) {
                    dan -= brojDana[JUN];
                    mesec = JUL;
                }
                break;
            case JUL:
                dan += STEP;
                if (dan > brojDana[JUL]) {
                    dan -= brojDana[JUL];
                    mesec = AVG;
                }
                break;
            case AVG:
                dan += STEP;
                if (dan > brojDana[AVG]) {
                    dan -= brojDana[AVG];
                    mesec = SEP;
                }
                break;
            case SEP:
                dan += STEP;
                if (dan > brojDana[SEP]) {
                    dan -= brojDana[SEP];
                    mesec = OKT;
                }
                break;
            case OKT:
                dan += STEP;
                if (dan > brojDana[OKT]) {
                    dan -= brojDana[OKT];
                    mesec = NOV;
                }
                break;
            case NOV:
                dan +=STEP;
                if (dan > brojDana[NOV]) {
                    dan -= brojDana[NOV];
                    mesec = DEC;
                }
                break;
            case DEC:
                dan += STEP;
                if (dan > brojDana[DEC]) {
                    dan -= brojDana[DEC];
                    mesec = JAN;
                    godina++;
                }
                break;
        }

        //printf("\t Datum do koga smo dosli je: %d.%d.%d\n", dan, mesec+1, godina);

        if ( dan == 13) {
            printf("Petak trinaesti je na datum: %d.%d.%d\n\n", dan, mesec+1, godina);
            pronadjen_petak = TRUE;
        }
    }


    return 0;
}
