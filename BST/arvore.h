#include <stdio.h>  
#include <stdlib.h>  
#include <limits.h> 
#include <sys/time.h> 
/******** Data types******/ 

typedef struct node_file { 
    int key; 
}node_file;  
typedef struct node  *pointer;   
typedef struct node { 
    node_file node_register; 
    pointer left, right ; 
}node ;  
typedef pointer bst;  

/***** functions ******/

/** 
 *  \brief initialize binary search tree  
 *   
 **/    
bst *bst_initialize();  
/** 
 *  \brief  inserting a new node in the already built tree 
 *  \param  new_node The node that will be inserted on the tree  
 *  \param  tree The already built tree
 **/
void bst_node_insert(node_file  new_node , bst *tree);  
/** 
 *  \brief searches the wished node in the tree 
 *  \param  searched_register the node to be searched  
 *  \param tree The already built tree
 **/
node_file  *bst_explore(node_file *searched_register ,bst  *tree);  
/** 
 *  \brief prints the tree height 
 *  \param tree The already built tree
 **/
int bst_height(bst tree);       
/** 
 *  \brief prints the tree data in order 
 *  \param tree The already built tree
 **/
void bst_print_Inorder(bst tree);    
/** 
 *  \brief prints the tree data in  pre order 
 *  \param tree The already built tree
 **/
void bst_print_Preorder(bst tree); 
/** 
 *  \brief prints the tree data in  post order 
 *  \param tree The already built tree
 **/
void bst_print_Postorder(bst tree); 
/** 
 *  \brief node to be placed at the root 
 *   
 **/
void bst_antecedent(pointer q , bst *tree);  
/** 
 *  \brief removes a wished node of the tree 
 *  \param node_content the node file that will be take out  
 *  \param tree The already built tree
 **/
pointer *bst_node_disconnect(node_file node_content , bst *tree); 
  
