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
        float superpoder;
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

    // Comparação de Cartas:
    // Desenvolva a lógica de comparação entre duas cartas.
    // Utilize estruturas de decisão como if, if-else para comparar atributos como população, área, PIB, etc.

      // Comparar população - não vou me alongar, pois já fiz isso na parte anterior
      if (cidades[0].populacao > cidades[1].populacao) {
        printf("População: %s vence\n", cidades[0].nome);

    } else if (cidades[0].populacao < cidades[1].populacao) {
        printf("População: %s vence\n", cidades[1].nome);

    } else {
        printf("População: Empate\n");
    }


    // Exibição dos Resultados:
    // Após realizar as comparações, exiba os resultados para o usuário.
    // Certifique-se de que o sistema mostre claramente qual carta venceu e com base em qual atributo.
    // Exemplo:
    // printf("A cidade vencedora é: %s\n", cidadeVencedora);

    return 0;
}
