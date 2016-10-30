#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "typedefs.c"

void telaLoginADM();
void listar_usuarios_adm();
void menu_adm();

int main(){
    telaLoginADM();
//    listar_usuarios_adm();
    return 0;
}

void telaLoginADM(){
    int i;
    char pwAdm[TAM_SENHA] = "m@st3r2016";
    char conf_pwAdm[TAM_SENHA];

    printf("Bem vindo, adm.\n");
    
    char *pos;
    do{
        printf("Digite sua senha para entrar: ");
        fgets(conf_pwAdm, TAM_SENHA, stdin);
        
        //remove newline 
        if ((pos=strchr(conf_pwAdm, '\n')) != NULL)
        *pos = '\0';
        
        //mascarar a senha * faltando *
        
        
    }while(strcmp(conf_pwAdm, pwAdm) != 0);
    printf("Logado com sucesso\n");


}

void listar_usuarios_adm(){
    int i, status;
    TUsuario listaUsu[100];
    FILE *usu;
    usu = fopen("banco/usuario.txt", "rt");
    if(usu == NULL){
        printf("Erro na abertura do arquivo\n");
    }else{
        printf("Arquivo aberto com sucesso\n");
    }
    
    while(!feof(usu)){
        fread(&listaUsu[i], sizeof(TUsuario), 1, usu);
    }
    
    printf("Lista de logins cadastrados no sistema: \n");
    for(i = 0; i < sizeof(listaUsu); i++){
        printf("%s\n", listaUsu[i].login);
    }
    /*
    i = 0;
    while(!feof(usu)){
        fgets(&listaUsu[i], sizeof(TUsuario), usu);
        printf("%s\n", listaUsu[i].login);
        i++;
    }
     
    */    
    
    
    status = fclose(usu);
    if (status == 0){
        printf("Arquivo fechado com sucesso\n");
    }else {
        printf("Erro ao fechar o arquivo\n");
    }
    
}

void menu_adm(){
    int op;
    printf("\n------MENU------\n");
    printf("1- Lista Usuarios");
    switch(op){
        case 1:
            listar_usuarios_adm();
    }
}

