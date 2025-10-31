#include <stdio.h>
#include <string.h> // strlen para o formatador

// Desafio Super Trunfo - Países
// Nível avançado: Cadastro + Cálculos + Comparação atributo a atributo
//
// Regras de comparação:
//   • Para todos os atributos (exceto densidade), vence o MAIOR valor.
//   • Para densidade populacional, vence o MENOR valor.
//   • Exibir 1 quando a Carta 1 vence e 0 caso contrário (Carta 2 vence ou empate).

// --------- Utilitário: formata unsigned long com pontos nos milhares ----------
void format_ull_with_dots(unsigned long value, char out[]) {
  char buf[32];
  snprintf(buf, sizeof(buf), "%lu", value); // número "cru"
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

int main() {
  // ===============================
  // Área para definição das variáveis
  // ===============================
  char estado1[3], estado2[3];     // 2 letras + '\0' (ex.: "SP")
  char codigo1[4], codigo2[4];     // Código da carta (ex.: A01)
  char cidade1[60], cidade2[60];   // Nome da cidade

  // *** unsigned long para suportar populações grandes ***
  unsigned long populacao1, populacao2;

  float area1, area2;               // km²
  float pib1, pib2;                 // bilhões de R$
  int   pontos1, pontos2;           // pontos turísticos

  // Variáveis de cálculo
  double densidade1, densidade2;    // hab/km²
  double pibpc1, pibpc2;            // R$/hab
  double invDens1, invDens2;        // área/população
  float  superPoder1, superPoder2;  // soma pedida

  // ===============================
  // Entrada de dados
  // ===============================
  // Carta 1
  printf("====== Cadastro da Carta 1 ======\n");
  printf("\nDigite a sigla do estado (ex.: SP): ");
  scanf(" %2s", estado1);

  printf("\nDigite o Codigo da Carta (exemplo: A01): ");
  scanf(" %3s", codigo1);

  printf("\nDigite o Nome da Cidade: ");
  scanf(" %59[^\n]", cidade1);

  printf("\nDigite a Populacao da cidade: ");
  scanf(" %lu", &populacao1);  // *** %lu ***

  printf("\nDigite a Area da cidade em km²: ");
  scanf(" %f", &area1);

  printf("\nDigite o PIB da cidade (em bilhoes de R$): ");
  scanf(" %f", &pib1);

  printf("\nDigite o Numero de Pontos Turisticos: ");
  scanf(" %d", &pontos1);

  printf("\n\n");

  // Carta 2
  printf("====== Cadastro da Carta 2 ======\n");
  printf("\nDigite a sigla do estado (ex.: SP): ");
  scanf(" %2s", estado2);

  printf("\nDigite o Codigo da Carta (exemplo: B02): ");
  scanf(" %3s", codigo2);

  printf("\nDigite o Nome da Cidade: ");
  scanf(" %59[^\n]", cidade2);

  printf("\nDigite a Populacao da cidade: ");
  scanf(" %lu", &populacao2);  // *** %lu ***

  printf("\nDigite a Area da cidade em km²: ");
  scanf(" %f", &area2);

  printf("\nDigite o PIB da cidade (em bilhoes de R$): ");
  scanf(" %f", &pib2);

  printf("\nDigite o Numero de Pontos Turisticos: ");
  scanf(" %d", &pontos2);

  // ===============================
  // Cálculos derivados
  // ===============================
  densidade1 = (area1 > 0.0f) ? ((double)populacao1 / (double)area1) : 0.0;
  densidade2 = (area2 > 0.0f) ? ((double)populacao2 / (double)area2) : 0.0;

  // PIB per capita: converter bilhões -> reais
  pibpc1 = (populacao1 > 0UL) ? ((double)pib1 * 1e9 / (double)populacao1) : 0.0;
  pibpc2 = (populacao2 > 0UL) ? ((double)pib2 * 1e9 / (double)populacao2) : 0.0;

  // Inverso da densidade
  invDens1 = (populacao1 > 0UL) ? ((double)area1 / (double)populacao1) : 0.0;
  invDens2 = (populacao2 > 0UL) ? ((double)area2 / (double)populacao2) : 0.0;

  // Super Poder = população + área + PIB(bi) + pontos + PIB_pc(R$) + inverso da densidade
  superPoder1 = (float)((double)populacao1 + (double)area1 + (double)pib1
                      + (double)pontos1 + pibpc1 + invDens1);
  superPoder2 = (float)((double)populacao2 + (double)area2 + (double)pib2
                      + (double)pontos2 + pibpc2 + invDens2);

  // ===============================
  // Exibição dos dados (com população formatada)
  // ===============================
  char pop1_fmt[40], pop2_fmt[40];
  format_ull_with_dots(populacao1, pop1_fmt);
  format_ull_with_dots(populacao2, pop2_fmt);

  printf("\n========================================\n");
  printf("     INFORMACOES DAS CARTAS CADASTRADAS \n");
  printf("========================================\n");

  printf("\nCarta 1:\n");
  printf("\nEstado: %s\n", estado1);
  printf("\nCodigo: %s\n", codigo1);
  printf("\nNome da Cidade: %s\n", cidade1);
  printf("\nPopulacao: %s\n", pop1_fmt);                 // <<< aqui
  printf("\nArea: %.2f km²\n", area1);
  printf("\nPIB: %.2f bilhoes de reais\n", pib1);
  printf("\nNumero de Pontos Turisticos: %d\n", pontos1);
  printf("\nDensidade Populacional: %.2f hab/km²\n", densidade1);
  printf("\nPIB per capita: R$ %.2f\n", pibpc1);
  printf("\nSuper Poder: %.2f\n", superPoder1);

  printf("\n");
  printf("========================================\n");

  printf("\nCarta 2:\n");
  printf("\nEstado: %s\n", estado2);
  printf("\nCodigo: %s\n", codigo2);
  printf("\nNome da Cidade: %s\n", cidade2);
  printf("\nPopulacao: %s\n", pop2_fmt);                 // <<< aqui
  printf("\nArea: %.2f km²\n", area2);
  printf("\nPIB: %.2f bilhoes de reais\n", pib2);
  printf("\nNumero de Pontos Turisticos: %d\n", pontos2);
  printf("\nDensidade Populacional: %.2f hab/km²\n", densidade2);
  printf("\nPIB per capita: R$ %.2f\n", pibpc2);
  printf("\nSuper Poder: %.2f\n", superPoder2);

  // ===============================
  // Comparações atributo a atributo
  // ===============================
  int c_pop  = (populacao1  > populacao2);
  int c_area = (area1       > area2);
  int c_pib  = (pib1        > pib2);
  int c_pts  = (pontos1     > pontos2);
  int c_den  = (densidade1  < densidade2); // MENOR vence
  int c_pc   = (pibpc1      > pibpc2);
  int c_sp   = (superPoder1 > superPoder2);

  printf("\n========================================\n");
  printf("Comparacao de Cartas:\n");
  printf("Populacao: %s venceu (%d)\n", c_pop ? "Carta 1" : "Carta 2", c_pop);
  printf("Area: %s venceu (%d)\n", c_area ? "Carta 1" : "Carta 2", c_area);
  printf("PIB: %s venceu (%d)\n", c_pib ? "Carta 1" : "Carta 2", c_pib);
  printf("Pontos Turisticos: %s venceu (%d)\n", c_pts ? "Carta 1" : "Carta 2", c_pts);
  printf("Densidade Populacional: %s venceu (%d)\n", c_den ? "Carta 1" : "Carta 2", c_den);
  printf("PIB per Capita: %s venceu (%d)\n", c_pc ? "Carta 1" : "Carta 2", c_pc);
  printf("Super Poder: %s venceu (%d)\n", c_sp ? "Carta 1" : "Carta 2", c_sp);

  printf("\n");
  return 0;
}
