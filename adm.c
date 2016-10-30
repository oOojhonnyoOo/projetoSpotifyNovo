#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tela_menu_adm.c"

#define TAM_NOME 50
#define TAM_LOGIN 15
#define TAM_SENHA 15
#define TAM_PLYLST 200
#define QTD_MUSICAS 100

int main(){
   
    int i;
    char pwAdm[TAM_SENHA] = "m@st3r2016";
    char conf_pwAdm[TAM_SENHA];

    printf("Bem vindo, adm.\n");
    
    char *pos;
    do{
        
		printf("Digite sua senha para entrar: ");
        fgets(conf_pwAdm, TAM_SENHA, stdin);
        
        if ((pos=strchr(conf_pwAdm, '\n')) != NULL)
        *pos = '\0'; 
        
    }while(strcmp(conf_pwAdm, pwAdm) != 0);

	tela_index_adm();
	
    return 0;
}


