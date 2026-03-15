#include <stdio.h>

/*
FUNÇÃO (SEM EFEITO COLATERAL)

Recebe a altitude atual por VALOR.
Então a função trabalha com uma CÓPIA do valor.

Ela calcula uma nova altitude desejada e retorna esse valor,
mas não altera a variável original do main.
*/
int calcularNovaAltitude(int altitudeAtual) {

    int novaAltitude = altitudeAtual + 500; // avião sobe 500 metros

    printf("\n[Funcao segura]\n");
    printf("Altitude recebida: %d\n", altitudeAtual);
    printf("Nova altitude calculada: %d\n", novaAltitude);

    return novaAltitude;
}


/*
PROCEDIMENTO (COM EFEITO COLATERAL)

Recebe um ponteiro para altitude.
Então ela recebe o ENDEREÇO da variável que está no main.

Ao usar *altitude da para acessar diretamente o valor
naquele endereço de memória, alterando a variável original.
*/
void forcarMudancaAltitude(int *altitude) {

    printf("\n[Procedimento com efeito colateral]\n");
    printf("Altitude original: %d\n", *altitude);

    *altitude = *altitude + 1000; // altera diretamente a variável do main

    printf("Altitude apos alteracao forcada: %d\n", *altitude);
}


int main() {

    // variável de estado local
    int altitude = 10000; // metros

    printf("Altitude inicial do aviao: %d\n", altitude);

    // chamada da função segura
    int altitudeDesejada = calcularNovaAltitude(altitude);

    printf("\nAltitude no main apos funcao: %d\n", altitude);
    printf("Altitude desejada retornada pela funcao: %d\n", altitudeDesejada);

    /*
    A altitude original NÃO mudou,
    porque a função trabalhou com uma cópia.
    */


    // chamada do procedimento que altera o estado
    forcarMudancaAltitude(&altitude);

    printf("\nAltitude no main apos procedimento: %d\n", altitude);

    /*
    Agora a variável mudou, porque enviei
    o ENDEREÇO dela usando &altitude.
    O procedimento alterou diretamente o valor
    armazenado na memória do main.
    */

    return 0;
}
