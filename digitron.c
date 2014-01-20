/*
 * Autor: Bojan Delic
 * Datum: 6.10.2007.
 * Verzija: 0.01
 * Prigram: Jednostavan oblik digitrona sa samo 4 operacije
 */


#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 128

enum state { OPERAND, OPERACIJA };
enum operacija { PLUS, MINUS, PUTA, PODELJENO };

int proveri_broj(char *);
int proveri_operand(char);


int main() {
    double rez = 0;
    char c;
    char buffer[BUFF_SIZE];
    enum operacija o;
    enum state s = OPERAND;

    char cont = 1;

    double tmp;

    while (cont) {
        if ( s == OPERAND) {
            printf("Unesite sledeci operand: ");
            scanf("%s", buffer);
            // f-ja koja prazni ulazni buffer
            // ako se ovo ne uradi sledeci scanf ce samo preskociti
            __fpurge(stdin);

            if (proveri_broj(buffer) != 0) {
                fprintf(stderr, "Neispravno unesen broj\n");
                return 1;
            }

            switch (o) {
                case PLUS:
                    rez += atof(buffer);
                    break;
                case MINUS:
                    rez -= atof(buffer);
                    break;
                case PUTA:
                    rez *= atof(buffer);
                    break;
                case PODELJENO:
                    if (tmp == 0) {
                        fprintf(stderr, "Deljenje nulom nije dozvoljeno\n");
                        return 3;
                    }
                    rez /= tmp;
                    break;
                default:
                    rez = atof(buffer);
            }
            s = OPERACIJA;
        }
        else {
            printf("Unesite operator: ");
            scanf("%c", &c);
            if (proveri_operand(c) != 0) {
                fprintf(stderr, "Neispravan operand na ulazu\n");
                return 2;
            }
            if (c == '=') {
                printf("Rezultat je %lf\n\n", rez);
                cont = 0;
            }
            switch (c) {
                case '+':
                    o = PLUS;
                    break;
                case '-':
                    o = MINUS;
                    break;
                case '*':
                    o = PUTA;
                    break;
                case '/':
                    o = PODELJENO;
                    break;

            }
            s = OPERAND;
        }

    }

    return 0;
}


int proveri_broj(char *s) {
    int i;
    for (i = 0; i < strlen(s); i++) {
        if (isdigit(s[i]) || s[i] == '.')
            continue;
        else
            return 1;

    }
    return 0;
}


int proveri_operand(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '=')
        return 0;
    else
        return 1;
}
