#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "tela_main.c"

#define TAM_NOME 50
#define TAM_LOGIN 15
#define TAM_SENHA 15
#define TAM_PLYLST 200
#define QTD_MUSICAS 100

int main(){
   	int i;
    char pwAdm[TAM_SENHA] = "m@st3r2016";
    char conf_pwAdm[TAM_SENHA], aux_pwAdm;

    printf("Bem vindo, adm.");
    
    char *pos;
    do{
        
		printf("\nDigite sua senha para entrar: ");
        //fgets(conf_pwAdm, TAM_SENHA, stdin);
        i = 0;
    	while( (aux_pwAdm=getch()) != 13){
    		conf_pwAdm[i] = aux_pwAdm;
        	printf("*");
        	i++;
    	}		
    	conf_pwAdm[i] = '\0';
    	
		fflush(stdin);
		printf("%s\n", conf_pwAdm);
        
        if ((pos=strchr(conf_pwAdm, '\n')) != NULL)
        *pos = '\0'; 

        
    }while(strcmp(conf_pwAdm, pwAdm) != 0);

	tela_index_adm();
	
    return 0;
}


