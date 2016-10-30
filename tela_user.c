#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>



void tela_user_listar(){
     
            int opcao;

			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|--------------- LISTAR USUARIO SPOTIFY ---------------------|\n");
			printf("|------------------------------------------------------------|\n");
			
			//edite aqui
			
			printf("\n\n\t Digite qualquer tecla para voltar: ");		
			getche();
        	tela_index_user();

     
}

void tela_user_consultar(){
     
 			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|------------- CONSULTAR USUARIO SPOTIFY --------------------|\n");
			printf("|------------------------------------------------------------|\n");
            getch();

			printf("\n\n\t Digite qualquer tecla para voltar: ");		
			getche();
        	tela_index_user();

}

