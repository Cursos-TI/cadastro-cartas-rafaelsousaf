#include <stdio.h>
#include <string.h>

/*
  Super Trunfo — Comparação por 1 atributo (nível básico)

  Objetivo:
    - Manter duas cartas pré-definidas no código (sem entrada do usuário).
    - Calcular Densidade Populacional = População / Área.
    - Calcular PIB per capita = PIB / População (PIB em reais).
    - Comparar apenas UM atributo escolhido via #define (sem menu/interação).
    - Usar if / if-else para decidir a carta vencedora.
    - Exibir o atributo comparado, os valores das duas cartas e o resultado.

  Observações:
    - População é int, Área e PIB são float.
    - Para Densidade Populacional: menor valor vence.
    - Para os demais atributos: maior valor vence.
*/

// Seleção do atributo diretamente no código
typedef enum {
  ATTR_POPULACAO = 1,
  ATTR_AREA      = 2,
  ATTR_PIB       = 3,
  ATTR_DENSIDADE = 4, // menor vence
  ATTR_PIB_PC    = 5
} CompareAttr;

// Trocar aqui para comparar outro atributo
#define SELECTED_ATTR ATTR_PIB_PC

// Formata inteiro com pontos nos milhares (ex.: 12345678 -> "12.345.678")
static void format_int_with_dots(int value, char out[]) {
  char buf[32];
  snprintf(buf, sizeof(buf), "%d", value);
  int len = (int)strlen(buf);

  int dotCount = (len - 1) / 3;
  int outLen = len + dotCount;

  out[outLen] = '\0';

  int i = len - 1, j = outLen - 1, group = 0;
  while (i >= 0) {
    out[j--] = buf[i--];
    group++;
    if (group == 3 && i >= 0) {
      out[j--] = '.';
      group = 0;
    }
  }
}

int main(void) {
  // ---------------------------------------------------------------------------
  // Cartas pré-definidas
  // ---------------------------------------------------------------------------
  // Carta 1
  const char estado1[] = "GO";
  const char codigo1[] = "G01";
  const char cidade1[] = "Buriti Alegre";
  int   populacao1 = 10000;         // habitantes
  float area1      = 3000.0f;       // km²
  float pib1       = 1.0e9f;        // reais (ex.: 1 bilhão = 1.0e9)
  int   pontos1    = 3;

  // Carta 2
  const char estado2[] = "MG";
  const char codigo2[] = "M02";
  const char cidade2[] = "Samonte";
  int   populacao2 = 30000;
  float area2      = 10000.0f;
  float pib2       = 7.0e9f;        // 7 bilhões de reais
  int   pontos2    = 5;

  // ---------------------------------------------------------------------------
  // Cálculos derivados
  // ---------------------------------------------------------------------------
  float densidade1 = (area1 > 0.0f) ? ((float)populacao1 / area1) : 0.0f;
  float densidade2 = (area2 > 0.0f) ? ((float)populacao2 / area2) : 0.0f;

  float pibpc1 = (populacao1 > 0) ? (pib1 / (float)populacao1) : 0.0f;
  float pibpc2 = (populacao2 > 0) ? (pib2 / (float)populacao2) : 0.0f;

  // ---------------------------------------------------------------------------
  // Exibição das cartas
  // ---------------------------------------------------------------------------
  char pop1_fmt[40], pop2_fmt[40];
  format_int_with_dots(populacao1, pop1_fmt);
  format_int_with_dots(populacao2, pop2_fmt);

  printf("\n========================================\n");
  printf("     INFORMACOES DAS CARTAS (pre-definidas)\n");
  printf("========================================\n");

  printf("\nCarta 1:\n");
  printf("Estado: %s\n", estado1);
  printf("Codigo: %s\n", codigo1);
  printf("Cidade: %s\n", cidade1);
  printf("Populacao: %s\n", pop1_fmt);
  printf("Area: %.2f km²\n", area1);
  printf("PIB: R$ %.2f\n", pib1);
  printf("Pontos Turisticos: %d\n", pontos1);
  printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
  printf("PIB per Capita: R$ %.2f\n", pibpc1);

  printf("\n----------------------------------------\n");

  printf("\nCarta 2:\n");
  printf("Estado: %s\n", estado2);
  printf("Codigo: %s\n", codigo2);
  printf("Cidade: %s\n", cidade2);
  printf("Populacao: %s\n", pop2_fmt);
  printf("Area: %.2f km²\n", area2);
  printf("PIB: R$ %.2f\n", pib2);
  printf("Pontos Turisticos: %d\n", pontos2);
  printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
  printf("PIB per Capita: R$ %.2f\n", pibpc2);

  // ---------------------------------------------------------------------------
  // Comparação de um único atributo (if / if-else)
  // ---------------------------------------------------------------------------
  float valor1 = 0.0f, valor2 = 0.0f;
  const char* nomeAtributo = "";
  int menorVence = 0; // 0 = maior vence; 1 = menor vence (densidade)

  if (SELECTED_ATTR == ATTR_POPULACAO) {
    valor1 = (float)populacao1;
    valor2 = (float)populacao2;
    nomeAtributo = "Populacao";
    menorVence = 0;
  } else if (SELECTED_ATTR == ATTR_AREA) {
    valor1 = area1;
    valor2 = area2;
    nomeAtributo = "Area";
    menorVence = 0;
  } else if (SELECTED_ATTR == ATTR_PIB) {
    valor1 = pib1;   // em reais
    valor2 = pib2;
    nomeAtributo = "PIB";
    menorVence = 0;
  } else if (SELECTED_ATTR == ATTR_DENSIDADE) {
    valor1 = densidade1; // hab/km²
    valor2 = densidade2;
    nomeAtributo = "Densidade Populacional";
    menorVence = 1; // MENOR vence
  } else if (SELECTED_ATTR == ATTR_PIB_PC) {
    valor1 = pibpc1; // R$ por habitante
    valor2 = pibpc2;
    nomeAtributo = "PIB per Capita";
    menorVence = 0;
  } else {
    printf("\nAtributo de comparacao invalido.\n");
    return 0;
  }

  // Exibição dos valores do atributo escolhido
  printf("\n========================================\n");
  printf("Comparacao de cartas (Atributo: %s)\n", nomeAtributo);
  printf("========================================\n");

  if (SELECTED_ATTR == ATTR_POPULACAO) {
    printf("Carta 1 - %s (%s): %s\n", cidade1, estado1, pop1_fmt);
    printf("Carta 2 - %s (%s): %s\n", cidade2, estado2, pop2_fmt);
  } else if (SELECTED_ATTR == ATTR_AREA) {
    printf("Carta 1 - %s (%s): %.2f km²\n", cidade1, estado1, area1);
    printf("Carta 2 - %s (%s): %.2f km²\n", cidade2, estado2, area2);
  } else if (SELECTED_ATTR == ATTR_PIB) {
    printf("Carta 1 - %s (%s): R$ %.2f\n", cidade1, estado1, pib1);
    printf("Carta 2 - %s (%s): R$ %.2f\n", cidade2, estado2, pib2);
  } else if (SELECTED_ATTR == ATTR_DENSIDADE) {
    printf("Carta 1 - %s (%s): %.2f hab/km²\n", cidade1, estado1, densidade1);
    printf("Carta 2 - %s (%s): %.2f hab/km²\n", cidade2, estado2, densidade2);
  } else if (SELECTED_ATTR == ATTR_PIB_PC) {
    printf("Carta 1 - %s (%s): R$ %.2f\n", cidade1, estado1, pibpc1);
    printf("Carta 2 - %s (%s): R$ %.2f\n", cidade2, estado2, pibpc2);
  }

  // Decisão de vitória (if / if-else)
  if (menorVence == 1) {
    // Densidade: menor vence
    if (valor1 < valor2) {
      printf("\nResultado: Carta 1 (%s) venceu!\n", cidade1);
    } else if (valor2 < valor1) {
      printf("\nResultado: Carta 2 (%s) venceu!\n", cidade2);
    } else {
      printf("\nResultado: Empate!\n");
    }
  } else {
    // Demais atributos: maior vence
    if (valor1 > valor2) {
      printf("\nResultado: Carta 1 (%s) venceu!\n", cidade1);
    } else if (valor2 > valor1) {
      printf("\nResultado: Carta 2 (%s) venceu!\n", cidade2);
    } else {
      printf("\nResultado: Empate!\n");
    }
  }

  printf("\n");
  
  return 0;
}
