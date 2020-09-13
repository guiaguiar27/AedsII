#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

/******DATA TYPES*******/
typedef struct node_file { 
    char name[20]; 
    float  score;  
    char group[10]; 
    int registration_number ;  
}node_file;  
typedef struct node  *pointer;   
typedef struct node { 
    node_file node_register; 
    pointer left, right ;  
    int count ; 
}node ;  
typedef pointer bst;  
/******DATA TYPES*******/  
/** 
 *  \brief initialize binary search tree cotains student data    
 **/    
bst *bst_student_initialize(); 
/** 
 *  \brief  inserting a new node in the already built tree 
 *  \param  new_node The node that will be inserted on the tree  
 *  \param  students_tree The already built student tree
 **/
void bst_student_node_insert(node_file  new_node , bst *students_tree);
/** 
 *  \brief  read the txt archieve and write on the students tree  
 *  \param  student_tree The already built student tree
 **/
void bst_student_reads_archieve(bst *studets_tree);    
/** 
 *  \brief  prints tree data in descenting order   
 *  \param  student_tree The already built student tree
 **/ 
void bst_student_descending_print(bst students_tree); 


