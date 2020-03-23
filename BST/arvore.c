#include "arvore.h"   
void inicializa_bst(tipo_dicionario *novo_dicionario){ 
    // por que ponteiro aqui ? 
    *novo_dicionario  = NULL ;     
    printf("Dicionario criado\n");

} 
// modulo de insercao  
void insere_no(tipo_registro  novo_no, tipo_apontador *no){ 
    // caso o registro sejá a raiz  
    // ou seja , o primeiro registro a ser inserido na arvore 
    if( *no == NULL){   
        *no = (tipo_apontador)malloc(sizeof(tipo_no));  

        (*no)->registro = novo_no ;  
        // como é uma nova folha os ponteiros direita e esquerda não apontam para nada 
        (*no)->direita = NULL ; 
        (*no)->esquerda = NULL ; 
        printf("Inserido \n"); 
        return ;     
    }  

    if(novo_no.chave > (*no)->registro.chave ) {  
        insere_no(novo_no , &(*no)->direita); 
        printf("Inserido \n");  
        return ;  
    } 
    else if(novo_no.chave <  (*no)->registro.chave){ 
        insere_no(novo_no, &(*no)->esquerda); 
        printf("Inserido \n");   
        return ;  
    }
}   
// modulo para pesquisar um registro a partir da chave desse registro na bst  
void pesquisa_no(tipo_registro *registro_buscado  , tipo_apontador *p ){ 
    if(*p == NULL){  
        printf("Arvore vazia\n");
        return ;  
    if((*registro_buscado).chave < (*p)->registro.chave ){        
            printf(" Pesquisa a esquerda\n"); 
            printf("Registro ainda não encontrado\n....\n"); 
            pesquisa_no(registro_buscado,&(*p)->esquerda); 
            return ; } 
    if((*registro_buscado).chave > (*p)->registro.chave ){          
            printf(" Pesquisa a esquerda\n");   
            printf("Registro ainda não encontrado\n....\n");  
            pesquisa_no(registro_buscado,&(*p)->direita); 
            return ; }  
         else {   
             *registro_buscado = (*p)->registro; 
             printf("Registro encontrado\n");
         }
    
}  
} 
void imprime_dados_ordem(tipo_apontador p){ 
    if(p == NULL) return ;   
      
    imprime_dados_ordem(p->esquerda); 
    printf("%d",p->registro.chave); 
    imprime_dados_ordem(p->direita);
}  
void imprime_dados_pre_ordem(tipo_apontador p){ 
    if(p == NULL) return ;  
    printf("%d",p->registro.chave);
    imprime_dados_pre_ordem(p->esquerda); 
    imprime_dados_pre_ordem(p->direita);  
} 

void imprime_dados_pos_ordem(tipo_apontador p){ 
    if(p == NULL) return ;  
    imprime_dados_pos_ordem(p->direita); 
    imprime_dados_pos_ordem(p->esquerda); 
    printf("%d",p->registro.chave);
     
     
}   
// calculo da altura da arvore  
int altura(tipo_apontador p){ 
    if (p == NULL){  
        return -1;  
    } 
    else { 
        int he = altura(p->esquerda); 
        int hd = altura(p->direita);  
        if(he<hd){ 
            return hd+1;  
        } 
        else return he+1 ; 
    }
}   
// calculo do antecessor para posteriormente ser usado na remoção de um item  
void antecessor(tipo_apontador q , tipo_apontador *r){ 
    if((*r)->direita != NULL){ 
        antecessor(q,&(*r)->direita); 
        return ;  
        // chegou no antecessor
    } 
    q->registro =(*r)->registro; 
    q = *r;  
    // reoganizar a arvore  
    *r = (*r)->direita; 
    free(q); 

}   
void retira(tipo_registro x , tipo_apontador *p){   
    tipo_apontador aux ;  
    if(*p == NULL){ 
        printf(" No nao esta na arvore\n"); 
        return ;  
    }  
    if(x.chave < (*p)->registro.chave){  
        retira(x,&(*p)->esquerda);      
        return ; 
    } 
    if(x.chave > (*p)->registro.chave){  
        retira(x,&(*p)->direita);      
        return ; 
    }  
    if((*p)->direita == NULL){ 
        aux = *p ; 
        *p = (*p)->esquerda ;
        return ;   
    } 

    if((*p)->esquerda != NULL){ 
        antecessor(*p ,&(*p)->esquerda);
        return ;   
    } 

    aux = *p;  
    *p = (*p)->direita;   
    free(aux); 

} 
