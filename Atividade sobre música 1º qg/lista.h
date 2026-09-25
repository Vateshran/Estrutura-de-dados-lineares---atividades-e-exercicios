#ifndef LISTA_H
#define LISTA_H
#include "musica.h"

typedef struct lista Lista;

Lista* criar_lista();
int inserir_inicio(Lista* l, Musica* m);
int inserir_final(Lista* l, Musica* m);
int inserir_posicao(Lista* l, Musica* m, int pos);
int remover_primeira(Lista* l);
int remover_ultima(Lista* l);
int remover_posicao(Lista* l, int pos);
Musica* consultar_primeira(Lista* l);
Musica* consultar_posicao(Lista* l, int pos);
int quantidade_musicas(Lista* l);
void liberar_lista(Lista* l);

#endif
