#include "alunos.h"  

bst *bst_student_initialize(){ 
    
    bst *new_students_tree = NULL ;    
    bst_group Generic_group = *bst_group_initialize(); 
    printf("The students tree was be initialized.\n");
    return new_students_tree; 

} 
int bst_student_node_insert(node_file  new_node , bst *students_tree){  
    if(*students_tree == NULL){   
        //aloca um buffer de memória para a árvore
        *students_tree = (pointer)malloc(sizeof(node));  
        (*students_tree)->node_register = new_node ;  
        (*students_tree)->right = NULL ; 
        (*students_tree)->left = NULL ;      
        return 1  ;     
    }  
    if(new_node.score > (*students_tree)->node_register.score ) {  
        bst_student_node_insert(new_node , &(*students_tree)->right);   
        return 1 ;  
    } 
    if(new_node.score <= (*students_tree)->node_register.score ) {  
        bst_student_node_insert(new_node , &(*students_tree)->left);   
        return 1 ;  
    }
}   

void bst_student_reads_archieve(bst *students_tree){
    int counter = 0 , counter_aux  = 0 ;  
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
        fscanf(arch,"%s - %d - %s - %f", 
        node_file_aux->name, 
        &node_file_aux->registration_number, 
        node_file_aux->Group.name, 
        &node_file_aux->score); 
        if(feof(arch)) break ;
        
        if (bst_student_node_insert(*node_file_aux,students_tree)){ 
            counter++ ; 
            (*students_tree)->Quantity_students.number_students_registreds = counter;  
            
            if(node_file_aux->score >= 6){  
                counter_aux ++;  
                (*students_tree)->Quantity_students.number_students_Average = counter_aux;
            }  
            
            
        }     
        
    }      
    return ; 
} 

void bst_student_descending_print(bst students_tree){ 
    if(students_tree == NULL) return ;  
    bst_student_descending_print(students_tree->right);
    printf("Name: %s - Registration Number:  %d - Group: %s - Score: %.2f\n", 
        students_tree->node_register.name, 
        students_tree->node_register.registration_number, 
        students_tree->node_register.Group.name, 
        students_tree->node_register.score);
    bst_student_descending_print(students_tree->left);  
     
}  
float bst_student_highest_grade(bst students_tree){ 
    if(students_tree->right == NULL){ 
        return students_tree->node_register.score;  
    }  
    bst_student_highest_grade(students_tree->right);
} 

float bst_student_lowest_grade(bst students_tree){ 
    if(students_tree->left == NULL){ 
        return students_tree->node_register.score;  
    }  
    bst_student_highest_grade(students_tree->left);
}  
