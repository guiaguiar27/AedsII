#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>


typedef struct { 
    int matricula ;  
    char nome[15] ; 
    float media_nota; 
    float notas[3];  

}tipo_registro ;  
typedef  struct  tipo_no *tipo_apontador ; 
typedef struct tipo_no { 
    tipo_registro registro ; 
    tipo_apontador direita , esquerda ;  
}tipo_no ;    
// funcoes   
void preenche_registro(); 
void inicializa_dc(tipo_apontador *p); 
void insere(tipo_apontador *p , tipo_registro new_registro); 
void le_arquivo(tipo_apontador *p );   
void fragmenta(char *l); 
//void ordena();  

