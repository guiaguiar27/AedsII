/*****************************************SYMMETRIC BINARY B-TREE*****************************************/

#include <stdio.h> 
#include <stdlib.h>  
#define TRUE 1  
#define FALSE 0 
/****************DATA TYPES **************************/
typedef struct { 
    int key ;  
}node_register; 
typedef enum { vertical, horizontal }edges;     
typedef struct node *pointer;  
typedef struct node{ 
    node_register node_register;  
    pointer Right, Left;  
    edges Bit_L , Bit_R ;  
} node ;   
typedef pointer SBB;  
/***************************FUNCTIONS******************************/  
/** 
 *  \brief initialize SBB
 */
SBB *sbb_initialize();  
/** 
 *  \brief search for a node in SBB, return this node 
 *  \param searched_register the node will be searched  
 *  \param tree the tree who node is finded  
 */ 
node_register  *sbb_explore(node_register searched_register ,SBB *tree);  
/** 
 * \brief Bayer transforamtion Left-Left
 * \param Generic_pointer Pointer that will be transformed
 */
void  sbb_LL_transformation(pointer *Generic_pointer); 
/** 
 * \brief Bayer transforamtion Left-Right 
 * \param Generic_pointer Pointer that will be transformed
 */
void  sbb_LR_transformation(pointer *Generic_pointer); 
/** 
 * \brief Bayer transforamtion Right-Right 
 * \param Generic_pointer Pointer that will be transformed 
 */
void  sbb_RR_transformation(pointer *Generic_pointer); 
/** 
 * \brief Bayer transforamtion Right-Left 
 * \param Generic_pointer Pointer that will be transformed
 */
void  sbb_RL_transformation(pointer *Generic_pointer); 
/** 
 * \brief Inserts a new node to the tree  
 * \param new_node The node register that will be inserted 
 * \param tree the tree in construction 
 */ 
void sbb_node_insert(node_register  new_node , SBB *tree);  
/** 
 * \brief Auxiliar function to insert a new node to the tree  
 * \param new_node The node register that will be inserted 
 * \param tree the tree in construction 
 * \param edge_inclination the inclination kind  
 * \param End  flag to stop 
 */ 
void sbb_node_Internal_insert(node_register  new_node ,  SBB *tree , edges *edge_inclination , short *End);
/** 
 * \brief remove a chosen node  
 * \param  x node that will be removed  
 * \param  p tree
 */
void  sbb_node_disconnect(node_register x, SBB *tree) ; 
void sbb_node_internal_disconnect(node_register x, SBB *tree, short *End);   
void sbb_ShortLeft(pointer *p , short *End);   
void sbb_ShorRight(pointer *p, short *End);  
void sbb_antecedent(pointer q , SBB *tree, short *End);