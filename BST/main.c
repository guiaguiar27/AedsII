#include "arvore.c"
 int main(){
         
    printf("inicio\n"); 
    tipo_registro x ;   
    int ans = 0 ;   
    int ans_sec = 0 ;  
    int chave_busc = 0  ; 
    int chave_aux = 0 ;  
    bst dicionario;   
    // um dicionario é do tipo bst   
    inicializa_bst(&dicionario);   
    scanf("%d",&chave_aux); 
    x.chave = chave_aux ;   
    chave_aux = 0  ; 
    while(x.chave > 0){ 
        insere_no(x,&dicionario); 
        scanf("%d",&chave_aux); 
        x.chave = chave_aux ; 
        chave_aux = 0  ;    

     }   
    /*  
    printf("Fim\n"); 
    //pesquisa(&dicionario);  
    printf("Escolha a opcao :\n 1- Buscar \n 2 - Retirar \n 3 - Imprimir\n"); 
    scanf("%d\n",&ans); 
    if(ans == 1){ 
        
        chave_busc = 0 ;  
        printf("Digite o valor da chave que vc deseja retirar\n"); 
        scanf("%d",&chave_busc);    
        x.chave = chave_busc;  
        pesquisa_no(&x,&dicionario);
     } 
    else if(ans == 2 ){ 
        //retira
        
        chave_busc = 0 ;  
        printf("Digite o valor da chave que vc deseja retirar\n"); 
        scanf("%d",&chave_busc); 
        x.chave = chave_busc ;  
        retira(x,&dicionario); 
    }  
    else if(ans == 3){ 
    
        printf("Digite : \n1 Ordem\n2 Pre-ordem\n3 pos-ordem\n "); 
        scanf("%d",&ans_sec);  
        switch(ans_sec){
            case 1 :  
                imprime_dados_ordem(&dicionario); 
                break ;  
            case 2 :  
                imprime_dados_pre_ordem(&dicionario); 
                break ; 
            case 3 :   
            
                imprime_dados_pos_ordem(&dicionario);   
                break ;   
        }

    } 
*/
     /* 
     insere_no(tipo_registro novo_no, tipo_apontador &no );  
     pesquisa(tipo_registro *registro_buscado  , tipo_apontador *p);  
     */ 
    return 0 ;      
 }