#include "Group.h"
bst_group *bst_group_initialize(){ 
    
    bst_group *new_grou_tree = NULL ;     
    printf("The  group tree was be initialized.\n"); 
    return new_grou_tree; 
} 
void bst_group_node_insert(group_node_file new_group_node , bst_group *group_tree){  
    if(*group_tree == NULL){   
        //aloca um buffer de memória para a árvore
        *group_tree = (Group_pointer)malloc(sizeof(Group_node));  
        (*group_tree)->node_register = new_group_node ;    
        (*group_tree)->right = NULL ; 
        (*group_tree)->left = NULL ; 
        printf("The node was be inserted!\n"); 
        return ;     
    }  
    if(new_group_node.score > (*group_tree)->node_register.score ) {  
        bst_node_insert(new_group_node , &(*group_tree)->right); 
        printf("The node was be inserted on the right side of the tree!\n");  
        return ;  
    } 
    if(new_group_node.score < (*group_tree)->node_register.score) {  
        bst_node_insert(new_group_node , &(*group_tree)->left); 
        printf("The node was be inserted on the left side of the tree!\n");  
        return ;  
    } 
}   
 
float bst_group_explore(bst_group  group_tree){ 
    if(group_tree->right == NULL){  
        return group_tree->node_register.score;  
    }  
    bst_group_explore(group_tree->right);
}  
