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
    long int n_reg;

	int retorno;

    printf("Qual o numero do registro: ");
    scanf("%ld", & n_reg); fflush(stdin);

    
	if(fseek(fp, (n_reg-1)*sizeof(Pessoa), SEEK_SET)!=0){
        printf("Registro inexistente ou problemas no posicionamento!!!");
        return 1;
    }
    
    if(fread(&x, sizeof(Pessoa), 1, fp)!= 1){
        printf("Problemas na leitura do registro!!!");
        return 1;
    }
   
    if(x.Status == '*'){
        printf("Um registro apagado não pode ser alterado!!! \n\n");
        return 1;
    }
   
    printf("\n\n Dados Atuais \n\n");
    
    //mostrar pessoa
    printf("%-30s %3d %10.2f \n",x.nome, x.idade, x.salario);
    
    printf("\n\n Novos dados \n\n");
    Ler_Pessoa(&x);
   
    // recuar um registro no arquivo
    fseek(fp, -(long) sizeof(Pessoa), SEEK_CUR);
    // reescrever o registro;
    fwrite(&x, sizeof(Pessoa), 1, fp);
    fflush(fp); /*despejar os arquivos no disco rígido*/
   
    return 0;
}
