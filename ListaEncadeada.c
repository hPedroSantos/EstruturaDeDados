#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* Declaração das struct */
struct no {
    int dado;
    struct no *prox;
};

struct registro {
    int n;
    int primeiro_dado;
    int ultimo_dado;
};

int main(void) {
    int numNos; // Variável para armazenar o número de nós
    int i; // Variável de controle do loop

    printf("Digite o numero de nos: ");
    scanf("%d", &numNos);

    /* Semente para gerar números aleatórios */
    srand(time(NULL));

    /* Inicialização dos ponteiros dos nós */
    struct no *head = NULL;
    struct no *p = NULL;

    /* Inicialização dos ponteiros do registro */
    struct registro *d;
    d = malloc(sizeof(struct registro));
    d->n = 0; // Inicializa o número de elementos na lista com descritor como 0
    d->primeiro_dado = -1; // Inicializa o primeiro dado como -1, caso a lista esteja vazia
    d->ultimo_dado = -1; // Inicializa o último dado como -1, caso a lista esteja vazia

    /* Loop para criar nós aleatórios */
    for (i = 0; i < numNos; i++) {
        p = malloc(sizeof(struct no));
        p->dado = rand() % numNos;
        p->prox = NULL;

        if (head == NULL) {
            head = p;
        } else {
            struct no *temp = head;
            while (temp->prox != NULL) {
                temp = temp->prox;
            }
            temp->prox = p;
        }
    }

    /* Ordenar a lista encadeada */
    struct no *atual = head;
    int auxiliar;

    /* Ordenação bubbleSort */
    while (atual != NULL) {
        struct no *next = atual->prox;
        while (next != NULL) {
            if (atual->dado > next->dado) {
                auxiliar = atual->dado;
                atual->dado = next->dado;
                next->dado = auxiliar;
            }
            next = next->prox;
        }
        atual = atual->prox;
    }

    /*Calcular valor médio*/
    int soma = 0;
    atual = head;
    while(atual != NULL){
        soma += atual->dado;
        atual = atual->prox;
    }

    float valor_medio_float = (float)soma / numNos;
    int valor_medio = round(valor_medio_float);
    printf("Valor medio: %i\n", valor_medio);

    /*Remover o valor acima da média*/
    struct no *anterior = NULL;
    atual = head;
    while(atual != NULL && atual->dado <= valor_medio){
        anterior = atual;
        atual = atual->prox;
    }

    if(anterior == NULL){
        head = head->prox;
        free(anterior);
    }else if(atual != NULL){
        anterior->prox = atual->prox;
        free(atual);
    }

    /* Percorrer e imprimir a lista atualizada */
    struct no *temp = head;
    printf("Lista com calculo: \n");
    while(temp != NULL){
        printf("%i, ", temp->dado);
        temp = temp->prox;
    }
    printf("\n");

    // Atualiza os dados do descritor
    d->n = numNos; // Atualiza o número de elementos na lista com descritor

    // Atualiza os dados do primeiro e último nó na lista
    if (head != NULL) {
        d->primeiro_dado = head->dado;
        struct no *ultimo = head;
        while (ultimo->prox != NULL) {
            ultimo = ultimo->prox;
        }
        d->ultimo_dado = ultimo->dado;
    } else {
        d->primeiro_dado = -1; // Se a lista estiver vazia, define os valores como -1
        d->ultimo_dado = -1;
    }

    /* Imprimir dados do descritor */
    printf("Dados do descritor:\n");
    printf("Numero de nos: %d\n", d->n);
    printf("Primeiro dado: %d\n", d->primeiro_dado);
    printf("Ultimo dado: %d\n", d->ultimo_dado);

    /*liberar memória*/
    atual = head;
    while (atual != NULL) {
        struct no *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(d);

    return 0;
}
