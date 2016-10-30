#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "tela_musica.c"


void tela_index_adm(){

	char opcao;
	
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
					//tela_user_listar();
					break;

				case 'b':
                    //tela_user_consultar();
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
			printf("\n\t e- Voltar ");

			printf("\n\n\t escolha sua opcao: ");		
			opcao = getche();
			
			switch(opcao){


				case 'a':
					tela_musica_cadastrar();
					break;

				case 'b':
					//tela_musica_consultar();
					break;
				case 'c':
					//tela_musica_consultar();
					break;
			
				case 'd':
					//tela_musica_consultar();
					break;

				case 'e':
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
					//tela_playlist_listar();
					break;

				case 'b':
					//tela_playlist_cadastrar();
					break;

				case 'c':
					//tela_playlist_consultar();
					break;

				case 'd':
					//tela_playlist_minhas();
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


