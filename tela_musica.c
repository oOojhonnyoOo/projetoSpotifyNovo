#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

typedef struct{
    char titulo[20+1];
    char autor[20+1];
    char Status; /* '*' indica que o registro está apagado*/
}musica;

void cadastrar_musica(musica *m){
    printf("\n\n\t titulo da musica:    "); gets(m->titulo);
    printf("\t autor:    "); gets(m->autor);
    m->Status = ' ';
    fflush(stdin);
}

FILE *arq_musica;

void arquivo_repositorio(){
	arq_musica = fopen("banco\\musica.txt","r+b");	
}

void tela_musica_cadastrar(char type_user, int id_usuario){
   
     
 			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|-------------- CADASTRAR MUSICA SPOTIFY --------------------|\n");
			printf("|------------------------------------------------------------|\n");
	
			arquivo_repositorio();

			musica m;
			
			cadastrar_musica(&m);
			
			fseek(arq_musica, 0L, SEEK_END);
		    if(fwrite(&m, sizeof(m), 1, arq_musica)!=1){
		    	printf("Adicionar musica: Falhou a escrita do registro");
		    	system("pause");
			}
		
			printf("\n\n\t MUSICA CADASTRADA COM SUCESSO... :) \n\n \t DIGITE QUALQUER TECLA PARA VOLTAR: ");		
			getche();
			
			tela_index_adm();	
        	   	
}

void tela_musica_listar(char type_user, int id_usuario){
     
 			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|--------------- LISTAR MUSICA SPOTIFY ----------------------|\n");
			printf("|------------------------------------------------------------|\n");

			arquivo_repositorio();
			
		    long int n_Linhas = 0;
		    musica mus;
		    rewind(arq_musica);
		    
			printf("\n\t TITULO \t\t\tAUTOR \n");
			printf("\t --------------------------------------------------\n");
		    
			while(1){
		    	
			    if(fread(&mus, sizeof(mus), 1, arq_musica)!= 1)break; /*Sair do laço*/
		        if(mus.Status=='*') continue; /*Passa ao próximo*/
		        
		        printf("\t %-30s %3s \n",mus.titulo, mus.autor);
		        
				n_Linhas++;
		        if(n_Linhas%20==0)
		            printf("Pressione <Enter> para continuar .  .  .");
		            
		    }
			
		
			printf("\n\n\t Digite qualquer tecla para voltar: ");		
			getche();	

			if(type_user == 'a'){
				tela_index_adm();
			}else{
				tela_index_user(id_usuario);	
			}
			

}

void tela_musica_consultar(char type_user,int id_usuario){
     
 			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|-------------- CONSULTAR MUSICA SPOTIFY --------------------|\n");
			printf("|------------------------------------------------------------|\n");
		
		    arquivo_repositorio();

		    char s[255+1];
		    printf("\n\t Qual o nome a procurar: ");
		    gets(s);
			fflush(stdin);
			
		    musica reg;
		    rewind(arq_musica);
		   
		    while(fread(&reg, sizeof(musica), 1, arq_musica))
		        if(reg.Status!='*' && strstr(reg.titulo, s))
		            printf("\n\n\t %-30s %3s \n",reg.titulo, reg.autor);
			
			printf("\n\n\t Digite qualquer tecla para voltar: ");		
			getche();
			if(type_user == 'a'){
				tela_index_adm();
			}else{
				tela_index_user(id_usuario);	
			}
        	

}



void tela_musica_alterar(char type_user, int id_usuario){
     
 			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|---------------- ALTERAR MUSICA SPOTIFY --------------------|\n");
			printf("|------------------------------------------------------------|\n");
		
			arquivo_repositorio();
		
			// LISTAR TODAS MUSICAS
		    long int n_Linhas = 0;
		    musica mus;
		    rewind(arq_musica);
		    
			printf("\n\t ID \t TITULO \t\t\tAUTOR \n");
			printf("\t --------------------------------------------------\n");
		    
			while(1){
		    	
			    if(fread(&mus, sizeof(mus), 1, arq_musica)!= 1)break; /*Sair do laço*/
		    
			    n_Linhas++;
			
				if(mus.Status=='*')continue; /*Passa ao próximo*/
		        
		        printf("\t %i \t %-30s %3s \n",n_Linhas,mus.titulo, mus.autor);
		        			
		        if(n_Linhas%20==0)
		            printf("Pressione <Enter> para continuar .  .  .");
		            
		    }			
			
			// UPDATE DA MUSICA
			
			musica x;
		    long int n_reg;
		
			int retorno;
		
		    printf("\n\tQual o numero do registro: ");
		    scanf("%ld", & n_reg); fflush(stdin);
				    
			if(fseek(arq_musica, (n_reg-1)*sizeof(musica), SEEK_SET)!=0){
		        printf("Registro inexistente ou problemas no posicionamento!!!");
		        system("pause");
		    }
		    
		    if(fread(&x, sizeof(musica), 1, arq_musica)!= 1){
		        printf("Problemas na leitura do registro!!!");
		        return 1;
		    }
		   
		    if(x.Status == '*'){
		        printf("Um registro apagado não pode ser alterado!!! \n\n");
		        return 1;
		    }
		   
		    printf("\n\n Dados Atuais \n\n");
		    
		    //mostrar pessoa
		    printf("%-30s %3s \n",x.titulo, x.autor);
		    
		    printf("\n\n Novos dados \n\n");
		    cadastrar_musica(&x);
		   
		    // recuar um registro no arquivo
		    fseek(arq_musica, -(long) sizeof(musica), SEEK_CUR);
		    // reescrever o registro;
		    fwrite(&x, sizeof(musica), 1, arq_musica);
		    fflush(arq_musica); /*despejar os arquivos no disco rígido*/
			
		
			printf("\n\n\t Digite qualquer tecla para voltar: ");		
			getche();
        	tela_index_adm();
        	

}

void tela_musica_excluir(char type_user, int id_usuario){
     
 			system("cls");
			printf("|------------------------------------------------------------|\n");
			printf("|---------------- EXCLUIR MUSICA SPOTIFY --------------------|\n");
			printf("|------------------------------------------------------------|\n");
		
		
			arquivo_repositorio();
		
			// LISTAR TODAS MUSICAS
		    long int n_Linhas = 0;
		    musica mus;
		    rewind(arq_musica);
		    
			printf("\n\t ID \t TITULO \t\t\tAUTOR \n");
			printf("\t --------------------------------------------------\n");
		    
			while(1){
		    	
			    if(fread(&mus, sizeof(mus), 1, arq_musica)!= 1)break; /*Sair do laço*/
		    
			    n_Linhas++;
			
				if(mus.Status=='*')continue; /*Passa ao próximo*/
		        
		        printf("\t %i \t %-30s %3s \n",n_Linhas,mus.titulo, mus.autor);
		        			
		        if(n_Linhas%20==0)
		            printf("Pressione <Enter> para continuar .  .  .");
		            
		    }			
		
		
			// EXCLUIR 			
		    musica x;
		    long int n_reg;
		    char resp;
		   
		    printf("\n\n\tQual o numero do registro: ");
		    scanf("%ld", & n_reg); fflush(stdin);
		    
		    if(fseek(arq_musica, (n_reg - 1)*sizeof(musica), SEEK_SET)!= 0){
		        printf("Registro inexistente ou problemas no registro!!!");
		        return 1;
		    }
		    
		    if(fread(&x, sizeof(musica), 1, arq_musica)!= 1){
		        printf("Problema na leitura do registro!!!");
		        return 1;
		    }
		    
		    if(x.Status=='*'){
		        printf("Registro já está apagado!!!\n\n");
		        return 1;
		    }
		    
		    printf("\n\n Dados atuais \n\n");
		    
			printf("%-30s %3s \n",x.titulo, x.autor);
		    
			printf("\n\n Apagar o registro (s/n)???: "); resp = getchar();
		    
			fflush(stdin);
		    
			if(toupper(resp)!= 'S') return 1;
		   
		    x.Status= '*';
		    // recuar um registro no arquivo
		    fseek(arq_musica, -(long) sizeof(musica), SEEK_CUR);
		    // reescrever o registro;
		    fwrite(&x, sizeof(musica), 1, arq_musica);
		    fflush(arq_musica); /*Despejar os arquivos no disco rígido*/
		      
					
		
			printf("\n\n\t Musica excluida com sucesso... :)\n\t digite qualquer tecla para voltar ao menu. ");		
			getche();	


			tela_index_adm();
      	

}


void listar_musicas(){
	
		arquivo_repositorio();
			
		long int n_Linhas = 0;
		musica mus;
		rewind(arq_musica);
		    
		printf("\n \t ID \t TITULO \t\t\tAUTOR \n");
		printf("\t --------------------------------------------------\n");
		    
		while(1){
		    	
			if(fread(&mus, sizeof(mus), 1, arq_musica)!= 1)break; /*Sair do laço*/
		    if(mus.Status=='*') continue; /*Passa ao próximo*/

			n_Linhas++;
		        
		    printf("\t %i \t %-30s %3s \n",n_Linhas,mus.titulo, mus.autor);    

		    if(n_Linhas%20==0)
		        printf("Pressione <Enter> para continuar .  .  .");
		            
		}
		
}


void get_nome_autor_musica(int id_musica){
	
		arquivo_repositorio();

		long int n_Linhas = 0;
		musica mus;
		rewind(arq_musica);
		    	    
		while(1){
		    	
			if(fread(&mus, sizeof(mus), 1, arq_musica)!= 1)break; /*Sair do laço*/
			if(mus.Status=='*') continue; /*Passa ao próximo*/
		    
			n_Linhas++; 
			    
		    if(id_musica == n_Linhas){
		    	printf("\t %-20s  %23s \n",mus.titulo,mus.autor);
			}

		    if(n_Linhas%20==0)
		        printf("Pressione <Enter> para continuar .  .  .");
		            
		}
	   
	    fflush(arq_musica);      
		
}

