#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>


typedef struct{
    int id_musica;
    int id_playlist;
    char Status; /* '*' indica que o registro está apagado*/
}Musica_playlist;

FILE *arq_mus_playlist;

void arquivo_mus_playlist(){
	arq_mus_playlist = fopen("banco\\musica_playlist.txt","r+b");	
}

void cadastro_mus_play(int id_musica, int id_playlist){
	
    Musica_playlist x;
    
    arq_mus_playlist();
    
	x.id_playlist = id_playlist;
	x.id_user = id_musica;
	x.Status = ' ';
	fflush(stdin);
    
	fseek(arq_fav_playlist, 0L, SEEK_END);
    if(fwrite(&x, sizeof(x), 1, arq_mus_playlist)!=1)
        printf("Adicionar pessoa: Falhou a escrita do registro");
	
}

