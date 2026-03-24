#include <stdio.h>
void valoralt (int saldo) {
// A variavel serve apenas como uma copia, nao muda o original
    saldo = 5000; 
}

// Usando o asterisco pra obter o endereco real da memoria
void ponteiroalt(int *saldo) {
    // Aqui o asterisco é usado para alterar o valor na origem
    *saldo = 5000; 
}
int main() {
    int saldobanc = 1000;
    printf("Saldo inicial: %d\n", saldobanc);
    // Copia do valor original
    valoralt(saldobanc);
    printf("Depois do valor (nao muda): %d\n", saldobanc);

    // O endereco é mandado usando o &
    ponteiroalt(&saldobanc);
    printf("Depois do ponteiro (muda): %d\n", saldobanc);

    return 0;
}