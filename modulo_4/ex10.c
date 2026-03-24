#include <stdio.h>
#include <string.h>

#define MAX_PACIENTES 50
#define MAX_MEDICOS 20

// Estrutura que representa um paciente
typedef struct {
    int id;
    char nome[50];
    int idade;
    int internado; // 0 = não, 1 = sim
} Paciente;

// Estrutura que representa um médico
typedef struct {
    int id;
    char nome[50];
} Medico;

// Estrutura principal (grande) do sistema hospitalar
typedef struct {
    Paciente pacientes[MAX_PACIENTES]; // lista de pacientes
    Medico medicos[MAX_MEDICOS];       // lista de médicos
    int leitos[30];                    // controle de leitos (0 = livre, 1 = ocupado)
    float caixa;                       // dinheiro do hospital
    int totalPacientes;                // quantidade atual de pacientes
} SistemaHospitalar;

// Função para encontrar um leito livre
int encontrarLeitoLivre(int leitos[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (leitos[i] == 0) { // verifica se o leito está livre
            return i;         // retorna o índice do leito disponível
        }
    }
    return -1; // retorna -1 se não houver leitos disponíveis
}

// Procedimento para realizar a internação de um paciente
void realizar_internacao(SistemaHospitalar *s, int id, const char *nome, int idade) {
    
    // Procura um leito livre
    int leito = encontrarLeitoLivre(s->leitos, 30);

    // Verifica se há leitos disponíveis
    if (leito == -1) {
        printf("Nao ha leitos disponiveis.\n");
        return;
    }

    // Cria um novo paciente temporário
    Paciente novo;
    novo.id = id;
    strcpy(novo.nome, nome); // copia o nome recebido
    novo.idade = idade;
    novo.internado = 1; // marca como internado

    // Adiciona o paciente no sistema
    s->pacientes[s->totalPacientes] = novo;
    s->totalPacientes++;

    // Marca o leito como ocupado
    s->leitos[leito] = 1;

    // Atualiza o caixa do hospital (exemplo de cobrança)
    s->caixa += 750.0;

    // Exibe mensagem de sucesso
    printf("Paciente %s internado no leito %d.\n", nome, leito);
}

int main() {
    SistemaHospitalar sistema;

    // Inicializa valores do sistema
    sistema.totalPacientes = 0;
    sistema.caixa = 2000.0;

    // Inicializa todos os leitos como livres
    for (int i = 0; i < 30; i++) {
        sistema.leitos[i] = 0;
    }

    // Testando internações
    realizar_internacao(&sistema, 1, "Carlos", 45);
    realizar_internacao(&sistema, 2, "Maria", 32);

    return 0;
}