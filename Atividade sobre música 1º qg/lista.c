#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct no {
    Musica* musica;
    struct no* prox;
} No;

struct lista {
    No* inicio;
    int qtd;
};

Lista* criar_lista() {
    Lista* l = (Lista*) malloc(sizeof(Lista));
    if (l != NULL) {
        l->inicio = NULL;
        l->qtd = 0;
    }
    return l;
}

int inserir_inicio(Lista* l, Musica* m) {
    if (l == NULL || m == NULL) return 0;
    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) return 0;
    novo->musica = m;
    novo->prox = l->inicio;
    l->inicio = novo;
    l->qtd++;
    return 1;
}

int inserir_final(Lista* l, Musica* m) {
    if (l == NULL || m == NULL) return 0;
    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) return 0;
    novo->musica = m;
    novo->prox = NULL;
    if (l->inicio == NULL) {
        l->inicio = novo;
    } else {
        No* aux = l->inicio;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    l->qtd++;
    return 1;
}

int inserir_posicao(Lista* l, Musica* m, int pos) {
    if (l == NULL || m == NULL || pos < 0 || pos > l->qtd) return 0;
    if (pos == 0) return inserir_inicio(l, m);
    if (pos == l->qtd) return inserir_final(l, m);
    
    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) return 0;
    novo->musica = m;
    
    No* aux = l->inicio;
    for (int i = 0; i < pos - 1; i++) {
        aux = aux->prox;
    }
    novo->prox = aux->prox;
    aux->prox = novo;
    l->qtd++;
    return 1;
}

int remover_primeira(Lista* l) {
    if (l == NULL || l->inicio == NULL) return 0;
    No* aux = l->inicio;
    l->inicio = aux->prox;
    free(aux);
    l->qtd--;
    return 1;
}

int remover_ultima(Lista* l) {
    if (l == NULL || l->inicio == NULL) return 0;
    if (l->inicio->prox == NULL) {
        free(l->inicio);
        l->inicio = NULL;
    } else {
        No* ant = NULL;
        No* aux = l->inicio;
        while (aux->prox != NULL) {
            ant = aux;
            aux = aux->prox;
        }
        ant->prox = NULL;
        free(aux);
    }
    l->qtd--;
    return 1;
}

int remover_posicao(Lista* l, int pos) {
    if (l == NULL || l->inicio == NULL || pos < 0 || pos >= l->qtd) return 0;
    if (pos == 0) return remover_primeira(l);
    
    No* ant = NULL;
    No* aux = l->inicio;
    for (int i = 0; i < pos; i++) {
        ant = aux;
        aux = aux->prox;
    }
    ant->prox = aux->prox;
    free(aux);
    l->qtd--;
    return 1;
}

Musica* consultar_primeira(Lista* l) {
    if (l == NULL || l->inicio == NULL) return NULL;
    return l->inicio->musica;
}

Musica* consultar_posicao(Lista* l, int pos) {
    if (l == NULL || l->inicio == NULL || pos < 0 || pos >= l->qtd) return NULL;
    No* aux = l->inicio;
    for (int i = 0; i < pos; i++) {
        aux = aux->prox;
    }
    return aux->musica;
}

int quantidade_musicas(Lista* l) {
    if (l == NULL) return 0;
    return l->qtd;
}

void liberar_lista(Lista* l) {
    if (l != NULL) {
        No* aux = l->inicio;
        while (aux != NULL) {
            No* temp = aux;
            aux = aux->prox;
            free(temp); 
        }
        free(l);
    }
}