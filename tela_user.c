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
    char nome[TAM_NOME+1];
    char senha[TAM_SENHA+1];
    char Status; /* '*' indica que o registro está apagado*/
}TipoPessoa;

FILE *usuario;

void usuario_repositorio(){
	usuario = fopen("banco\\usuario.txt","r+b");	
}


void tela_user_listar(char type_user, int id_usuario){
     
            int opcao;

			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|--------------- LISTAR USUARIO SPOTIFY ---------------------|\n");
			printf("|------------------------------------------------------------|\n");

			usuario_repositorio();
			
		    long int n_Linhas = 0;
		    TipoPessoa reg;
		    rewind(usuario);
	
			
			/* Verifica se e usuario ou adm e exibe os campos de acordo */
			if(type_user == 'a'){ 
			
			printf("\n\t ID \t LOGIN \t\t\t\tNOME \n");
			printf("\t --------------------------------------------------\n");
				while(1){
		    	
			    if(fread(&reg, sizeof(reg), 1, usuario)!= 1)break; /*Sair do laço*/
		        
		        n_Linhas++;
		        
				if(reg.Status=='*') continue; /*Passa ao próximo*/

		        printf("\t %i \t %-30s %3s \n",n_Linhas,reg.login,reg.nome) ;
		        	
		        if(n_Linhas%20==0)
		            printf("Pressione <Enter> para continuar .  .  .");
		            
		    	}
			}else {
				printf("\n\t ID \t NOME \n");
				printf("\t --------------------------------------------------\n");
				
				while(1){
		    	
			    if(fread(&reg, sizeof(reg), 1, usuario)!= 1)break; /*Sair do laço*/
		        
		        n_Linhas++;
		        
				if(reg.Status=='*') continue; /*Passa ao próximo*/

		        printf("\t %i \t %3s \n",n_Linhas,reg.nome) ; 
		        	
		        if(n_Linhas%20==0)
		            printf("Pressione <Enter> para continuar .  .  .");
		            
		    	}
			}	    
		   
						
			printf("\n\n\t Digite qualquer tecla para voltar: ");		
			getche();	

			if(type_user == 'a'){
				tela_index_adm();
			}else{
				tela_index_user();	
			}

     
}

void tela_user_consultar(char type_user,int id_usuario){
     
 			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|------------- CONSULTAR USUARIO SPOTIFY --------------------|\n");
			printf("|------------------------------------------------------------|\n");


		    char s[255+1];
		    printf("\n\t Qual o nome a procurar: ");
		    gets(s);
			fflush(stdin);
			
		    TipoPessoa reg;
		    rewind(usuario);
		   
		    while(fread(&reg, sizeof(TipoPessoa), 1, usuario))
		        if(reg.Status!='*' && strstr(reg.login, s))
		            printf("\n\n\t %-30s %3s \n",reg.login, reg.senha);
		
			printf("\n\n\t Digite qualquer tecla para voltar: ");		
			getche();
			if(type_user == 'a'){
				tela_index_adm();
			}else{
				tela_index_user(id_usuario);	
			}

}

char*get_nome_usuario(int id_usuario)
{
	
	usuario_repositorio();
			
	TipoPessoa x;		
	
	if(fseek(usuario, (id_usuario-1)*sizeof(TipoPessoa), SEEK_SET)!=0){
		printf("Registro inexistente ou problemas no posicionamento!!!");
		system("PAUSE");
	}
		    
	if(fread(&x, sizeof(TipoPessoa), 1, usuario)!= 1){
		printf("Problemas na leitura do registro!!!");
		system("PAUSE");
	}
		   
	if(x.Status == '*'){
		printf("Um registro apagado não pode ser alterado!!! \n\n");
		system("PAUSE");
	}
		   
    char retorno[200];
    
    strcpy(retorno, x.nome);
   
   	//printf(" %s ",Retorno);
   		    		   
	fflush(usuario); /*despejar os arquivos no disco rígido*/

	return retorno;

}
