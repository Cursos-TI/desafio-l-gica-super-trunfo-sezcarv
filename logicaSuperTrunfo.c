#include <stdio.h>

/* Atividade */

int main() {
    int j; // A variável j foi inserida com a finalidade de possibilitar aos usuários a definição do número de cartas que deseja cadastrar.
   
    // Declaração das variáveis para "j" cartas:
    int pturisticos[j]; // Variável inteira declarada como Arrays para o armazenamento de dados das j cartas
    unsigned long int populacao[j]; // Variável inteira longa declarada como Arrays para o armazenamento de dados das j cartas
    float area[j], pib[j], densdemog[j], pibpercapita[j], supertrunfo[j]; // Variáveis de ponto flutuante declaradas como Arrays para o armazenamento de dados das j cartas
    char estado[j], codcarta[j][4], cidade[j][20]; // Variáveis char e strings declaradas como Arrays para o armazenamento de dados das j cartas

    printf("Desafio Super Trunfo! (Tecle Enter para continuar.)\n"); // Apresenta o nome do jogo e aguarda a tecla enter ser acionada para inicializar o jogo
    scanf("%*c"); // Lê a entrada anterior e descarta

    printf("Informe o número de cartas a ser cadastrado\n"); // Solicita ao usuário o número de cartas que será cadastrada (no caso do desafio, informar 32 cartas)
    scanf(" %d", &j); 

    // Loop for para a realização do cadastramento das j cartas
    for (int i = 0; i < j; i++) {
        printf("\n*** Cadastro da Carta %d ***\n", i + 1); // Informa que será realizado o cadastramento das cartas (carta 1, carta 2, ...)

        printf("Informe o Estado (de A a H): \n"); // Solicita ao usuário a letra correspondente ao Estado
        scanf(" %c", &estado[i]); // Lê a letra informada e armazena no array estado[i] 

        printf("Informe o código da carta: \n"); // Solicita ao usuário o código da carta
        scanf("%3s", codcarta[i]); // Lê o código informado e armazena no array codcarta[i]

        printf("Informe o nome da cidade: \n"); // Solicita ao usuário que informe a cidade
        scanf(" %[^\n]", cidade[i]); // Lê o nome da cidade e armazena na array cidade[i]

        printf("Informe a população da cidade: \n"); // Solicita ao usuário que informe a população da cidade
        scanf("%d", &populacao[i]); // Lê a população e armazena na array populacao[i]

        printf("Informe a área da cidade, em Km²: \n"); // Solicita ao usuário que informe a área da cidade
        scanf("%f", &area[i]); // Lê a área e armazena na array area[i]

        printf("Informe o PIB da cidade: \n"); // Solicita ao usuário que informe o PIB da cidade
        scanf("%f", &pib[i]); // Lê o PIB da cidade e armazena na array pib[i]

        printf("Informe o número de pontos turísticos da cidade: \n"); // Solicita ao usuário que informe o número de pontos turísticos
        scanf("%d", &pturisticos[i]); // Lê o número de pontos turísticos e armazena na array pturisticos[i]

        // Cálculo da densidade populacional e PIB per capita
        densdemog[i] = (float)populacao[i] / area[i];
        pibpercapita[i] = (float)pib[i] / populacao[i];
        
        // Cálculo do Super Trunfo
        supertrunfo[i] = (float)populacao[i] + area[i] + pib[i] + (float)pturisticos[i] + densdemog[i] + pibpercapita[i];
        
    }

    // Comparações para todos os critérios informados pelos usuários
    // Comparação dos valores das Populações informadas
    int vencedor_populacao = 0;
    for (int i = 1; i < j; i++) {
        if (populacao[i] > populacao[vencedor_populacao]) {
            vencedor_populacao = i;
        }
    }

    // Comparação dos valores das Áreas informadas
    int vencedor_area = 0;
    for (int i = 1; i < j; i++) {
        if (area[i] > area[vencedor_area]) {
            vencedor_area = i;
        }
    }

    // Comparação dos valores dos PIBs informados
    int vencedor_pib = 0;
    for (int i = 1; i < j; i++) {
        if (pib[i] > pib[vencedor_pib]) {
            vencedor_pib = i;
        }
    }

    // Comparação dos Números de Pontos Turísticos informados
    int vencedor_pontos = 0;
    for (int i = 1; i < j; i++) {
        if (pturisticos[i] > pturisticos[vencedor_pontos]) {
            vencedor_pontos = i;
        }
    }

    // Comparação das Densidades Populacionais calculadas
    int vencedor_densidade = 0;
    for (int i = 1; i < j; i++) {
        if (densdemog[i] < densdemog[vencedor_densidade]) {
            vencedor_densidade = i;
        }
    }
    
    // Comparação dos PIBs per Capita calculados
    int vencedor_pibpc = 0;
    for (int i = 1; i < j; i++) {
        if (pibpercapita[i] > pibpercapita[vencedor_pibpc]) {
            vencedor_pibpc = i;
        }
    }
    
     // Comparação dos Super Trunfos calculados
    int vencedor_strunfo = 0;
    for (int i = 1; i < j; i++) {
        if (supertrunfo[i] > supertrunfo[vencedor_strunfo]) {
            vencedor_strunfo = i;
        }
    }
    
    // Impressão dos resultados
    printf("\n*** Dados das Cartas Cadastrados ***\n"); // Imprime o cabeçalho "Dados das Cartas Cadastradas"
    // Loop para apresntar, de forma organizada, os dados das cidades cadastradas
    for (int i = 0; i < j; i++) { 
        printf("\n");
        printf("Estado: %c\nCódigo da carta: %.3s\nCidade: %s\nPopulação: %d habitantes\nÁrea: %.3f Km²\nPIB: R$ %.2f\nNúmero de pontos turísticos: %d\nDensidade populacional: %.3f hab./Km²\nPIB per capita: R$ %.2f\nSuper Trunfo: %.2f\n",
               estado[i], codcarta[i], cidade[i], populacao[i], area[i], pib[i], pturisticos[i], densdemog[i], pibpercapita[i], supertrunfo[i]);
        printf("\n");
    }
    // Impressão dos resultados das comparações
        printf("\n*** Comparações das Cartas ***\n");
        printf("\n");
        printf("População: Venceu a carta %s\nÁrea: Venceu a carta %s\nPIB: Venceu a carta %s\nNúmero de pontos turísticos: Venceu a carta %s\nDensidade populacional: Venceu a carta %s\nPIB per capita: Venceu a carta %s\nSuper Trunfo: Venceu a carta %s\n", codcarta[vencedor_populacao], codcarta[vencedor_area], codcarta[vencedor_pib], codcarta[vencedor_pontos], codcarta[vencedor_densidade], codcarta[vencedor_pibpc], codcarta[vencedor_strunfo]);

    return 0;
}