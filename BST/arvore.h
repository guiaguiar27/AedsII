#include <stdio.h>  
#include <stdlib.h>  
#include <limits.h> 
#include <sys/time.h>
// chave sao um dos parametros do registro no caso uma identificacao 
 
// registro contem os dados a serem armazenados em cada no  
typedef struct tipo_registro { 
    int chave; 

}tipo_registro;  
//  
/*
typedef struct {  
    tipo_registro *registro_arq ;  
    int quantidade_arquivo ;  

}tipo_arquivo;  
*/ 
typedef struct tipo_no *tipo_apontador;   

typedef struct tipo_no { 
    tipo_registro registro; 
    tipo_apontador esquerda, direita ; 

}tipo_no ;  
typedef tipo_apontador bst;     
void inicializa_bst(bst *novo_dicionario);  
void insere_no(tipo_registro  novo_no, tipo_apontador *no);  
void pesquisa_no(tipo_registro *registro_buscado ,tipo_apontador *p); 
void imprime_dados_ordem(tipo_apontador p);    
void imprime_dados_pre_ordem(tipo_apontador p); 
void imprime_dados_pos_ordem(tipo_apontador p); 
int altura(tipo_apontador p);    
// ser implementado dps  
//void arquivo(tipo_arquivo  *arq );  
void antecessor(tipo_apontador q , tipo_apontador *r);  
void retira(tipo_registro x , tipo_apontador *p); 
  
