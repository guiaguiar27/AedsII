#include "alunos.c" 
int main(){ 
    bst *student_tree;  
    student_tree = bst_student_initialize(); 
    printf("ok\n"); 
    bst_student_reads_archieve(student_tree);   
    bst_student_descending_print(student_tree);
    
    return 0;  
}