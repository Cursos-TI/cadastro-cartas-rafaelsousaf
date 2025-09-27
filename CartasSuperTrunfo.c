#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das cartas
// Objetivo: No nível novato você deve criar as cartas representando as cidades
// utilizando scanf para entrada de dados e printf para exibir as informações.

int main() {
  // ===============================
  // Área para definição das variáveis
  // ===============================
  // Cada variável vai armazenar uma propriedade da cidade
  char estado1, estado2;          // Letra do estado (A-H)
  char codigo1[4], codigo2[4];    // Código da carta (ex.: A01)
  char cidade1[60], cidade2[60];  // Nome da cidade
  int populacao1, populacao2;     // Número de habitantes
  float area1, area2;             // Área em km²
  float pib1, pib2;               // PIB da cidade
  int pontos1, pontos2;           // Pontos turísticos

  // ===============================
  // Área para entrada de dados
  // ===============================
  // Carta 1
  printf("====== Cadastro da Carta 1 ======\n");
  printf("\nDigite a letra do Estado (A-H): ");
  scanf(" %c", &estado1); // lê um caractere

  printf("\nDigite o Codigo da Carta (exemplo: A01): ");
  scanf(" %3s", codigo1); // lê até 3 caracteres para o código

  printf("\nDigite o Nome da Cidade: ");
  scanf(" %[^\n]", cidade1); // lê até encontrar ENTER (aceita espaços)

  printf("\nDigite a Populacao da cidade: ");
  scanf(" %d", &populacao1); // lê um número inteiro

  printf("\nDigite a Area da cidade em km²: ");
  scanf(" %f", &area1); // lê um número real (float)

  printf("\nDigite o PIB da cidade: ");
  scanf(" %f", &pib1); // lê um número real (float)

  printf("\nDigite o Numero de Pontos Turisticos: ");
  scanf(" %d", &pontos1); // lê um número inteiro

  printf("\n");

  printf("\n");

  // Carta 2
  printf("====== Cadastro da Carta 2 ======\n");
  printf("\nDigite a letra do Estado (A-H): ");
  scanf(" %c", &estado2);  // lê um caractere

  printf("\nDigite o Codigo da Carta (exemplo: B02): ");
  scanf(" %3s", codigo2); // lê até 3 caracteres para o código

  printf("\nDigite o Nome da Cidade: ");
  scanf(" %[^\n]", cidade2); // lê até encontrar ENTER (aceita espaços)

  printf("\nDigite a Populacao da cidade: ");
  scanf(" %d", &populacao2); // lê um número inteiro

  printf("\nDigite a Area da cidade em km²: ");
  scanf(" %f", &area2); // lê um número real (float)

  printf("\nDigite o PIB da cidade: ");
  scanf(" %f", &pib2); // lê um número real (float)

  printf("\nDigite o Numero de Pontos Turisticos: ");
  scanf(" %d", &pontos2); // lê um número inteiro

 // ===============================
  // Área para exibição dos dados
  // ===============================
  // Saída organizada, uma informação por linha, com descrições claras
  printf("\n========================================\n");
  printf("     INFORMACOES DAS CARTAS CADASTRADAS \n");
  printf("========================================\n");

  printf("\nCarta 1:\n");
  printf("\nEstado: %c\n", estado1);
  printf("\nCodigo: %s\n", codigo1);
  printf("\nNome da Cidade: %s\n", cidade1);
  printf("\nPopulacao: %d\n", populacao1);
  printf("\nArea: %.2f km²\n", area1);
  printf("\nPIB: %.2f bilhoes de reais\n", pib1);
  printf("\nNumero de Pontos Turisticos: %d\n", pontos1);

  printf("\n");
  printf("========================================\n");

  printf("\nCarta 2:\n");
  printf("\nEstado: %c\n", estado2);
  printf("\nCodigo: %s\n", codigo2);
  printf("\nNome da Cidade: %s\n", cidade2);
  printf("\nPopulacao: %d\n", populacao2);
  printf("\nArea: %.2f km²\n", area2);
  printf("\nPIB: %.2f bilhoes de reais\n", pib2);
  printf("\nNumero de Pontos Turisticos: %d\n", pontos2);

  return 0;
}