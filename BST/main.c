#include "arvore.c"
 int main(){  
    
    node_file x ;   
    int answer = 1 ;   
    int answer_sec = 0 ;  
    int searched_key = 0  ; 
    int key_aux = 0 ;  
    bst tree;   
    node_file *node_aux = (node_file*)malloc(sizeof(node_file));
         
    tree = bst_initialize();
    scanf("%d",&key_aux); 
    x.key = key_aux ;   
    key_aux = 0  ; 
    while(x.key >= 0){ 
        bst_node_insert(x,&tree);
        scanf("%d",&key_aux); 
        x.key = key_aux ; 
        key_aux = 0  ;    
     } 
    while(answer > 0){    
        printf("INPUT:\n1- To search  \n2 - To remove \n3 - To print\n"); 
        scanf("%d\n",&answer); 
        if(answer == 1){ 
            searched_key = 0 ;  
            printf("Key: \n"); 
            scanf("%d",&searched_key);    
            x.key = searched_key;  
            node_aux = bst_explore(x,&tree); 
            printf("Register was finded: %d\n",node_aux->key);
        } 
        if(answer == 2 ){ 
            
            searched_key = 0 ;  
            printf("Key to be removed: \n"); 
            scanf("%d",&searched_key); 
            x.key = searched_key ;  
            bst_node_disconnect(x,&tree); 
        }  
        printf("INPUT:\n1 Order\n2 Pre order\n3 post order\n ");
        if(answer == 3){  
            scanf("%d",&answer_sec);  
            switch(answer_sec){
                case 1 :  
                    bst_print_Inorder(tree); 
                    break ;  
                case 2 :  
                    bst_print_Preorder(tree); 
                    break ; 
                case 3 :    
                    bst_print_Postorder(tree);   
                    break ;   
            }
        }  
    }  
    return 0 ;      
}