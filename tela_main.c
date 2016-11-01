#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "tela_user.c"
#include "tela_musica.c"
#include "tela_perfil.c"
#include "tela_playlist.c"

#define TAM_NOME 50
#define TAM_LOGIN 15
#define TAM_SENHA 15

char opcao;
char type_user;



void tela_index_user(int id_usuario){
	
	type_user = 'u';
	
	system("cls");
	
	printf("|------------------------------------------------------------|\n");
	printf("|------------- BEM VINDO AO MENU SPOTIFY --------------------|\n");
	printf("|------------------------------------------------------------|\n");
	
	printf("\n\t 1- Usuario ");
	printf("\n\t 2- Musica ");
	printf("\n\t 3- Playlist ");
	printf("\n\t 4- Confiturar perfil ");
	printf("\n\t 5- Sair ");
			
	printf("\n\n\t escolha sua opcao: ");		
	opcao = getche();
	
	switch(opcao){

		case '1':

			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|--------------- LISTAR USUARIO SPOTIFY ---------------------|\n");
			printf("|------------------------------------------------------------|\n");
			
			printf("\n\t a- listar usuario");
			printf("\n\t b- consultar usuario ");
			printf("\n\t c- voltar ");
			
			printf("\n\n\t escolha sua opcao: ");		
			opcao = getche();
			
			switch(opcao){

				case 'a':
					tela_user_listar(type_user,id_usuario);
					break;

				case 'b':
                    tela_user_consultar(type_user,id_usuario);
					break;           
           
				case 'c':
					tela_index_user(id_usuario);
					break;
				
			}
			
			break;
		
		case '2':

			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|-------------- CONSULTAR MUSICA SPOTIFY --------------------|\n");
			printf("|------------------------------------------------------------|\n");

			printf("\n\t a- listar musica");
			printf("\n\t b- consultar musica ");
			printf("\n\t c- voltar ");

			printf("\n\n\t escolha sua opcao: ");		
			opcao = getche();
			
			switch(opcao){


				case 'a':
					tela_musica_listar(type_user,id_usuario);
					break;

				case 'b':
					tela_musica_consultar(type_user,id_usuario);
					break;

				case 'c':
					tela_index_user(id_usuario);
					break;
				
			}
			
			break;
		
		case '3':

			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|------------------ PLAYLIST SPOTIFY ------------------------|\n");
			printf("|------------------------------------------------------------|\n");

			printf("\n\t a- listar todas as playlists");
			printf("\n\t b- cadastrar playlist ");
			printf("\n\t c- consultar playlist ");
			printf("\n\t d- minhas playlists ");
			printf("\n\t e- voltar ");

			printf("\n\n\t escolha sua opcao: ");		
			opcao = getche();
			
			switch(opcao){

				case 'a':
					tela_playlist_listar(type_user,id_usuario);
					break;

				case 'b':
					tela_playlist_cadastrar(type_user,id_usuario);
					break;

				case 'c':
					tela_playlist_consultar(type_user,id_usuario);
					break;

				case 'd':
					tela_playlist_minhas(type_user,id_usuario);
					break;

				case 'e':
					tela_index_user(id_usuario);
					break;
				
			}
			
			break;
		
		case '4':

			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|------------- CONFIGURAR PERFIL SPOTIFY --------------------|\n");
			printf("|------------------------------------------------------------|\n");

			printf("\n\t a- alterar nome");
			printf("\n\t b- alterar login ");
			printf("\n\t c- alterar senha ");
			printf("\n\t d- voltar ");

			printf("\n\n\t escolha sua opcao: ");		
			opcao = getche();
			
			switch(opcao){

				case 'a':
					tela_perfil_nome(type_user,id_usuario);
					break;
					
				case 'b':
					tela_perfil_login(type_user,id_usuario);
					break;
					
				case 'c':
					tela_perfil_senha(type_user,id_usuario);
					break;
                    					
				case 'd':
					tela_index_user(id_usuario);
					break;
				
			}
			
			break;

		case '5':

			system("cls");
			system("pause");
			
			break;
		
	}
			
				
}

void tela_index_adm(){

	type_user = 'a';

	system("cls");

	printf("|------------------------------------------------------------|\n");
	printf("|------------- BEM VINDO AO MENU SPOTIFY --------------------|\n");
	printf("|------------------------------------------------------------|\n");
	
	printf("\n\t 1- Usuario ");
	printf("\n\t 2- Musica ");
	printf("\n\t 3- Playlist ");
	printf("\n\t 4- Sair ");
			
	printf("\n\n\t escolha sua opcao: ");		
	opcao = getche();
	
	switch(opcao){

		case '1':

			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|------------------- USUARIO SPOTIFY ------------------------|\n");
			printf("|------------------------------------------------------------|\n");
			
			printf("\n\t a- Listar usuario");
			printf("\n\t b- Consultar usuario ");
			printf("\n\t c- Alterar senha usuario");
			printf("\n\t c- voltar ");
			
			printf("\n\n\t escolha sua opcao: ");		
			opcao = getche();
			
			switch(opcao){

				case 'a':
					tela_user_listar(type_user,99);
					break;

				case 'b':
                    tela_user_consultar(type_user,99);
					break;           
           
				case 'c':
					tela_index_adm();
					break;
				
			}
			
			break;
		
		case '2':

			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|------------------- MUSICA SPOTIFY -------------------------|\n");
			printf("|------------------------------------------------------------|\n");

			printf("\n\t a- Cadastrar musica ");
			printf("\n\t b- Listar musica");
			printf("\n\t c- Consultar musica ");
			printf("\n\t d- Alterar musica ");
			printf("\n\t e- Excluir musica ");
			printf("\n\t f- Voltar ");

			printf("\n\n\t escolha sua opcao: ");		
			opcao = getche();
			
			switch(opcao){


				case 'a':
					tela_musica_cadastrar(type_user,99);
					break;

				case 'b':
					tela_musica_listar(type_user,99);
					break;
				case 'c':
					tela_musica_consultar(type_user,99);
					break;
			
				case 'd':
					tela_musica_alterar(type_user,99);
					break;
				
				case 'e':
					tela_musica_excluir(type_user,99);
					break;

				case 'f':
					tela_index_adm();
					break;
				
			}
			
			break;
		
		case '3':

			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|------------------ PLAYLIST SPOTIFY ------------------------|\n");
			printf("|------------------------------------------------------------|\n");

			printf("\n\t a- listar todas as playlists");
			printf("\n\t c- consultar playlist ");
			printf("\n\t e- voltar ");

			printf("\n\n\t escolha sua opcao: ");		
			opcao = getche();
			
			switch(opcao){

				case 'a':
					//tela_playlist_listar(type_user,99);
					break;

				case 'b':
					//tela_playlist_cadastrar(type_user,99);
					break;

				case 'c':
					//tela_playlist_consultar(type_user,99);
					break;

				case 'd':
					//tela_playlist_minhas(type_user,99);
					break;

				case 'e':
					tela_index_adm();
					break;
				
			}
			
			break;
		
		case '4':

			system("pause");
			
			break;
		
	}
			
				
}

