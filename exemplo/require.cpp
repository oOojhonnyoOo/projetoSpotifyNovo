#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

typedef struct{
    char nome[30+1];
    int idade;
    float salario;
    char Status; 
}Pessoa;



int main(int argc, char *argv[]) {
   
	FILE *fp;
	
    fp= fopen("Dados.txt", "r+b"); //tentar abrir
    if(fp==NULL){
        fp = fopen("Dados.txt", "w+b"); // criar o arquivo
        if(fp==NULL){
            fprintf(stderr," Erro fatal: impossível criar arquivo de dados\n");
            exit(1);
        }
    }

    long int n_Linhas = 0;
    Pessoa reg;
    rewind(fp);
    
    while(1){
    	
	    if(fread(&reg, sizeof(reg), 1, fp)!= 1)break; /*Sair do laço*/
        if(reg.Status=='*') continue; /*Passa ao próximo*/
        
        printf("%-30s %3d %10.2f \n",reg.nome, reg.idade, reg.salario);
        
		n_Linhas++;
        if(n_Linhas%20==0)
            printf("Pressione <Enter> para continuar .  .  .");
            
    }
    printf("\n\n Pressione <Enter> para continuar .  .  . %i ",n_Linhas); /*No fim da listagem*/

    
	return 0;
}
