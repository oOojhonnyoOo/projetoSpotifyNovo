#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>


typedef struct{
    char nome[30+1];
    int idade;
    float salario;
    char Status; /* '*' indica que o registro está apagado*/
}Pessoa;


/* lê os dados de um registro introduzido pelo usuário*/
void Ler_Pessoa(Pessoa *p){
    printf("Nome:    "); gets(p->nome);
    printf("Idade:   "); scanf("%d",&p->idade);
    printf("salario: "); scanf("%f",&p->salario);
    p->Status = ' ';
    fflush(stdin);
}

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
	    
    char s[255+1];
    printf("Qual o nome a procurar: ");
    gets(s);
	fflush(stdin);
	
    Pessoa reg;
    rewind(fp);
   
    while(fread(&reg, sizeof(Pessoa), 1, fp))
        if(reg.Status!='*' && strstr(reg.nome, s))
            printf("%-30s %3d %10.2f \n",reg.nome, reg.idade, reg.salario);
           
    printf("\n\n Pressione <Enter> para continuar .  .  ."); /*No fim da listagem*/	  
    
                
    return 0;
}
