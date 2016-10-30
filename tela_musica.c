#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

typedef struct{
    char titulo[20+1];
    char autor[20+1];
    char Status; /* '*' indica que o registro está apagado*/
}musica;

void cadastrar_musica(musica *m){
    printf("\n\n\t titulo da musica:    "); gets(m->titulo);
    printf("\t autor:    "); gets(m->autor);
    m->Status = ' ';
    fflush(stdin);
}

void tela_musica_cadastrar(){
   
     
 			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|-------------- CADASTRAR MUSICA SPOTIFY --------------------|\n");
			printf("|------------------------------------------------------------|\n");


			FILE *arq_musica;
			arq_musica = fopen("banco\\musica.txt","r+b");

			musica m;
			
			cadastrar_musica(&m);
			
			fseek(arq_musica, 0L, SEEK_END);
		    if(fwrite(&m, sizeof(m), 1, arq_musica)!=1){
		    	printf("Adicionar musica: Falhou a escrita do registro");
		    	return 1;
			}
		
			printf("\n\n\t MUSICA CADASTRADA COM SUCESSO... :) \n\n \t DIGITE QUALQUER TECLA PARA VOLTAR: ");		
			getche();
			
			if(1 == 1){
				tela_index_adm();	
			}else{
				tela_index_user();
			}
        	
        	
        	
}

void tela_musica_listar(){
     
 			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|--------------- LISTAR MUSICA SPOTIFY ----------------------|\n");
			printf("|------------------------------------------------------------|\n");
            getch();
		
		
			printf("\n\n\t Digite qualquer tecla para voltar: ");		
			getche();
        	//tela_index_user();
        	
        	
}

void tela_musica_consultar(){
     
 			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|-------------- CONSULTAR MUSICA SPOTIFY --------------------|\n");
			printf("|------------------------------------------------------------|\n");
            getch();
		
		
			printf("\n\n\t Digite qualquer tecla para voltar: ");		
			getche();
        	//tela_index_user();
        	

}



void tela_musica_alterar(){
     
 			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|---------------- ALTERAR MUSICA SPOTIFY --------------------|\n");
			printf("|------------------------------------------------------------|\n");
            getch();
		
		
			printf("\n\n\t Digite qualquer tecla para voltar: ");		
			getche();
        	//tela_index_user();
        	

}

void tela_musica_excluir(){
     
 			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|---------------- EXCLUIR MUSICA SPOTIFY --------------------|\n");
			printf("|------------------------------------------------------------|\n");
            getch();
		
		
			printf("\n\n\t Digite qualquer tecla para voltar: ");		
			getche();
        	//tela_index_user();
        	

}

