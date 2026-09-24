#ifndef MUSICA_H
#define MUSICA_H

typedef struct musica Musica;

Musica* criar_musica(char* titulo, char* artista, int duracao);
void consultar_musica(Musica* m, char* titulo, char* artista, int* duracao);
void imprimir_musica(Musica* m);
void liberar_musica(Musica* m);

#endif
