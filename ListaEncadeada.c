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
    int numNos;

    printf("Digite o número de nós: ");
    scanf("%d", &numNos);

    /* Semente para gerar números aleatórios */
    srand(time(NULL));

    /* Inicialização dos ponteiros dos nós */
    struct no *q = NULL;
    struct no *head = NULL;
    struct no *p = NULL;

    /* Inicialização dos ponteiros do registror */
    struct descritor *d;
    d = malloc(sizeof(struct descritor));
    d->i = NULL;
    d->f = NULL;
    d->n = 0;

    /* Loop para criar nós aleatórios */
    for (int i = 0; i < numNos; i++) {
        if (p == NULL) {
            p = malloc(sizeof(struct no));
        }

        p->dado = rand() % numNos;
        p->prox = NULL;

        if (head == NULL) {
            head = p;
        } else {
            /* O campo prox do ponteiro q está apontando para o endereço de mem. de p, linkando a lista */
            q->prox = p;
        }
        /* Apontar para o ultimo nó */
        q = p;
        /* Atualizar o valor para inteirar corretamente */
        p = NULL;
    }

    /* Imprimir a lista original */
    printf("Lista original: \n");
    struct no *temp_original = head;
    while (temp_original != NULL) {
        printf("%d, ", temp_original->dado);
        temp_original = temp_original->prox;
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

    /* Imprimir a lista ordenada */
    printf("Lista ordenada: \n");
    struct no *temp_ordenada = head;
    while (temp_ordenada != NULL) {
        printf("%d, ", temp_ordenada->dado);
        temp_ordenada = temp_ordenada->prox;
    }
    printf("\n");

    /*Calcular valor médio*/
    int soma = 0;
    atual = head;
    while(atual != NULL){
        soma += atual -> dado;
        atual = atual -> prox;
    }

    float valor_medio_float = (float)soma / numNos;
    int valor_medio = round(valor_medio_float);
    printf("Valor médio: %i\n", valor_medio);

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

    // Percorrer e imprimir a lista atualizada
    struct no *temp = head;
    printf("Lista com cálculo: \n");
    while(temp != NULL){
        printf("%i, ", temp->dado);
        temp = temp->prox;
    }
    printf("\n");

    d->i = head;
    d->f = q;
    d->n = numNos;

    /*lista com descritor*/
    printf("Lista com descritor: \n");
    struct no *temp_descritor = d->i;
    while(temp_descritor != NULL){
        printf("%i, ", temp_descritor -> dado);
        temp_descritor = temp_descritor -> prox;
    }

    printf("\n");


    return 0;
}



/*Exercício proposto abaixo*/

/*Usuário informa numero de nós a inserir aleatoriamente em uma Lista Simplesmente Encadeada.
Obs: o campo dado dos nós é um número inteiro
Os nós são transferidos em ordem crescente do campo dado para uma Lista com Descritor
O algorítmo deve calcular o valor médio dos nós na LCD e remover o primeiro nó com valor
imediatamente superior ao valor médio.
Imprimir a Lista com Descritor final.*/