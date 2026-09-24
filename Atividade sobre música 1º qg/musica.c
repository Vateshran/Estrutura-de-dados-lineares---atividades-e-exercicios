#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "musica.h"

struct musica {
    char titulo[100];
    char artista[100];
    int duracao;
};

Musica* criar_musica(char* titulo, char* artista, int duracao) {
    Musica* m = (Musica*) malloc(sizeof(Musica));
    if (m != NULL) {
        strcpy(m->titulo, titulo);
        strcpy(m->artista, artista);
        m->duracao = duracao;
    }
    return m;
}

void consultar_musica(Musica* m, char* titulo, char* artista, int* duracao) {
    if (m != NULL) {
        strcpy(titulo, m->titulo);
        strcpy(artista, m->artista);
        *duracao = m->duracao;
    }
}

void imprimir_musica(Musica* m) {
    if (m != NULL) {
        printf("Musica: %s | Artista: %s | Duracao: %d seg\n", m->titulo, m->artista, m->duracao);
    }
}

void liberar_musica(Musica* m) {
    free(m);
}