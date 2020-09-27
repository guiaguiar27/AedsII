#include "sbb.h"
/******************************************************************************************/
// initialize the sbb tree  
SBB *sbb_initialize(){ 
    SBB *sbb_tree = NULL ; 
    printf("The SBB was created !\n"); 
    return sbb_tree;  
}
/******************************************************************************************/
// search for a node   
// same fucntion structure used in the BSTs 
node_register   *sbb_explore(node_register searched_register ,SBB *tree){ 
    node_register *node_s = (pointer)malloc(sizeof(node_register)) ;   
    if(*tree == NULL){  
        printf("the tree is void\n");
        return NULL ;   
    }
    else if(searched_register.key < (*tree)->node_register.key ){        
            printf("Searching on the left side of the tree\n"); 
            bst_explore(searched_register,&(*tree)->Left); 
            return 0;  
    } 
    else if(searched_register.key > (*tree)->node_register.key ){        
            printf("Searching on the right side of the tree\n"); 
            bst_explore(searched_register,&(*tree)->Right); 
            return  0 ;  
    }
    else {   
        *node_s = (*tree)->node_register; 
        printf("Register was finded\n"); 
        return node_s;  
    }
}  
/******************************************************************************************/  
void  sbb_LL_transformation(pointer *Generic_pointer){  
    pointer Aux_pointer; 
    //1<- 2 <- 3(G)      
    // Aux_pointer is the left node
    Aux_pointer = (*Generic_pointer)->Left;    
    // 2 replace 3 
    // pointer conecting 
    (*Generic_pointer)->Left = Aux_pointer->Right; 
    Aux_pointer->Right = *Generic_pointer ; 
    // repair the wrong edges
    (*Generic_pointer)->Bit_L = vertical;     
    Aux_pointer->Bit_L = vertical ; 
   // change
    *Generic_pointer = Aux_pointer; 
} 
/******************************************************************************************/  
void  sbb_LR_transformation(pointer *Generic_pointer){
    pointer Aux_pointer1 , Aux_pointer2; 
    // right pointer
    Aux_pointer1 = (*Generic_pointer)->Left;  
    Aux_pointer2 = Aux_pointer1->Right ;   
    // repair the wrong edges
    Aux_pointer1->Bit_R = vertical;  
    (*Generic_pointer)->Bit_L = vertical ; 
    // pointer conections  
    Aux_pointer1->Right = Aux_pointer2->Left ;   
    Aux_pointer2->Left = Aux_pointer1 ;  
    Aux_pointer2->Right = (*Generic_pointer)->Left;   
    (*Generic_pointer)->Left = Aux_pointer2;  
    // change the Generic_pointer (sink of the subtree)
    *Generic_pointer = Aux_pointer2 ; 
} 
/******************************************************************************************/  
void  sbb_RR_transformation(pointer *Generic_pointer){  
    pointer Aux_pointer;      
    // Aux_pointer is the Right node
    Aux_pointer = (*Generic_pointer)->Right;    
    // 2 replace 3 
    // pointer conecting 
    (*Generic_pointer)->Right = Aux_pointer->Left; 
    Aux_pointer->Left = *Generic_pointer ; 
    // repair the wrong edges
    (*Generic_pointer)->Bit_R = vertical;     
    Aux_pointer->Bit_R = vertical ; 
   // change
    *Generic_pointer = Aux_pointer; 
}
/******************************************************************************************/  
void  sbb_RL_transformation(pointer *Generic_pointer){
    pointer Aux_pointer1 , Aux_pointer2; 
    // right pointer
    Aux_pointer1 = (*Generic_pointer)->Right;  
    Aux_pointer2 = Aux_pointer1->Left ;   
    // repair the wrong edges
    Aux_pointer1->Bit_L = vertical;  
    (*Generic_pointer)->Bit_R = vertical ; 
    // pointer conections  
    Aux_pointer1->Left = Aux_pointer2->Right ;   
    Aux_pointer2->Right = Aux_pointer1 ;  
    Aux_pointer2->Left = (*Generic_pointer)->Right;   
    (*Generic_pointer)->Right = Aux_pointer2;  
    // change the Generic_pointer (sink of the subtree)
    *Generic_pointer = Aux_pointer2 ; 
}  
/******************************************************************************************/