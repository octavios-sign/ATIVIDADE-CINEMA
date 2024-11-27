#include <stdio.h>
#include <stdlib.h> //PESQUISAR
#include <string.h> 
#include <time.h> //PESQUISAR

// Definições de constantes
#define LINHAS 5
#define COLUNAS 5
#define MAX_BILHETES 100

// Estrutura de Lugar
typedef struct {
    int linha;
    int coluna;
    int ocupado;       // 0 = Disponível, 1 = Ocupado
    int tipoIngresso;  // 0 = Inteiro, 1 = Meia-entrada
    int comCombo;      // 0 = Não, 1 = Sim
} Lugar;

// Estrutura de Bilhete
typedef struct {
    int numeroBilhete;
    Lugar lugar;
    char nomeCliente[100];
} Bilhete;

// Declaração de variáveis globais
Lugar sala[LINHAS][COLUNAS];
Bilhete bilhetes[MAX_BILHETES];
int bilheteCount = 0;

// Funções do sistema
void inicializarSala() {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            sala[i][j].linha = i;
            sala[i][j].coluna = j;
            sala[i][j].ocupado = 0;
            sala[i][j].tipoIngresso = -1;
            sala[i][j].comCombo = 0;
        }
    }
}

void exibirFilmes() {
    printf("\nFilmes disponíveis:\n");
    printf("1. Vingadores: Ultimato\n");
    printf("2. O Rei Leão\n");
    printf("3. Avatar 2\n");
    printf("4. Interestelar\n");
}

void exibirSala() {
    printf("\nMapa da Sala (D = Disponível, X = Ocupado):\n");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%c ", sala[i][j].ocupado ? 'X' : 'D');
        }
        printf("\n");
    }
}

int gerarNumeroBilheteUnico() {
    int numero;
    int unico;
    do {
        unico = 1;
        numero = rand() % 100000 + 1;
        for (int i = 0; i < bilheteCount; i++) {
            if (bilhetes[i].numeroBilhete == numero) {
                unico = 0;
                break;
            }
        }
    } while (!unico);
    return numero;
}

void reservarLugar() {
    int linha, coluna, tipoIngresso, comCombo, escolhaFilme;
    char nomeCliente[100];

    exibirFilmes();
    printf("Escolha o filme pelo número: ");
    scanf("%d", &escolhaFilme);
    getchar();

    if (escolhaFilme < 1 || escolhaFilme > 4) {
        printf("Filme inválido.\n");
        return;
    }

    printf("\nVocê escolheu o filme %d.\n", escolhaFilme);
    exibirSala();

    printf("Digite seu nome: ");
    fgets(nomeCliente, 100, stdin);
    nomeCliente[strcspn(nomeCliente, "\n")] = 0;

    printf("Escolha um lugar (linha [0-%d], coluna [0-%d]): ", LINHAS - 1, COLUNAS - 1);
    scanf("%d %d", &linha, &coluna);
    getchar();

    if (linha < 0 || linha >= LINHAS || coluna < 0 || coluna >= COLUNAS || sala[linha][coluna].ocupado) {
        printf("Lugar inválido ou já ocupado.\n");
        return;
    }

    do {
        printf("Digite o tipo de ingresso (0 para Inteiro, 1 para Meia-entrada): ");
        scanf("%d", &tipoIngresso);
    } while (tipoIngresso != 0 && tipoIngresso != 1);

    do {
        printf("Deseja adicionar combo (0 para Não, 1 para Sim): ");
        scanf("%d", &comCombo);
    } while (comCombo != 0 && comCombo != 1);

    sala[linha][coluna].ocupado = 1;
    sala[linha][coluna].tipoIngresso = tipoIngresso;
    sala[linha][coluna].comCombo = comCombo;

    Bilhete bilhete;
    bilhete.numeroBilhete = gerarNumeroBilheteUnico();
    bilhete.lugar = sala[linha][coluna];
    strcpy(bilhete.nomeCliente, nomeCliente);

    bilhetes[bilheteCount++] = bilhete;

    printf("\nReserva confirmada!\n");
    printf("Bilhete Número: %d\n", bilhete.numeroBilhete);
}

void imprimirBilhete() {
    int numeroBilhete;
    printf("Digite o número do bilhete: ");
    scanf("%d", &numeroBilhete);
    getchar();

    for (int i = 0; i < bilheteCount; i++) {
        if (bilhetes[i].numeroBilhete == numeroBilhete) {
            printf("\nBilhete Número: %d\n", bilhetes[i].numeroBilhete);
            printf("Cliente: %s\n", bilhetes[i].nomeCliente);
            printf("Lugar: Linha %d, Coluna %d\n", bilhetes[i].lugar.linha, bilhetes[i].lugar.coluna);
            printf("Tipo de Ingresso: %s\n", bilhetes[i].lugar.tipoIngresso == 0 ? "Inteiro" : "Meia-entrada");
            printf("Combo: %s\n", bilhetes[i].lugar.comCombo == 1 ? "Sim" : "Não");
            return;
        }
    }
    printf("Bilhete não encontrado.\n");
}

void cancelarCompra() {
    int numeroBilhete;
    printf("Digite o número do bilhete a ser cancelado: ");
    scanf("%d", &numeroBilhete);
    getchar();

    for (int i = 0; i < bilheteCount; i++) {
        if (bilhetes[i].numeroBilhete == numeroBilhete) {
            sala[bilhetes[i].lugar.linha][bilhetes[i].lugar.coluna].ocupado = 0;

            for (int j = i; j < bilheteCount - 1; j++) {
                bilhetes[j] = bilhetes[j + 1];
            }
            bilheteCount--;

            printf("Compra cancelada e lugar liberado.\n");
            return;
        }
    }
    printf("Bilhete não encontrado.\n");
}

void exibirRelatorio() {
    int totalIngressos = 0, totalCombos = 0, totalArrecadado = 0;

    for (int i = 0; i < bilheteCount; i++) {
        totalIngressos++;
        totalArrecadado += bilhetes[i].lugar.tipoIngresso == 0 ? 20 : 10;
        if (bilhetes[i].lugar.comCombo) {
            totalCombos++;
            totalArrecadado += 10;
        }
    }

    printf("\nRelatório Final:\n");
    printf("Ingressos vendidos: %d\n", totalIngressos);
    printf("Combos vendidos: %d\n", totalCombos);
    printf("Total arrecadado: R$ %d\n", totalArrecadado);
}

int main() {
    srand(time(NULL)); //PESQUISAR
    int opcao;

    inicializarSala();

    do {
        printf("\nMenu Principal:\n");
        printf("1. Reservar Lugar\n");
        printf("2. Imprimir Bilhete\n");
        printf("3. Cancelar Compra\n");
        printf("4. Exibir Sala\n");
        printf("5. Exibir Relatório\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1: reservarLugar(); break;
            case 2: imprimirBilhete(); break;
            case 3: cancelarCompra(); break;
            case 4: exibirSala(); break;
            case 5: exibirRelatorio(); break;
            case 6: printf("Encerrando o sistema.\n"); break;
            default: printf("Opção inválida.\n");
        }
    } while (opcao != 6);

    return 0;
}
