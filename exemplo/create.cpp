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
	    
    Pessoa x;
    
	Ler_Pessoa(&x);
    
	fseek(fp, 0L, SEEK_END);
    if(fwrite(&x, sizeof(x), 1, fp)!=1)
        printf("Adicionar pessoa: Falhou a escrita do registro");

    
    return 0;
}
