#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Definição da estrutura cidade
struct cidade {
    char pais[50];
    char codigo[10];
    char nome[50];
    float populacao;
    float area;
    float pib;
    int pontosturisticos;
    float densidadepopulacional;
    float pibpercapita;
    float superpoder;
};

// Definição da estrutura Pais
struct pais {
    char nome[50];
    struct cidade cidades[4];
};

// Declaração de um array de 8 estruturas pais
struct pais paises[8];

// Função para limpar o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para ler uma string com espaços
void lerString(char *destino, int tamanho, const char *mensagem) {
    printf("%s", mensagem);
    fgets(destino, tamanho, stdin);
    
    // Remover o caractere de nova linha, se presente
    size_t len = strlen(destino);
    if (len > 0 && destino[len - 1] == '\n') {
        destino[len - 1] = '\0';
    }
}

// Função para ler um número inteiro com validação
int lerInteiro(const char *mensagem, int min, int max) {
    int valor;
    char buffer[100];
    
    while (1) {
        printf("%s", mensagem);
        fgets(buffer, sizeof(buffer), stdin);
        
        // Verificar se a entrada é um número
        if (sscanf(buffer, "%d", &valor) != 1) {
            printf("Erro: Por favor, digite um número válido.\n");
            continue;
        }
        
        // Verificar se o número está dentro do intervalo
        if (valor < min || valor > max) {
            printf("Erro: O valor deve estar entre %d e %d.\n", min, max);
            continue;
        }
        
        return valor;
    }
}

// Função para ler um número float com validação
float lerFloat(const char *mensagem, float min) {
    float valor;
    char buffer[100];
    
    while (1) {
        printf("%s", mensagem);
        fgets(buffer, sizeof(buffer), stdin);
        
        // Verificar se a entrada é um número
        if (sscanf(buffer, "%f", &valor) != 1) {
            printf("Erro: Por favor, digite um número válido.\n");
            continue;
        }
        
        // Verificar se o número é positivo
        if (valor < min) {
            printf("Erro: O valor deve ser maior ou igual a %.2f.\n", min);
            continue;
        }
        
        return valor;
    }
}

// Função para comparar dois atributos
void compararAtributos(const char *atributo, float valor1, float valor2, const char *nome1, const char *nome2) {
    printf("\n----- Comparando %s -----\n", atributo);
    printf("%s: %.2f\n", nome1, valor1);
    printf("%s: %.2f\n", nome2, valor2);

    // Verifica se o atributo é "Densidade Populacional"
    if (strcmp(atributo, "Densidade Populacional") == 0) {
        // Para densidade populacional, o menor valor vence
        if (valor1 < valor2) {
            printf("Resultado: %s vence (menor densidade é melhor)\n", nome1);
        } else if (valor1 > valor2) {
            printf("Resultado: %s vence (menor densidade é melhor)\n", nome2);
        } else {
            printf("Resultado: Empate\n");
        }
    } else {
        // Para outros atributos, o maior valor vence
        if (valor1 > valor2) {
            printf("Resultado: %s vence (maior valor é melhor)\n", nome1);
        } else if (valor1 < valor2) {
            printf("Resultado: %s vence (maior valor é melhor)\n", nome2);
        } else {
            printf("Resultado: Empate\n");
        }
    }
}

// Função para comparar pontos turísticos (valor inteiro)
void compararPontosTuristicos(int valor1, int valor2, const char *nome1, const char *nome2) {
    printf("\n----- Comparando Pontos Turísticos -----\n");
    printf("%s: %d\n", nome1, valor1);
    printf("%s: %d\n", nome2, valor2);

    if (valor1 > valor2) {
        printf("Resultado: %s vence (maior número é melhor)\n", nome1);
    } else if (valor1 < valor2) {
        printf("Resultado: %s vence (maior número é melhor)\n", nome2);
    } else {
        printf("Resultado: Empate\n");
    }
}

// Função para exibir os detalhes de uma cidade
void exibirDetalhes(struct cidade cidade) {
    printf("\n===== Detalhes da Cidade =====\n");
    printf("Código: %s\n", cidade.codigo);
    printf("Nome: %s\n", cidade.nome);
    printf("País: %s\n", cidade.pais);
    printf("População: %.2f milhões\n", cidade.populacao);
    printf("Área: %.2f mil km²\n", cidade.area);
    printf("PIB: %.2f bilhões de dólares\n", cidade.pib);
    printf("Pontos Turísticos: %d\n", cidade.pontosturisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", cidade.densidadepopulacional);
    printf("PIB per Capita: %.2f mil dólares\n", cidade.pibpercapita);
    printf("Super Poder: %.2f\n", cidade.superpoder);
    printf("==============================\n");
}

// Função para comparar cartas
void compararCartas(struct cidade cidade1, struct cidade cidade2) {
    printf("\n********** COMPARAÇÃO DE CARTAS **********\n");
    printf("Carta 1: %s (%s)\n", cidade1.nome, cidade1.pais);
    printf("Carta 2: %s (%s)\n", cidade2.nome, cidade2.pais);
    
    int opcao1, opcao2;
    
    printf("\nEscolha o primeiro atributo que deseja comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");
    printf("6 - PIB per Capita\n");
    
    opcao1 = lerInteiro("Digite a opção desejada (1-6): ", 1, 6);

    printf("\nEscolha o segundo atributo que deseja comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");
    printf("6 - PIB per Capita\n");
    
    opcao2 = lerInteiro("Digite a opção desejada (1-6): ", 1, 6);

    // Comparar o primeiro atributo
    switch (opcao1) {
        case 1:
            compararAtributos("População", cidade1.populacao, cidade2.populacao, cidade1.nome, cidade2.nome);
            break;
        case 2:
            compararAtributos("Área", cidade1.area, cidade2.area, cidade1.nome, cidade2.nome);
            break;
        case 3:
            compararAtributos("PIB", cidade1.pib, cidade2.pib, cidade1.nome, cidade2.nome);
            break;
        case 4:
            compararPontosTuristicos(cidade1.pontosturisticos, cidade2.pontosturisticos, cidade1.nome, cidade2.nome);
            break;
        case 5:
            compararAtributos("Densidade Populacional", cidade1.densidadepopulacional, cidade2.densidadepopulacional, cidade1.nome, cidade2.nome);
            break;
        case 6:
            compararAtributos("PIB per Capita", cidade1.pibpercapita, cidade2.pibpercapita, cidade1.nome, cidade2.nome);
            break;
    }

    // Comparar o segundo atributo
    switch (opcao2) {
        case 1:
            compararAtributos("População", cidade1.populacao, cidade2.populacao, cidade1.nome, cidade2.nome);
            break;
        case 2:
            compararAtributos("Área", cidade1.area, cidade2.area, cidade1.nome, cidade2.nome);
            break;
        case 3:
            compararAtributos("PIB", cidade1.pib, cidade2.pib, cidade1.nome, cidade2.nome);
            break;
        case 4:
            compararPontosTuristicos(cidade1.pontosturisticos, cidade2.pontosturisticos, cidade1.nome, cidade2.nome);
            break;
        case 5:
            compararAtributos("Densidade Populacional", cidade1.densidadepopulacional, cidade2.densidadepopulacional, cidade1.nome, cidade2.nome);
            break;
        case 6:
            compararAtributos("PIB per Capita", cidade1.pibpercapita, cidade2.pibpercapita, cidade1.nome, cidade2.nome);
            break;
    }
}

// Função para listar todas as cidades cadastradas
void listarCidades() {
    printf("\n===== LISTA DE TODAS AS CIDADES CADASTRADAS =====\n");
    
    for (int i = 0; i < 8; i++) {
        printf("\nPaís: %s\n", paises[i].nome);
        printf("---------------------------\n");
        
        for (int j = 0; j < 4; j++) {
            printf("%d. %s (Código: %s)\n", j + 1, paises[i].cidades[j].nome, paises[i].cidades[j].codigo);
        }
    }
    printf("\n=================================================\n");
}

int main() {
    printf("\n********** SUPER TRUNFO - PAÍSES **********\n\n");

    // Cadastro de países e cidades
    for (int i = 0; i < 8; i++) {
        printf("\n===== Cadastro do país %d =====\n", i + 1);
        
        // Limpar o buffer antes de ler o nome do país (apenas na primeira iteração)
        if (i == 0) {
            limparBuffer();
        }
        
        lerString(paises[i].nome, sizeof(paises[i].nome), "Digite o nome do país: ");

        for (int j = 0; j < 4; j++) {
            printf("\n----- Cadastro da cidade %d do país %s -----\n", j + 1, paises[i].nome);
            
            // Gerar código automaticamente (ex: BRA01, USA02)
            char prefixo[4] = {0};
            strncpy(prefixo, paises[i].nome, 3);
            for (int k = 0; k < 3; k++) {
                prefixo[k] = toupper(prefixo[k]);
            }
            snprintf(paises[i].cidades[j].codigo, sizeof(paises[i].cidades[j].codigo), "%s%02d", prefixo, j + 1);
            
            // Copiar o nome do país para a cidade
            strncpy(paises[i].cidades[j].pais, paises[i].nome, sizeof(paises[i].cidades[j].pais) - 1);
            paises[i].cidades[j].pais[sizeof(paises[i].cidades[j].pais) - 1] = '\0';  // Garantir terminação nula
            
            lerString(paises[i].cidades[j].nome, sizeof(paises[i].cidades[j].nome), "Digite o nome da cidade: ");
            
            paises[i].cidades[j].populacao = lerFloat("Digite a população da cidade em milhões de habitantes: ", 0.0);
            paises[i].cidades[j].area = lerFloat("Digite a área da cidade em milhares de km²: ", 0.0);
            paises[i].cidades[j].pib = lerFloat("Digite o PIB da cidade em bilhões de dólares: ", 0.0);
            paises[i].cidades[j].pontosturisticos = lerInteiro("Digite o número de pontos turísticos da cidade: ", 0, 1000);

            // Calcular valores derivados
            if (paises[i].cidades[j].area > 0) {
                paises[i].cidades[j].densidadepopulacional = paises[i].cidades[j].populacao * 1000 / paises[i].cidades[j].area;
            } else {
                paises[i].cidades[j].densidadepopulacional = 0;
            }
            
            if (paises[i].cidades[j].populacao > 0) {
                paises[i].cidades[j].pibpercapita = paises[i].cidades[j].pib * 1000 / paises[i].cidades[j].populacao;
            } else {
                paises[i].cidades[j].pibpercapita = 0;
            }
            
            paises[i].cidades[j].superpoder = paises[i].cidades[j].populacao + 
                                             paises[i].cidades[j].area + 
                                             paises[i].cidades[j].pib + 
                                             paises[i].cidades[j].pontosturisticos - 
                                             paises[i].cidades[j].densidadepopulacional;
            
            printf("Cidade cadastrada com sucesso!\n");
        }
        
        printf("\nPaís %s cadastrado com sucesso!\n", paises[i].nome);
    }

    // Menu principal
    int opcao;
    do {
        printf("\n===== MENU PRINCIPAL =====\n");
        printf("1 - Listar todas as cidades\n");
        printf("2 - Ver detalhes de uma cidade\n");
        printf("3 - Comparar cartas\n");
        printf("0 - Sair do jogo\n");
        
        opcao = lerInteiro("Digite a opção desejada: ", 0, 3);
        
        switch (opcao) {
            case 1:
                listarCidades();
                break;
                
            case 2: {
                listarCidades();
                int paisIndex = lerInteiro("Digite o número do país (1-8): ", 1, 8) - 1;
                int cidadeIndex = lerInteiro("Digite o número da cidade (1-4): ", 1, 4) - 1;
                exibirDetalhes(paises[paisIndex].cidades[cidadeIndex]);
                break;
            }
                
            case 3: {
                listarCidades();
                printf("\n----- Seleção da primeira carta -----\n");
                int paisIndex1 = lerInteiro("Digite o número do primeiro país (1-8): ", 1, 8) - 1;
                int cidadeIndex1 = lerInteiro("Digite o número da primeira cidade (1-4): ", 1, 4) - 1;
                
                printf("\n----- Seleção da segunda carta -----\n");
                int paisIndex2 = lerInteiro("Digite o número do segundo país (1-8): ", 1, 8) - 1;
                int cidadeIndex2 = lerInteiro("Digite o número da segunda cidade (1-4): ", 1, 4) - 1;
                
                compararCartas(paises[paisIndex1].cidades[cidadeIndex1], paises[paisIndex2].cidades[cidadeIndex2]);
                break;
            }
                
            case 0:
                printf("\nObrigado por jogar o Super Trunfo de Países!\n");
                break;
                
            default:
                printf("Opção inválida. Por favor, tente novamente.\n");
        }
        
    } while (opcao != 0);

    return 0;
}