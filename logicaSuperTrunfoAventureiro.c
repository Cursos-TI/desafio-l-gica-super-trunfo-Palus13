#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Definição das variáveis para armazenar as propriedades das cidades - Serão utilizadas duas cidades
    // Copiarei o código utilizado na primeira parte do desafio para facilitar a implementação

    struct cidade {
        char pais[20];
        char codigo[4];
        char nome[20];
        float populacao;
        float area;
        float pib;
        int pontosturisticos;
        float densidadepopulacional;
        float pibpercapita;
    };

    struct cidade cidades[2]; // Array para armazenar duas cidades

    for (int i = 0; i < 2; i++) {
        printf("Cadastro da cidade %d:\n", i + 1);

        printf("Digite o nome da cidade: \n");
        scanf("%19s", cidades[i].nome);

        printf("Digite a população da cidade em milhões de habitantes: \n");
        scanf("%f", &cidades[i].populacao);

        printf("Digite a área da cidade em milhares de km²: \n");
        scanf("%f", &cidades[i].area);

        printf("Digite o PIB da cidade em bilhões de dólares: \n");
        scanf("%f", &cidades[i].pib);

        printf("Digite o número de pontos turísticos da cidade: \n");
        scanf("%d", &cidades[i].pontosturisticos);

        // Cálculo da densidade populacional
        cidades[i].densidadepopulacional = cidades[i].populacao / cidades[i].area / 1000;

        // Cálculo do PIB per capita
        cidades[i].pibpercapita = cidades[i].pib / cidades[i].populacao * 1000;

        printf("\n");
    }

    // Exibição dos dados cadastrados
    for (int i = 0; i < 2; i++) {
        printf("Dados da cidade %d:\n", i + 1);
        printf("Nome: %s\n", cidades[i].nome);
        printf("População: %.2f milhões\n", cidades[i].populacao);
        printf("Área: %.2f milhares de km²\n", cidades[i].area);
        printf("PIB: %.2f bilhões de dólares\n", cidades[i].pib);
        printf("Pontos turísticos: %d\n", cidades[i].pontosturisticos);
        printf("Densidade populacional: %.2f habitantes/km²\n", cidades[i].densidadepopulacional);
        printf("PIB per capita: %.2f dólares\n", cidades[i].pibpercapita);
        printf("\n");
    }

    // Comparação de Cartas utilizando a 'switch':
    // Desenvolva a lógica de comparação entre duas cartas.
    // Utilize estruturas de decisão como if, if-else para comparar atributos como população, área, PIB, etc.

      int opcao;
      printf("Escolha qual o atributo que deseja comparar:\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Pontos Turísticos\n");
        printf("5 - Densidade Populacional\n");
        printf("6 - PIB per Capita\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Comparando pela População:\n");
                if (cidades[0].populacao > cidades[1].populacao) {
                    printf("População: %s vence\n", cidades[0].nome);
            
                } else if (cidades[0].populacao < cidades[1].populacao) {
                    printf("População: %s vence\n", cidades[1].nome);
            
                } else {
                    printf("População: Empate\n");
                break;
            case 2:
                printf("Comparando pela Área:\n");
                if (cidades[0].area > cidades[1].area) {
                    printf("Área: %s vence\n", cidades[0].nome);
            
                } else if (cidades[0].area < cidades[1].area) {
                    printf("Área: %s vence\n", cidades[1].nome);
            
                } else {
                    printf("Área: Empate\n");
                }
                break;
            case 3:
                printf("Comparando pelo PIB:\n");
                if (cidades[0].pib > cidades[1].pib) {
                    printf("PIB: %s vence\n", cidades[0].nome);
            
                } else if (cidades[0].pib < cidades[1].pib) {
                    printf("PIB: %s vence\n", cidades[1].nome);
            
                } else {
                    printf("PIB: Empate\n");
                }
                break;
            case 4:
                printf("Comparando pelos Pontos Turísticos:\n");
                if (cidades[0].pontosturisticos > cidades[1].pontosturisticos) {
                    printf("Pontos Turísticos: %s vence\n", cidades[0].nome);
            
                } else if (cidades[0].pontosturisticos < cidades[1].pontosturisticos) {
                    printf("Pontos Turísticos: %s vence\n", cidades[1].nome);
            
                } else {
                    printf("Pontos Turísticos: Empate\n");
                }
                break;
            case 5:
                printf("Comparando pela Densidade Populacional:\n");
                if (cidades[0].densidadepopulacional > cidades[1].densidadepopulacional) {
                    printf("Densidade Populacional: %s vence\n", cidades[0].nome);
            
                } else if (cidades[0].densidadepopulacional < cidades[1].densidadepopulacional) {
                    printf("Densidade Populacional: %s vence\n", cidades[1].nome);
            
                } else {
                    printf("Densidade Populacional: Empate\n");
                }
                break;
            case 6:
                printf("Comparando pelo PIB per Capita:\n");
                if (cidades[0].pibpercapita > cidades[1].pibpercapita) {
                    printf("PIB per Capita: %s vence\n", cidades[0].nome);
            
                } else if (cidades[0].pibpercapita < cidades[1].pibpercapita) {
                    printf("PIB per Capita: %s vence\n", cidades[1].nome);
            
                } else {
                    printf("PIB per Capita: Empate\n");
                }
                break;
            default:
                printf("Opção inválida!\n");
        }

  
    }

    return 0;
}
