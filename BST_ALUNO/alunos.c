#include "alunos.h"  

bst *bst_student_initialize(){ 
    
    bst *new_students_tree = NULL ;     
    printf("The students tree was be initialized.\n"); 
    return new_students_tree; 
} 
void bst_student_node_insert(node_file  new_node , bst *students_tree){  
    if(*students_tree == NULL){   
        //aloca um buffer de memória para a árvore
        *students_tree = (pointer)malloc(sizeof(node));  
        (*students_tree)->node_register = new_node ;  
        (*students_tree)->right = NULL ; 
        (*students_tree)->left = NULL ; 
        printf("The node was be inserted!\n"); 
        (*students_tree)->count++;
        return ;     
    }  
    if(new_node.score > (*students_tree)->node_register.score ) {  
        bst_student_node_insert(new_node , &(*students_tree)->right); 
        printf("The node was be inserted on the right side of the tree!\n");  
        (*students_tree)->count++;
        return ;  
    } 
    if(new_node.score <= (*students_tree)->node_register.score ) {  
        bst_student_node_insert(new_node , &(*students_tree)->left); 
        printf("The node was be inserted on the left side of the tree!\n");  
        (*students_tree)->count++;
        return ;  
    }
}   
void bst_student_reads_archieve(bst *students_tree){
    FILE *arch ;  
    node_file *node_file_aux = (node_file*)malloc(sizeof(node_file));  
    int count = 0 ;   
    arch = fopen("alunos.txt","r");  
    if(arch == NULL){
        printf("The file was not opened\n");
        return ; 
    } 
    else printf("File was opened\n ");  
    while(!feof(arch)){     
        printf("read the first line\n");
        
        if(fscanf(arch,"%s - %d - %s - %f", 
        node_file_aux->name, 
        &node_file_aux->registration_number, 
        node_file_aux->group, 
        &node_file_aux->score) == NULL) break ;
        
        fscanf(arch,"%s - %d - %s - %f", 
        node_file_aux->name, 
        &node_file_aux->registration_number, 
        node_file_aux->group, 
        &node_file_aux->score); 

        bst_student_node_insert(*node_file_aux,&students_tree); 
        
    }      
    return ; 
} 
void bst_student_descending_print(bst students_tree){ 
     if(students_tree == NULL) return ;  
    bst_student_descending_print(students_tree->right);
    printf("Name: %s - Registration Number:  %d - Group: %s - Score: %f\n", 
        students_tree->node_register.name, 
        &students_tree->node_register.registration_number, 
        students_tree->node_register.group, 
        &students_tree->node_register.score);
    bst_student_descending_print(students_tree->left); 
     
} 