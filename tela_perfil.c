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
}Pessoa2;

int confere_senha(Pessoa2 *p);

void alterar_senha(Pessoa2 *p){
	char novaSenha[TAM_SENHA];
    char verifica;	
    int w;
    
    
    do{
    	memset(novaSenha,0,strlen(novaSenha));
    	printf("\n\t Digite sua NOVA SENHA: ");
    	for ( w = 0 ; w < TAM_SENHA ; w++ ) {
			   	
			verifica = getch();
			       
			if (verifica == 13){
				break;
			}else{
				novaSenha[w] = verifica;
				printf("*");
			}
		  	
		}
		printf("\n\nVocê digitou: %s\n\n", novaSenha);
		printf("\n\t Confirme sua NOVA SENHA: ");
		for ( w = 0 ; w < TAM_SENHA ; w++ ) {
			   	
			verifica = getch();
			       
			if (verifica == 13){
				break;
			}else{
				p->senha[w] = verifica;
				printf("*");
			}
			   			    
		}
		printf("\n\nVocê digitou: %s\n\n", p->senha);
		
		if(strcmp(novaSenha, p->senha) != 0){
			printf("\n\nSem sucesso na confirmacao da senha, tente novamente\n\n");
		}
    	
	}while(strcmp(novaSenha,p->senha) != 0);
		
    
    p->Status = ' ';
    fflush(stdin);
}

void alterar_login(Pessoa2 *p, char novoLogin[TAM_LOGIN]){
	strcpy(p->login, novoLogin);
    p->Status = ' ';
    fflush(stdin);
}


void alterar_nome(Pessoa2 *p, char novoNome[TAM_NOME]){
    strcpy(p->nome, novoNome);
    p->Status = ' ';
    fflush(stdin);
}


FILE *usuario;

void usuario_repositorio2(){
	usuario = fopen("banco\\usuario.txt","r+b");	
}



void tela_perfil_nome(char type_user, int id_usuario){
     		char novoNome[TAM_NOME] = {};
 			char conferirSenha[TAM_SENHA+1];
			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|------------- ALTERAR NOME PERFIL SPOTIFY ------------------|\n");
			printf("|------------------------------------------------------------|\n");

			printf("%i",id_usuario);		
		
			usuario_repositorio2();
			
			Pessoa2 x;		
		    
			if(fseek(usuario, (id_usuario-1)*sizeof(Pessoa2), SEEK_SET)!=0){
		        printf("Registro inexistente ou problemas no posicionamento!!!");
		        system("PAUSE");
		    }
		    
		    if(fread(&x, sizeof(Pessoa2), 1, usuario)!= 1){
		        printf("Problemas na leitura do registro!!!");
		        system("PAUSE");
		    }
		   
		    if(x.Status == '*'){
		        printf("Um registro apagado não pode ser alterado!!! \n\n");
		        system("PAUSE");
		    }
		   
		    printf("\n\n\t Seu nome atual : %-30s \n",x.nome);
		    		    
		    printf("\t Digite seu novo nome: ");
		    gets(novoNome);
		   
		    /* solicita senha para confirmar alteração de nome*/
		   	
			if(confere_senha(&x) == 0){
				alterar_nome(&x, novoNome);
				printf("\n\t Nome alterado com sucesso");
			}
			
	
		   
		    // recuar um registro no arquivo
		    fseek(usuario, -(long) sizeof(Pessoa2), SEEK_CUR);
		    // reescrever o registro;
		    fwrite(&x, sizeof(Pessoa2), 1, usuario);
		    fflush(usuario); /*despejar os arquivos no disco rígido*/
		
			printf("\n\n\t Digite qualquer tecla para voltar: ");		
			getche();
        	tela_index_user(id_usuario);           	

}

void tela_perfil_login(char type_user, int id_usuario){
			char novoLogin[TAM_LOGIN] = {};
			
 			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|--------------- ALTERAR LOGIN SPOTIFY ----------------------|\n");
			printf("|------------------------------------------------------------|\n");

			usuario_repositorio2();
			
			Pessoa2 x;		
		    
			if(fseek(usuario, (id_usuario-1)*sizeof(Pessoa2), SEEK_SET)!=0){
		        printf("Registro inexistente ou problemas no posicionamento!!!");
		        system("PAUSE");
		    }
		    
		    if(fread(&x, sizeof(Pessoa2), 1, usuario)!= 1){
		        printf("Problemas na leitura do registro!!!");
		        system("PAUSE");
		    }
		   
		    if(x.Status == '*'){
		        printf("Um registro apagado não pode ser alterado!!! \n\n");
		        system("PAUSE");
		    }
		   
		    printf("\n\n\t Seu login atual : %-30s \n",x.login);
		    		    
		    printf("\t Digite seu novo login: ");
		    gets(novoLogin);
		    /* solicita a senha para confirmar a mudança de login*/
		   	if(confere_senha(&x) == 0){
				alterar_login(&x, novoLogin);
				printf("\n\t Login alterado com sucesso");
			}
			
		   
		    // recuar um registro no arquivo
		    fseek(usuario, -(long) sizeof(Pessoa2), SEEK_CUR);
		    // reescrever o registro;
		    fwrite(&x, sizeof(Pessoa2), 1, usuario);
		    fflush(usuario); /*despejar os arquivos no disco rígido*/
		
			printf("\n\n\t Digite qualquer tecla para voltar: ");		
			getche();
        	tela_index_user(id_usuario);        	

}

void tela_perfil_senha(char type_user, int id_usuario){
     
     		char senhaAntiga[TAM_SENHA];
 			
			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|--------------- ALTERAR SENHA SPOTIFY ----------------------|\n");
			printf("|------------------------------------------------------------|\n");
			
			usuario_repositorio2();
			
			Pessoa2 x;		
		    
			if(fseek(usuario, (id_usuario-1)*sizeof(Pessoa2), SEEK_SET)!=0){
		        printf("Registro inexistente ou problemas no posicionamento!!!");
		        system("PAUSE");
		    }
		    
		    if(fread(&x, sizeof(Pessoa2), 1, usuario)!= 1){
		        printf("Problemas na leitura do registro!!!");
		        system("PAUSE");
		    }
		   
		    if(x.Status == '*'){
		        printf("Um registro apagado não pode ser alterado!!! \n\n");
		        system("PAUSE");
		    }
		   
		    printf("\n\n\t Seu login: %-30s \n",x.login);

			printf("\n\t Digite sua SENHA ANTIGA: ");
			gets(senhaAntiga);
			while(strcmp (senhaAntiga,x.senha) != 0){
				printf("\n\tSenha nao confere, digite novamente: ");
				gets(senhaAntiga);
			}
		    
			alterar_senha(&x);
		   
		    // recuar um registro no arquivo
		    fseek(usuario, -(long) sizeof(Pessoa2), SEEK_CUR);
		    // reescrever o registro;
		    fwrite(&x, sizeof(Pessoa2), 1, usuario);
		    fflush(usuario); /*despejar os arquivos no disco rígido*/
		
			printf("\n\n\t Sua senha foi alterada com sucesso!! :) \n\t Digite qualquer coisa no teclado para voltar ao menu.: ");		
			getche();
        	tela_index_user(id_usuario);        	

}


void tela_perfil_ver_dados(char type_user, int id_usuario){
     
 			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|------------- VER DADOS DO USUARIO SPOTIFY -----------------|\n");
			printf("|------------------------------------------------------------|\n");

			usuario_repositorio2();

			printf("\n\n\t DADOS DO USUARIO \n\n");
			printf("\tID:    %i\n",id_usuario);			
			printf("\tNOME:  \n");
			printf("\tLOGIN: \n");
			printf("\tSENHA: \n");
		
			printf("\n\n\t Digite qualquer tecla para voltar: ");		
			getche();
        	tela_index_user(id_usuario);        	

}

int confere_senha(Pessoa2 *p){
	int i;
	char senha[TAM_SENHA], verifica;
	
	do{
		memset(senha,0,strlen(senha));
        printf("\n\t Digite sua senha para confirmar: ");
		for ( i = 0 ; i < TAM_SENHA ; i++ ) {
				   	
			verifica = getch();
			       
			if (verifica == 13){
				break;
			}else{
				senha[i] = verifica;
				printf("*");
			}
			   
		}
		        
        if(senha != p->senha) printf("\n\t Voce digitou uma senha errada!");
    }while(strcmp(senha, p->senha) != 0);
    printf("\n\t Senha correta!");
    return 0;
}
