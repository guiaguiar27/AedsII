#include "arvore.h"   
bst *bst_initialize(){ 
    
    bst *new_tree = NULL ;     
    printf("The tree was be initialized.\n"); 
    return new_tree; 
} 
void bst_node_insert(node_file  new_node , bst *tree){  
    if(*tree == NULL){   
        //aloca um buffer de memória para a árvore
        *tree = (pointer)malloc(sizeof(node));  
        (*tree)->node_register = new_node ;  
        (*tree)->right = NULL ; 
        (*tree)->left = NULL ; 
        printf("The node was be inserted!\n"); 
        return ;     
    }  
    if(new_node.key > (*tree)->node_register.key ) {  
        insere_no(new_node , &(*tree)->right); 
        printf("The node was be inserted on the right side of the tree!\n");  
        return ;  
    } 
    if(new_node.key <= (*tree)->node_register.key ) {  
        insere_no(new_node , &(*tree)->left); 
        printf("The node was be inserted on the left side of the tree!\n");  
        return ;  
    }
}   
 
node_file  *bst_explore(node_file *searched_register ,bst  *tree){ 
    if(*tree == NULL){  
        printf("the tree is void\n");
        return ;   
    }
    else if((*searched_register).key < (*tree)->node_register.key ){        
            printf("Searching on the left side of the tree\n"); 
            pesquisa_no(searched_register,&(*tree)->left); 
            return ;  
    } 
    else if((*searched_register).key > (*tree)->node_register.key ){        
            printf("Searching on the right side of the tree\n"); 
            pesquisa_no(searched_register,&(*tree)->right); 
            return ;  
    }
    else {   
        *searched_register = (*tree)->node_register; 
        printf("Register was finded\n"); 
        return searched_register;  
    }
}  

void bst_print_Inorder(bst tree){ 
    if(tree == NULL) return ;   
    
    bst_print_Inorder(tree->left);   
    printf("%d",tree->node_register.key); 
    bst_print_Inorder(tree->right);
}  
void bst_print_Preorder(bst tree){ 
    if(tree == NULL) return ;  

    printf("%d",tree->node_register.key);
    bst_print_Preorder(tree->left); 
    bst_print_Preorder(tree->right);  
} 
void bst_print_Postorder(bst tree){ 
    if(tree == NULL) return ;  
    bst_print_Postorder(tree->right);  
    bst_print_Preorder(tree->right);
    printf("%d",tree->node_register.key);
     
     
}  
int bst_height(bst  tree){ 
    if (tree == NULL){  
        return -1;  
    } 
    else { 
        int hL = bst_height(tree->left); 
        int hR = bst_height(tree->right);
        if(hL<hR){ 
            return hR+1;  
        } 
        else return hL+1 ; 
    }
}   
void bst_antecedent(pointer q , bst *tree){ 
    if((*tree)->right != NULL){ 
        bst_antecedent(q,&(*tree)->right); 
        return ;  
    } 
    q->node_register = (*tree)->node_register; 
    q = *tree; 
    *tree = (*tree)->left; 
    free(q);  
}
void  *bst_node_disconnect(node_file x, bst *p){ 
    pointer node_aux ;  
    if(*p == NULL) printf(" The tree is void");
    if(x.key < (*p)->node_register.key){ 
        bst_node_insert(x, &(*p)->left); 
        return ; 
    }
    if(x.key > (*p)->node_register.key){ 
        bst_node_insert(x, &(*p)->right);
        return ;  
    } 
    if((*p)->right == NULL){ 
        node_aux = *p ; 
        *p = (*p)->left ; 
        free(node_aux); 
    }  
    if((*p)->left != NULL){ 
        bst_antecedent(*p,&(*p)->left);  
        return;  
    } 
    node_aux = *p ; 
    *p = (*p)->right; 
    free(node_aux);     

} 
