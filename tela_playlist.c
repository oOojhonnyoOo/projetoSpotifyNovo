#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>


typedef struct{
    char titulo[50+1];
    int id_user;
    char Status; /* '*' indica que o registro está apagado*/
}Playlist;

void cadastrar_playlist(Playlist *p,int id_usuario){
    printf("\n\n\t Digite o titulo da playlist:    "); gets(p->titulo);
    p->id_user = id_usuario;
    p->Status = ' ';
    fflush(stdin);
}

FILE *arq_playlist;

void arquivo_playlist(){
	arq_playlist = fopen("banco\\playlist.txt","r+b");	
}



void tela_playlist_listar(char type_user, int id_usuario){
     
 			system("cls");
			printf("|------------------------------------------------------------%i|\n",id_usuario);
			printf("|---------------- LISTAR PLAYLIST SPOTIFY -------------------|\n");
			printf("|------------------------------------------------------------|\n");
		
			arquivo_playlist();

		    long int n_Linhas = 0;
		    Playlist reg;
		    rewind(arq_playlist);
		    
		    while(1){
		    	
			    if(fread(&reg, sizeof(reg), 1, arq_playlist)!= 1)break; /*Sair do laço*/
		        if(reg.Status=='*') continue; /*Passa ao próximo*/
		        
		        printf("%-30s %3s \n",reg.titulo, reg.id_user);
		        
				n_Linhas++;
		        if(n_Linhas%20==0)
		            printf("Pressione <Enter> para continuar .  .  .");
		            
		    }
		    printf("\n\n Pressione <Enter> para continuar .  .  .  "); /*No fim da listagem*/
			
		
			printf("\n\n\t Digite qualquer tecla para voltar: ");		
			getche();
        	tela_index_user(id_usuario);
        	

}


void tela_playlist_cadastrar(char type_user, int id_usuario){
     
 			system("cls");
			printf("|------------------------------------------------------------%i|\n",id_usuario);
			printf("|------------- CADASTRAR PLAYLIST SPOTIFY -------------------|\n");
			printf("|------------------------------------------------------------|\n");
		
			arquivo_playlist();
		
		    Playlist x;    
			cadastrar_playlist(&x,id_usuario);
		    
			fseek(arq_playlist, 0L, SEEK_END);
		    if(fwrite(&x, sizeof(x), 1, arq_playlist)!=1)
		        printf("Adicionar pessoa: Falhou a escrita do registro");
				
			printf("\n\n\t Playlist cadastrada com sucesso ... :) \n\t digite qualquer tecla para voltar ao menu: ");		
			getche();
        	tela_index_user(id_usuario);
        	

}

void tela_playlist_consultar(char type_user, int id_usuario){
     
 			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|------------- CONSULTAR PLAYLIST SPOTIFY -------------------|\n");
			printf("|------------------------------------------------------------|\n");
            getch();
		
		
			printf("\n\n\t Digite qualquer tecla para voltar: ");		
			getche();
        	tela_index_user(id_usuario);
        	

}


void tela_playlist_minhas(char type_user, int id_usuario){
     
 			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|--------------- MINHAS PLAYLIST SPOTIFY --------------------|\n");
			printf("|------------------------------------------------------------|\n");
            getch();
		
		
			printf("\n\n\t Digite qualquer tecla para voltar: ");		
			getche();
        	tela_index_user(id_usuario);
        	

}

