#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* Declaração das struct */
struct no {
    int dado;
    struct no *prox;
};

struct descritor {
    int n;
    struct no *i;
    struct no *f;
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

    /* Inicialização dos ponteiros do descritor */
    struct descritor *d;
    d = malloc(sizeof(struct descritor));
    d->n = 0; // Inicializa o número de elementos na lista com descritor como 0
    d->i = NULL; // Inicializa o primeiro dado como NULL, caso a lista esteja vazia
    d->f = NULL; // Inicializa o último dado como NULL, caso a lista esteja vazia

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
    
    /* Impressão da lista original */
    printf("Lista original:\n");
    struct no *tempOriginal = head;
    while (tempOriginal != NULL) {
        printf("%d, ", tempOriginal->dado);
        tempOriginal = tempOriginal->prox;
    }
    printf("\n");

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

    // Atualiza os ponteiros do primeiro e último nó na lista
    d->i = head;
    struct no *ultimo = head;
    while (ultimo != NULL && ultimo->prox != NULL) {
        ultimo = ultimo->prox;
    }
    d->f = ultimo;

    /* Imprimir dados do descritor */
    printf("Dados do descritor:\n");
    printf("Numero de nos: %d\n", d->n);
    printf("Primeiro dado: %d\n", d->i->dado);
    printf("Ultimo dado: %d\n", d->f->dado);

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
