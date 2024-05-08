#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* Declaração das structs */
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
    int i; // Movido a declaração da variável 'i' para o início do escopo da função 'main'

    printf("Digite o numero de nos: ");
    scanf("%d", &numNos);

    /* Semente para gerar números aleatórios */
    srand(time(NULL));


    /* Inicialização dos ponteiros dos nós */
    struct no *q = NULL;
    struct no *head = NULL;
    struct no *p = NULL;

    /* Inicialização dos ponteiros do descritor */
    struct descritor *d;
    d = malloc(sizeof(struct descritor));
    d->i = NULL;
    d->f = NULL;
    d->n = 0;

    /* Loop para criar nós aleatórios */
    for (i = 0; i < numNos; i++) { // Corrigido o erro do 'for' loop com declaração inicial
        if (p == NULL) {
            p = malloc(sizeof(struct no));
        }

        p->dado = rand() % numNos;
        p->prox = NULL;

        if (head == NULL) {
            head = p;
        } else {
            /* Encontrar a posição correta para inserir o novo nó */
            q = head;
            while (q->prox != NULL && q->prox->dado < p->dado) {
                q = q->prox;
            }

            /* Inserir o novo nó */
            p->prox = q->prox;
            q->prox = p;
        }

        /* Atualizar o valor de p */
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

    /* Calcular valor médio */
    int soma = 0;
    p = head;
    while (p != NULL) {
        soma += p->dado;
        p = p->prox;
    }
    float valor_medio_float = (float)soma / numNos;
    int valor_medio = round(valor_medio_float);
    printf("Valor medio: %i\n", valor_medio);

    /* Remover o primeiro nó com valor superior ao valor médio */
    struct no *anterior = NULL;
    p = head;
    while (p != NULL && p->dado <= valor_medio) {
        anterior = p;
        p = p->prox;
    }

    if (anterior == NULL) {
        head = head->prox;
        free(anterior);
    } else if (p != NULL) {
        anterior->prox = p->prox;
        free(p);
    }

    /* Criar e preencher a Lista com Descritor */
    d->i = head;
    d->f = q;
    d->n = numNos;

    /* Imprimir a Lista com Descritor final */
    printf("Lista com descritor: \n");
    struct no *temp_descritor = d->i;
    while (temp_descritor != NULL) {
        printf("%i, ", temp_descritor->dado);
        temp_descritor = temp_descritor->prox;
    }
    printf("\n");
    
    printf("Acessando os dados do descritor:\n");
    printf("Dado de i: %d - Dado de f: %d - Dado de n: %d", d->i->dado, d->f->dado, d->f->dado);


    return 0;
}
