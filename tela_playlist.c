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
		    
		    printf("\n\n\t TITULO DA PLAYLIST \t\t NOME DO USUARIO \t FAVORITAS \n");
		    printf("\t ---------------------------------------------------------------------------\n");
		    
		    while(1){
		    	
			    if(fread(&reg, sizeof(reg), 1, arq_playlist)!= 1)break; /*Sair do laço*/
		        n_Linhas++;
				if(reg.Status=='*') continue; /*Passa ao próximo*/
		        
		        printf("\t %-30s %10s \t\t     ",reg.titulo,get_nome_usuario(reg.id_user));
				
				busca_play_fav(id_usuario,n_Linhas);
				
				printf("\n");
				
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
     
     		int id_escolha;
 			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|--------------- EXCLUIR PLAYLIST SPOTIFY -------------------|\n");
			printf("|------------------------------------------------------------|\n");

			arquivo_playlist();

			//listar playlists
		    long int n_Linhas = 0;
		    Playlist reg;
		    rewind(arq_playlist);
		    
		    printf("\n\n \t ID \t TITULO DA PLAYLIST \t\t NOME DO USUARIO \n");
		    printf("\t ---------------------------------------------------------\n");
		    
		    while(1){
		    	
			    if(fread(&reg, sizeof(reg), 1, arq_playlist)!= 1)break; /*Sair do laço*/
		        n_Linhas++;
				if(reg.Status=='*') continue; /*Passa ao próximo*/
		        if(reg.id_user == id_usuario){
			        printf("\t %i \t %-30s %10s \t\t \n",n_Linhas,reg.titulo,get_nome_usuario(reg.id_user));		        	
				}
				
		        if(n_Linhas%20==0)
		            printf("Pressione <Enter> para continuar .  .  .");
		            
		    }


			printf("\n\t Digite id da playlist que deseja excluir: ");
			scanf("%i", &id_escolha);
		    fflush(stdin); /*Despejar os arquivos no disco rígido*/
			
			//excluir playlist
		    Playlist x;
		    long int n_reg;
		    char resp;

		    if(fseek(arq_playlist, (id_escolha - 1)*sizeof(Playlist), SEEK_SET)!= 0){
		        printf("Registro inexistente ou problemas no registro!!!");
		        return 1;
		    }
		    if(fread(&x, sizeof(Playlist), 1, arq_playlist)!= 1){
		        printf("Problema na leitura do registro!!!");
		        return 1;
		    }
		    if(x.Status=='*'){
		        printf("Registro já está apagado!!!\n\n");
		        return 1;
		    }
		    
		    printf("\n\n Dados atuais \n\n");
		    
			printf(" titulo da playlist: %-30s \n",x.titulo);
		    
			printf("\n\n Apagar o registro (s/n)???: "); resp = getchar();
		    
			fflush(stdin);
		    
			if(toupper(resp)!= 'S') return 1;
		   
		    x.Status= '*';
		    // recuar um registro no arquivo
		    fseek(arq_playlist, -(long) sizeof(Playlist), SEEK_CUR);
		    // reescrever o registro;
		    fwrite(&x, sizeof(Playlist), 1, arq_playlist);
		    fflush(arq_playlist); /*Despejar os arquivos no disco rígido*/
			
		
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
     
     		int id_playlist;
     
 			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|--------------- FAVORITAR PLAYLIST SPOTIFY -----------------|\n");
			printf("|------------------------------------------------------------|\n");	
			
			arquivo_playlist();

		    long int n_Linhas = 0;
		    Playlist reg;
		    rewind(arq_playlist);
		    
		    printf("\n\n     ID  TITULO DA PLAYLIST \t\t NOME DO USUARIO \n");
		    printf("     -------------------------------------------------------\n");
		    
		    while(1){
		    	
			    if(fread(&reg, sizeof(reg), 1, arq_playlist)!= 1)break; /*Sair do laço*/
		        if(reg.Status=='*') continue; /*Passa ao próximo*/
		        n_Linhas++;
		        
		        if(id_usuario != reg.id_user){
		        	printf("     %i \t %-30s %10s \n",n_Linhas,reg.titulo,get_nome_usuario(reg.id_user));		        	
				}
		       	
		        if(n_Linhas%20==0)
		            printf("Pressione <Enter> para continuar .  .  .");
		            
		    }
			
			printf("\n\n     Digite a id da playlist para favoritar: ");
			scanf("%i", &id_playlist);

			cadastro_playlist_favorita(id_usuario,id_playlist);
			
			printf("\n\n     Sua playlist foi favoritada com sucesso... :)  \n     Digite qualquer tecla para voltar:");		
			getche();

			if(type_user == 'a'){
				tela_index_adm();
			}else{
				tela_index_user(id_usuario);	
			}	
       	

}



void tela_playlist_cadastrar_musica(char type_user, int id_usuario){
	
     		int id_mus_esc,id_play_esc; 			
			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|------------ CADASTRAR MUSICA PLAYLIST SPOTIFY -------------|\n");
			printf("|------------------------------------------------------------|\n");	
			
			arquivo_playlist();

			listar_musicas();
			
			printf("\n\t Digite o id da musica: ");
			scanf("%i", &id_mus_esc);

			//listar playlists
		    long int n_Linhas = 0;
		    Playlist reg;
		    rewind(arq_playlist);
		    
		    printf("\n\n \t ID \t TITULO DA PLAYLIST \t\t NOME DO USUARIO \n");
		    printf("\t ---------------------------------------------------------\n");
		    
		    while(1){
		    	
			    if(fread(&reg, sizeof(reg), 1, arq_playlist)!= 1)break; /*Sair do laço*/
		        n_Linhas++;
				if(reg.Status=='*') continue; /*Passa ao próximo*/
		        
		        printf("\t %i \t %-30s %10s \t\t \n",n_Linhas,reg.titulo,get_nome_usuario(reg.id_user));
				
		        if(n_Linhas%20==0)
		            printf("Pressione <Enter> para continuar .  .  .");
		            
		    }
			
			//escolher a playlist pelo codigo
			printf("\n\t Digite o id da playlist: ");
			scanf("%i", &id_play_esc);

			
			//vincular a musica a playlist	
			cadastrar_musica_playlist(id_mus_esc,id_play_esc);
			
			
			printf("\n\n\t Parabens, musica cadastrada na playlist com sucesso.. :) \n\t Digite qualquer tecla para voltar: ");		
			getche();

			if(type_user == 'a'){
				tela_index_adm();
			}else{
				tela_index_user(id_usuario);	
			}	
       	

}



void tela_playlist_listar_musica(char type_user, int id_usuario){
     
     		int id_play_esc; 
     
 			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|-------------- LISTAR MUSICA PLAYLIST SPOTIFY --------------|\n");
			printf("|------------------------------------------------------------|\n");	
			
			arquivo_playlist();


			//listar playlists
		    long int n_Linhas = 0;
		    Playlist reg;
		    rewind(arq_playlist);
		    
		    printf("\n\n \t ID \t TITULO DA PLAYLIST \t\t NOME DO USUARIO \n");
		    printf("\t ---------------------------------------------------------\n");
		    
		    while(1){
		    	
			    if(fread(&reg, sizeof(reg), 1, arq_playlist)!= 1)break; /*Sair do laço*/
		        n_Linhas++;
				if(reg.Status=='*') continue; /*Passa ao próximo*/   
		        printf("\t %i \t %-30s %10s \t\t \n",n_Linhas,reg.titulo,get_nome_usuario(reg.id_user));
				
		        if(n_Linhas%20==0)
		            printf("Pressione <Enter> para continuar .  .  .");
		            
		    }
			
			//escolher a playlist pelo codigo
			printf("\n\t Digite o id da playlist: ");
			scanf("%i", &id_play_esc);

			//listar todas as musicas da playlist
			printf("\n\n");
			buscar_musica_playlist(id_play_esc);
		
		
			printf("\n\n\t Digite qualquer tecla para voltar: ");		
			getche();

			if(type_user == 'a'){
				tela_index_adm();
			}else{
				tela_index_user(id_usuario);	
			}	
       	

}


void tela_playlist_excluir_musica(char type_user, int id_usuario){
     
     		int id_escolha;
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


