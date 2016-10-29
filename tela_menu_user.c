#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "tela_user.c"
#include "tela_musica.c"
#include "tela_perfil.c"


void tela_index_user(){

	char opcao;
	
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
					tela_user_listar();
					break;

				case 'b':
                    tela_user_consultar();
					break;           
           
				case 'c':
					tela_index_user();
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
					tela_musica_listar();
					break;

				case 'b':
					tela_musica_consultar();
					break;

				case 'c':
					tela_index_user();
					break;
				
			}
			
			break;
		
		case '3':

			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|------------------ PLAYLIST SPOTIFY ------------------------|\n");
			printf("|------------------------------------------------------------|\n");

			printf("\n\t a- listar todas as playlists");
			printf("\n\t b- cadastrar playlist musica ");
			printf("\n\t c- consultar playlist ");
			printf("\n\t d- minhas playlists ");
			printf("\n\t e- voltar ");

			printf("\n\n\t escolha sua opcao: ");		
			opcao = getche();
			
			switch(opcao){

				case 'a':
					tela_playlist_listar();
					break;

				case 'b':
					tela_playlist_cadastrar();
					break;

				case 'c':
					tela_playlist_consultar();
					break;

				case 'd':
					tela_playlist_listar();
					break;

				case 'e':
					tela_index_user();
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
			printf("\n\t c- voltar ");

			printf("\n\n\t escolha sua opcao: ");		
			opcao = getche();
			
			switch(opcao){

				case 'a':
					tela_perfil_nome();
					break;
					
				case 'b':
					tela_perfil_login();
					break;
                    					
				case 'c':
					tela_index_user();
					break;
				
			}
			
			break;

		case '5':

			system("pause");
			
			break;
		
	}
			
				
}


