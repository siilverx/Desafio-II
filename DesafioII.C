#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* unidades[] = {"zero", "um", "dois", "três", "quatro", "cinco", "seis", "sete", "oito", "nove"};
char* dezenas[] = {"dez", "onze", "doze", "treze", "quatorze", "quinze", "dezesseis", "dezessete", "dezoito", "dezenove"};
char* dezenas_multiplas[] = {"vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa"};
char* centenas[] = {"cento", "duzentos", "trezentos", "quatrocentos", "quinhentos", "seiscentos", "setecentos", "oitocentos", "novecentos"};

void escrever_extenso(int numero) {
    if (numero == 0) {
        printf("zero reais");
        return;
    }

    if (numero < 0 || numero > 999999) {
        printf("Número fora do intervalo permitido.");
        return;
    }

    if (numero >= 100000) {
        int centena_milhar = numero / 100000;
        escrever_extenso(centena_milhar);
        printf(" cem");
        numero %= 100000;
    }

    if (numero >= 1000) {
        int milhar = numero / 1000;
        if (milhar > 0) {
            escrever_extenso(milhar);
            printf(" mil");
        }
        numero %= 1000;
    }

    if (numero >= 100) {
        int centena = numero / 100;
        if (centena > 0) {
            printf(" %s", centenas[centena - 1]);
        }
        numero %= 100;
    }

    if (numero >= 20) {
        int dezena = numero / 10;
        if (dezena > 0) {
            printf(" e %s", dezenas_multiplas[dezena - 2]);
        }
        numero %= 10;
    } else if (numero >= 10) {
        printf(" e %s", dezenas[numero - 10]);
        return;
    }

    if (numero > 0) {
        printf(" %s", unidades[numero]);
    }

    if (numero == 1) {
        printf(" real");
    } else {
        printf(" reais");
    }
}

int main() {
    int numero;
    printf("Digite um número inteiro (até 6 dígitos): ");
    scanf("%d", &numero);

    escrever_extenso(numero);
    printf("\n");

    return 0;
}
