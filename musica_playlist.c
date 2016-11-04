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

void cadastrar_musica_playlist(int id_musica, int id_playlist){

    Musica_playlist x;
    
    arquivo_mus_playlist();
    
	x.id_playlist = id_playlist;
	x.id_musica = id_musica;
	x.Status = ' ';
	fflush(stdin);
    
	fseek(arq_mus_playlist, 0L, SEEK_END);
    if(fwrite(&x, sizeof(x), 1, arq_mus_playlist)!=1)
        printf("Adicionar pessoa: Falhou a escrita do registro");
		
		
}

void buscar_musica_playlist(int id_playlist){
	
	arquivo_mus_playlist();
	
    Musica_playlist reg;
    rewind(arq_mus_playlist);
    long int n_Linhas = 0;
    
    printf("\t NOME DA MUSICA \t\t NOME DO AUTOR \n");
    printf("\t ------------------------------------------------------- \n");
    
    while(1){
    	
	    if(fread(&reg, sizeof(reg), 1, arq_mus_playlist)!= 1)break; /*Sair do laço*/
        n_Linhas++;
		if(reg.Status=='*') continue; /*Passa ao próximo*/
		
		if(reg.id_playlist == id_playlist){
        	get_nome_autor_musica(reg.id_musica);
		}
		
        if(n_Linhas%20==0)
            printf("Pressione <Enter> para continuar .  .  .");
    }
	
}

