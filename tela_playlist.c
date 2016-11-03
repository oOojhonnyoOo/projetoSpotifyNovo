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
			printf("|------------------------------------------------------------|\n");
			printf("|---------------- LISTAR PLAYLIST SPOTIFY -------------------|\n");
			printf("|------------------------------------------------------------|\n");
		
			arquivo_playlist();

		    long int n_Linhas = 0;
		    Playlist reg;
		    rewind(arq_playlist);
		    
		    printf("\n\n\t TITULO DA PLAYLIST \t\t NOME DO USUARIO \t\t FAVORITAS \n");
		    printf("\t ---------------------------------------------------------------------------\n");
		    
		    while(1){
		    	
			    if(fread(&reg, sizeof(reg), 1, arq_playlist)!= 1)break; /*Sair do laço*/
		        if(reg.Status=='*') continue; /*Passa ao próximo*/
		        
		        printf("\t %-30s %10s \t\t\t * \n",reg.titulo,get_nome_usuario(reg.id_user));
		        
				n_Linhas++;
		        if(n_Linhas%20==0)
		            printf("Pressione <Enter> para continuar .  .  .");
		            
		    }
		
			printf("\n\n\t Digite qualquer tecla para voltar: ");		
			getche();
			
			if(type_user == 'a'){
				tela_index_adm();
			}else{
				tela_index_user(id_usuario);	
			}
        	

}


void tela_playlist_cadastrar(char type_user, int id_usuario){
     
 			system("cls");
			printf("|------------------------------------------------------------|\n");
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

			arquivo_playlist();

			char s[255+1];
		    printf("\n\t Pesquise o titulo da playlist: ");
		    gets(s);
			fflush(stdin);
			
		    Playlist reg;
		    rewind(arq_playlist);

		    printf("\n\n\t TITULO DA PLAYLIST \t\t NOME DO USUARIO\n");
		    printf("\t ------------------------------------------------\n");
		   
		    while(fread(&reg, sizeof(Playlist), 1, arq_playlist))
		        if(reg.Status!='*' && strstr(reg.titulo, s))
		            printf("\t %-30s %10s \n",reg.titulo,get_nome_usuario(reg.id_user));
		
			printf("\n\n\t Digite qualquer tecla para voltar: ");		
			getche();
			
			if(type_user == 'a'){
				tela_index_adm();
			}else{
				tela_index_user(id_usuario);	
			}

}


void tela_playlist_excluir(char type_user, int id_usuario){
     
 			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|--------------- EXCLUIR PLAYLIST SPOTIFY -------------------|\n");
			printf("|------------------------------------------------------------|\n");

			arquivo_playlist();

			
		
			printf("\n\n\t Digite qualquer tecla para voltar: ");		
			getche();
			
			if(type_user == 'a'){
				tela_index_adm();
			}else{
				tela_index_user(id_usuario);	
			}

}


void tela_playlist_minhas(char type_user, int id_usuario){
     
 			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|--------------- MINHAS PLAYLIST SPOTIFY --------------------|\n");
			printf("|------------------------------------------------------------|\n");
			
			
			arquivo_playlist();

		    long int n_Linhas = 0;
		    Playlist reg;
		    rewind(arq_playlist);
		    
		    printf("\n\n\t TITULO DA PLAYLIST \t\t NOME DO USUARIO \n");
		    printf("\t ------------------------------------------------\n");
		    
		    while(1){
		    	
			    if(fread(&reg, sizeof(reg), 1, arq_playlist)!= 1) break; /*Sair do laço*/
		        if(reg.Status=='*')  continue; /*Passa ao próximo*/
		        
		        if(reg.id_user == id_usuario){
			        printf("\t %-30s %10s \n",reg.titulo,get_nome_usuario(reg.id_user));		        	
				}
		        
				n_Linhas++;
		        if(n_Linhas%20==0)
		            printf("Pressione <Enter> para continuar .  .  .");
		            
		    }
		
			printf("\n\n\t Digite qualquer tecla para voltar: ");		
			getche();

			tela_index_user(id_usuario);	
       	

}



void tela_playlist_musica(char type_user, int id_usuario){
     
 			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|-------------- MUSICAS DA PLAYLIST SPOTIFY -----------------|\n");
			printf("|------------------------------------------------------------|\n");	
			
			arquivo_playlist();

			
		
			printf("\n\n\t Digite qualquer tecla para voltar: ");		
			getche();

			if(type_user == 'a'){
				tela_index_adm();
			}else{
				tela_index_user(id_usuario);	
			}	
       	

}


void tela_playlist_favoritar(char type_user, int id_usuario){
     
 			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|--------------- FAVORITAR PLAYLIST SPOTIFY -----------------|\n");
			printf("|------------------------------------------------------------|\n");	
			
			arquivo_playlist();

			
		
			printf("\n\n\t Digite qualquer tecla para voltar: ");		
			getche();

			if(type_user == 'a'){
				tela_index_adm();
			}else{
				tela_index_user(id_usuario);	
			}	
       	

}



void tela_playlist_cadastrar_musica(char type_user, int id_usuario){
     
 			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|------------ CADASTRAR MUSICA PLAYLIST SPOTIFY -------------|\n");
			printf("|------------------------------------------------------------|\n");	
			
			arquivo_playlist();

			
		
			printf("\n\n\t Digite qualquer tecla para voltar: ");		
			getche();

			if(type_user == 'a'){
				tela_index_adm();
			}else{
				tela_index_user(id_usuario);	
			}	
       	

}



void tela_playlist_listar_musica(char type_user, int id_usuario){
     
 			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|-------------- LISTAR MUSICA PLAYLIST SPOTIFY --------------|\n");
			printf("|------------------------------------------------------------|\n");	
			
			arquivo_playlist();

			
		
			printf("\n\n\t Digite qualquer tecla para voltar: ");		
			getche();

			if(type_user == 'a'){
				tela_index_adm();
			}else{
				tela_index_user(id_usuario);	
			}	
       	

}


void tela_playlist_excluir_musica(char type_user, int id_usuario){
     
 			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|------------- EXCLUIR MUSICA PLAYLIST SPOTIFY --------------|\n");
			printf("|------------------------------------------------------------|\n");	
			
			arquivo_playlist();

			
		
			printf("\n\n\t Digite qualquer tecla para voltar: ");		
			getche();

			if(type_user == 'a'){
				tela_index_adm();
			}else{
				tela_index_user(id_usuario);	
			}	
       	

}


