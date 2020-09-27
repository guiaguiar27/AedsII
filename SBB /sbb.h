/*****************************************SYMMETRIC BINARY B-TREE*****************************************/

#include <stdio.h> 
#include <stdlib.h> 
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



