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
    char senha[TAM_SENHA+1];
    char Status; /* '*' indica que o registro está apagado*/
}Pessoa2;

void alterar_senha(Pessoa2 *p){
	
    int w;
    char verifica;	
    
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

void alterar_login(Pessoa2 *p){
    gets(p->login);
    p->Status = ' ';
    fflush(stdin);
}

FILE *usuario;

void usuario_repositorio2(){
	usuario = fopen("banco\\usuario.txt","r+b");	
}



void tela_perfil_nome(char type_user, int id_usuario){
     
 			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|------------- ALTERAR NOME PERFIL SPOTIFY ------------------|\n");
			printf("|------------------------------------------------------------|\n");

			printf("%i",id_usuario);		
		
			printf("\n\n\t Digite qualquer tecla para voltar: ");		
			getche();
        	tela_index_user(id_usuario);
        	

}

void tela_perfil_login(char type_user, int id_usuario){
     
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
		    		    
		    printf("\t Digite seu novo login:");
		    
			alterar_login(&x);
		   
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
		    		    
		    printf("\t Digite sua nova senha:");
		    
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

