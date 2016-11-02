#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "tela_main.c"

#define TAM_NOME 50
#define TAM_LOGIN 15
#define TAM_SENHA 15

typedef struct{
    char login[TAM_LOGIN+1];
    char nome[TAM_NOME+1];
    char senha[TAM_SENHA+1];
    char Status; /* '*' indica que o registro está apagado*/
}Pessoa;

void cadastrar_Pessoa(Pessoa *p){
    int w;
    char verifica;
	printf("\n\n\t Digite seu nome:    "); gets(p->nome);
	printf("\t Digite seu login:    "); gets(p->login);
    printf("\t Digite sua senha:    ");
	for ( w = 0 ; w < TAM_SENHA ; w++ ) {
			   	
		verifica = getch();
		       
		if (verifica == 13){
			break;
		}else{
			p->senha[w] = verifica;
			printf("*");
		}
		   			    
	}		
	p->Status = ' ';
    fflush(stdin);
    
}

int main(){
	
	int op,i,j,num = 0;
	char login[TAM_LOGIN] = {},senha[TAM_SENHA] = {},senha2[TAM_SENHA] = {},verifica,verifica2,ch;	
	
	FILE *usuario;
	usuario = fopen("banco\\usuario.txt","r+b");
	
	printf("|-----------------------------------------------------------|\n");
	printf("|----------------- BEM VINDO AO SPOTIFY --------------------|\n");
	printf("|-----------------------------------------------------------|\n");
	
	printf("\n\n 1 - Login \n 2 - Cadastro\n");	
	printf("\nDigite a sua opcao:");
	
	op = getche();

	system("cls");	
		
	switch(op){
		
		case '1':
			
			printf("|-----------------------------------------------------------|\n");
			printf("|-------------------- LOGIN  SPOTIFY -----------------------|\n");
			printf("|-----------------------------------------------------------|\n");
			
			printf("\n\tlogin : ");
			gets(login);	
			printf("\tsenha : ");
			
			for ( i = 0 ; i < TAM_SENHA ; i++ ) {
			    	
				verifica = getch();
		        
				if (verifica == 13){
					break;
				}else{
					senha[i] = verifica;
					printf("*");
				}
			   			    
			}		

			fflush(stdin);
			

		    Pessoa reg;
		    rewind(usuario);
		   	int contador = 0;
		    while(fread(&reg, sizeof(Pessoa), 1, usuario)){
		    	contador++;
		        if(reg.Status!='*' && strstr(reg.login, login) && strstr(reg.senha, senha)){
					tela_index_user(contador);
		        	return 1;
				}
			}
			
			
			printf("Conta inexistente :( ");

			break;
			
		case '2':
			
			printf("|-----------------------------------------------------------|\n");
			printf("|------------- CADASTRO USUARIO SPOTIFY --------------------|\n");
			printf("|-----------------------------------------------------------|\n");
	
			Pessoa x;
			
			cadastrar_Pessoa(&x);

			fseek(usuario, 0L, SEEK_END);
		    
			if(fwrite(&x, sizeof(x), 1, usuario)!=1){
		    	printf("Adicionar pessoa: Falhou a escrita do registro");
		    	return 1;
			}

			//LOGANDO USUARIO CADASTRADO
		    Pessoa regx;
		    rewind(usuario);
		   	int contadorx = 0;
		    while(fread(&regx, sizeof(Pessoa), 1, usuario)){
		    	contadorx++;
		        if(regx.Status!='*' && strstr(regx.login, x.login) && strstr(regx.senha, x.senha)){
					tela_index_user(contadorx);
		        	return 1;
				}
			}
			
			break;
		
	}	

	fclose(usuario);			

}

