#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#define TAM_NOME 50
#define TAM_LOGIN 15
#define TAM_SENHA 15

typedef struct{
    char login[TAM_LOGIN+1];
    char senha[TAM_SENHA+1];
    char Status; /* '*' indica que o registro está apagado*/
}TipoPessoa;

FILE *usuario;

void usuario_repositorio(){
	usuario = fopen("banco\\usuario.txt","r+b");	
}


void tela_user_listar(char type_user){
     
            int opcao;

			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|--------------- LISTAR USUARIO SPOTIFY ---------------------|\n");
			printf("|------------------------------------------------------------|\n");

			usuario_repositorio();
			
		    long int n_Linhas = 0;
		    TipoPessoa reg;
		    rewind(usuario);
		    
		    while(1){
		    	
			    if(fread(&reg, sizeof(reg), 1, usuario)!= 1)break; /*Sair do laço*/
		        if(reg.Status=='*') continue; /*Passa ao próximo*/
		        
		        printf("%-30s %3s \n",reg.login, reg.senha);
		        
				n_Linhas++;
		        if(n_Linhas%20==0)
		            printf("Pressione <Enter> para continuar .  .  .");
		            
		    }
						
			printf("\n\n\t Digite qualquer tecla para voltar: ");		
			getche();	

			if(type_user == 'a'){
				tela_index_adm();
			}else{
				tela_index_user();	
			}

     
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

