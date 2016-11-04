#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>


typedef struct{
    int id_user;
    int id_playlist;
    char Status; /* '*' indica que o registro está apagado*/
}Favoritar_playlist;

FILE *arq_fav_playlist;

void arquivo_fav_playlist(){
	arq_fav_playlist = fopen("banco\\usuario_playlist.txt","r+b");	
}

void cadastro_playlist_favorita(int id_usuario, int id_playlist){
	
    Favoritar_playlist x;
    
    arquivo_fav_playlist();
    
	x.id_playlist = id_playlist;
	x.id_user = id_usuario;
	x.Status = ' ';
	fflush(stdin);
    
	fseek(arq_fav_playlist, 0L, SEEK_END);
    if(fwrite(&x, sizeof(x), 1, arq_fav_playlist)!=1)
        printf("Adicionar pessoa: Falhou a escrita do registro");
	
}

void busca_play_fav(int id_usuario, int id_playlist)
{

		arquivo_fav_playlist();
		
		Favoritar_playlist reg;

		rewind(arq_fav_playlist);	

		while(fread(&reg, sizeof(Favoritar_playlist), 1, arq_fav_playlist)){
	
		   	if(reg.id_user == id_usuario && reg.id_playlist == id_playlist){
		   		printf("X");
			}
		}
	
}


