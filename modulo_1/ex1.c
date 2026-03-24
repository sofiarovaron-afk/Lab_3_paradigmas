#include <stdio.h>

// Função Iterativa (Rápida - Complexidade O(n))
long long fibo(int n) {
    if (n <= 1) return n;
    long long a = 0, b = 1, prox;
    
    // O for faz o calculo linear, o que torna mais rapido
    for (int i = 2; i <= n; i++) {
        prox = a + b;
        a = b;
        b = prox;
    }
    return b;
}

// Função Recursiva (Lenta - Complexidade O(2^n))
long long fiborec(int n) {
    // Caso base para a funcao nao se tornar infinita
    if (n <= 1) return n;
    
    // Aqui a recursao acaba recalculando os mesmos numeros, 
    // gerando um peso grande na pilha de execução (Stack)
    return fiborec(n - 1) + fiborec(n - 2);
}

int main() {
    int n = 40;
    
    printf("Calculando Fibonacci de %d...\n", n);
    
    // Resultado instantâneo
    printf("Fibonacci Iterativo: %lld\n", fibo(n));
    
    // Isso vai demorar alguns segundos (ou minutos) dependendo do PC
    // É o comportamento esperado para o Exercício 1!
    printf("Fibonacci Recursivo: %lld\n", fiborec(n)); 
    
    return 0;
}