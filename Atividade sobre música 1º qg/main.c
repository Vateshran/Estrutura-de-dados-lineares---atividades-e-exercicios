#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void adiciona_musica(Lista* playlist, Musica* m) {
    inserir_final(playlist, m);
}

void adiciona_musica_posicao(Lista* playlist, Musica* m, int pos) {
    inserir_posicao(playlist, m, pos);
}

void remove_musica(Lista* playlist, int pos, int* pos_atual) {
    remover_posicao(playlist, pos);
    if (pos < *pos_atual) {
        (*pos_atual)--;
    }
}

int tempo_restante(Lista* playlist, int pos_atual) {
    int total = 0;
    int qtd = quantidade_musicas(playlist);
    for (int i = pos_atual; i < qtd; i++) {
        Musica* m = consultar_posicao(playlist, i);
        if (m != NULL) {
            char t[100], a[100];
            int d;
            consultar_musica(m, t, a, &d);
            total += d;
        }
    }
    return total;
}

void play(Lista* playlist, int* pos_atual) {
    Musica* m = consultar_posicao(playlist, *pos_atual);
    if (m != NULL) {
        printf("▶ Tocando agora: ");
        imprimir_musica(m);
        (*pos_atual)++;
    } else {
        printf("Fim da playlist. Nenhuma musica para tocar.\n");
    }
}

int musicas_reproduzidas(int pos_atual) {
    return pos_atual;
}

int main() {
    Lista* playlist = criar_lista();
    int pos_atual = 0;

    Musica* m1 = criar_musica("Smells Like Teen Spirit", "Nirvana", 301);
    Musica* m2 = criar_musica("Bohemian Rhapsody", "Queen", 354);
    Musica* m3 = criar_musica("Hotel California", "Eagles", 390);
    Musica* m4 = criar_musica("Stairway to Heaven", "Led Zeppelin", 482);
    Musica* m5 = criar_musica("Imagine", "John Lennon", 183);
    Musica* m6 = criar_musica("Hey Jude", "The Beatles", 431);
    Musica* m7 = criar_musica("Billie Jean", "Michael Jackson", 294);
    Musica* m8 = criar_musica("Like a Rolling Stone", "Bob Dylan", 373);
    Musica* m9 = criar_musica("Sweet Child O' Mine", "Guns N' Roses", 356);
    Musica* m10 = criar_musica("Wonderwall", "Oasis", 258);

    adiciona_musica(playlist, m1);
    adiciona_musica(playlist, m2);
    adiciona_musica(playlist, m3);
    adiciona_musica(playlist, m4);
    adiciona_musica(playlist, m5);
    adiciona_musica(playlist, m6);
    adiciona_musica(playlist, m7);
    adiciona_musica(playlist, m8);
    adiciona_musica(playlist, m9);
    
    adiciona_musica_posicao(playlist, m10, 3);

    printf("=== Iniciando Playlist ===\n");
    play(playlist, &pos_atual);
    play(playlist, &pos_atual);
    play(playlist, &pos_atual);

    printf("\nMusicas ja reproduzidas: %d\n", musicas_reproduzidas(pos_atual));
    
    int tr = tempo_restante(playlist, pos_atual);
    printf("Tempo total restante: %d segundos\n\n", tr);

    printf("Removendo musica da posicao 5...\n\n");
    remove_musica(playlist, 5, &pos_atual);
    
    play(playlist, &pos_atual);

    printf("\n=== Resumo Final ===\n");
    printf("Quantidade de musicas na playlist: %d\n", quantidade_musicas(playlist));
    printf("Posicao da proxima musica a ser reproduzida: %d\n", pos_atual);

    liberar_lista(playlist);
    liberar_musica(m1);
    liberar_musica(m2);
    liberar_musica(m3);
    liberar_musica(m4);
    liberar_musica(m5);
    liberar_musica(m6);
    liberar_musica(m7);
    liberar_musica(m8);
    liberar_musica(m9);
    liberar_musica(m10);
    
    return 0;
}