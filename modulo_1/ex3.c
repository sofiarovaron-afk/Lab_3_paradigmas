#include <stdio.h>

// Funcao para o calculo do salario liquido
float calcliq(float bruto) {
    return bruto * 0.90;
}

// Funcao para exibicao formatada dos valores
void imprimirlin(int id, float liq) {
    printf("Funcionario %d | Salario Liquido: R$ %.2f\n", id, liq);
}

int main() {
    // Uso de array para evitar repeticao de variaveis (sal1, sal2...)
    float salarios[] = {3000.0, 4500.0, 2000.0};
    float totalfolha = 0;

    printf("--- Relatorio Organizado ---\n");

    // O loop 'for' percorre os dados sem precisar repetir o codigo manualmente
    for (int i = 0; i < 3; i++) {
        float liq = calcliq(salarios[i]);
        imprimirlin(i + 1, liq);
        totalfolha += liq;
    }

    printf("Total Final: R$ %.2f\n", totalfolha);

    return 0;
}