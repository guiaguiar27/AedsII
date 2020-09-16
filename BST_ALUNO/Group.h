#include <stdio.h>  
#include <stdlib.h>  
/******** Data types******/ 

typedef struct group_node_file { 
    float score; 
    char name[10];  
}group_node_file;  
typedef struct Group_node  *Group_pointer;   
typedef struct Group_node { 
    group_node_file node_register; 
    Group_pointer left, right ; 
}Group_node ;  
typedef Group_pointer bst_group;  

/***** functions ******/

/** 
 *  \brief initialize binary search tree    
 **/    
bst_group *bst_group_initialize();  
/** 
 *  \brief  inserting a new node in the already built tree 
 *  \param  new_node The node that will be inserted on the tree  
 *  \param  tree The already built tree
 **/
void bst_group_node_insert( group_node_file  new_node , bst_group *tree);  
/** 
 *  \brief searches the wished node in the tree 
 *  \param  searched_register the node to be searched  
 *  \param tree The already built tree
 **/
float bst_group_explore(bst_group  tree);  
