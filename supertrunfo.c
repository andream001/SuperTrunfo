#include <stdio.h>
#include <string.h>

struct Carta {
    char estado[50];
    int codigo;
    char nome_cidade[50];
    long populacao;
    float pib;
    float area;
    int pontos_turisticos;
    float densidade;
    float pib_per_capita;
};

void input_carta(struct Carta *c) {
    char buffer[100];

    //Estado
    printf("Digite o estado: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    strncpy(c->estado, buffer, 49);
    c->estado[49] = '\0';

    //Codigo
    printf("Digite o codigo: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &c->codigo);

    //Nome da cidade
    printf("Digite o nome da cidade: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    strncpy(c->nome_cidade, buffer, 49);
    c->nome_cidade[49] = '\0';

    //Populacao
    printf("Digite a populacao: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%ld", &c->populacao);

    //PIB
    printf("Digite o PIB: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%f", &c->pib);

    //Area
    printf("Digite a area: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%f", &c->area);

    //Pontos turisticos
    printf("Digite os pontos turisticos: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &c->pontos_turisticos);

    //Densidade
    c->densidade = c->populacao / c->area;
    c->pib_per_capita = c->pib / c->populacao;
}

void display_carta(struct Carta c) {
    printf("Estado: %s\n", c.estado);
    printf("Codigo: %d\n", c.codigo);
    printf("Nome da cidade: %s\n", c.nome_cidade);
    printf("Populacao: %ld\n", c.populacao);
    printf("PIB: %f\n", c.pib);
    printf("Area: %f\n", c.area);
    printf("Pontos turisticos: %d\n", c.pontos_turisticos);
    printf("Densidade: %f\n", c.densidade);
    printf("PIB per capita: %f\n", c.pib_per_capita);
}


int main() {
    struct Carta carta;

    input_carta(&carta);
    display_carta(carta);

    return 0;
}
