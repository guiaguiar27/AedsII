#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "Group.h"
/******DATA TYPES*******/

typedef struct node_file { 
    char name[20]; 
    float  score;  
    Group group[Q_group]; 
    int registration_number ;  
}node_file; 

typedef struct quantity { 
      int number_students_registreds;  
      int number_students_Average;
}quantity; 

typedef struct node  *pointer;   
typedef struct node{  

    node_file node_register; 
    pointer left, right ;  
    quantity Quantity_students;     

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
int  bst_student_node_insert(node_file  new_node , bst *students_tree);
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

/** 
 *  \brief  prints the highest score in the tree   
 *  \param  student_tree The already built student tree
 **/ 
float bst_student_highest_grade(bst students_tree); 
/** 
 *  \brief  prints the highest score in the tree   
 *  \param  student_tree The already built student tree
 **/  
float bst_student_lowest_grade(bst students_tree);  
