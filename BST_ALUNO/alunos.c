#include "alunos.h"  

void inicializa_dc(tipo_apontador *p){ 
    *p = NULL;  
} 
void insere(tipo_apontador *p , tipo_registro new_registro){ 
    if(*p == NULL){     
        *p = (tipo_apontador)malloc(sizeof(tipo_no)); 
        (*p)->registro = new_registro;  
        (*p)->direita = NULL; 
        (*p)->esquerda = NULL; 
    } 
    else if((*p)->registro.media_notas >  new_registro.notas_acumulados) insere(new_registro,&(*p)->esquerda);
    else if((*p)->registro.media_notas <  new_registro.notas_acumulados) insere(new_registro,&(*p)->esquerda);
} 

void le_arquivo(tipo_apontador *p){ 
    FILE *arq ;  
    tipo_registro generico ;  
    int count = 0 ;   
    float notas_acumuladas; 
    int num = 3 ;   
    arq = fopen("alunos.txt","r");  
    if(arq == NULL){
        printf("Arquivo nao foi aberto com sucesso\n");
        return ; 
    } 
    else printf("Arquivo aberto\n ");    
    // ler_linha por linha   do arquivo 
     
    while(!feof(arq)){    
        if(fscanf(arq,"%s - %d - %f - %f - %f",generico.nome,&generico.matricula,&generico.notas[1],&generico.notas[2],&generico.notas[3]) == NULL) break ;
        
        fscanf(arq,"%s - %d - %f - %f - %f",generico.nome,&generico.matricula,&generico.notas[1],&generico.notas[2],&generico.notas[3]);  
        for(int i = 0 ; i < num; i++) notas_acumuladas = notas_acumuladas + generico.notas[i]/3;  

    }      

    return ; 
} 
