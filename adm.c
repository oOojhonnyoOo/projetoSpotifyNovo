#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tela_main.c"

#define TAM_NOME 50
#define TAM_LOGIN 15
#define TAM_SENHA 15
#define TAM_PLYLST 200
#define QTD_MUSICAS 100

int main(){
   
    int i;
    char pwAdm[TAM_SENHA] = "m@st3r2016";
    char conf_pwAdm[TAM_SENHA] = {};
    int x;
    char verifica;
    
    printf("Bem vindo, adm.\n");
    
    char *pos;
    do{
        
		printf("\nDigite sua senha para entrar: ");
        
		for ( x = 0 ; x < TAM_SENHA ; x++ ) {
				   	
			verifica = getch();
			       
			if (verifica == 13){
				break;
			}else{
				conf_pwAdm[x] = verifica;
				printf("*");
			}
			   			    
		}        
        
    }while(strcmp(conf_pwAdm, pwAdm) != 0);

	tela_index_adm();
	
    return 0;
}


