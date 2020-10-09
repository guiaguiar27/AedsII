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
            sbb_explore(searched_register,&(*tree)->Left); 
            return 0;  
    } 
    else if(searched_register.key > (*tree)->node_register.key ){        
            printf("Searching on the right side of the tree\n"); 
            sbb_explore(searched_register,&(*tree)->Right); 
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
    printf("Left-Left transformation it is happening ! \n");
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
    printf("Left-Right transformation it is happening ! \n");
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
    printf("Right-Right transformation it is happening ! \n"); 
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
    printf("Right-Left transformation it is happening ! \n");
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
void sbb_node_Internal_insert(node_register  new_node ,  SBB *tree , edges *edge_inclination , short *End){ 
    if (*tree == NULL){ 
        *tree = (pointer)malloc(sizeof(node)); 
        *edge_inclination = horizontal ; 
        (*tree)->Left = NULL ; 
        (*tree)->Right = NULL ;  
        (*tree)->node_register = new_node ;  
        (*tree)->Bit_L = (*tree)->Bit_R = vertical ; 
        *End = FALSE  ; return;     
    } 
    if(new_node.key < (*tree)->node_register.key){ 
        // in this case the node will run in the left side 
        sbb_node_Internal_insert(new_node,&(*tree)->Left,&(*tree)->Bit_L,End); 
        if(*End) return ;   
        if((*tree)->Bit_L == vertical) { 
            *End = TRUE; 
            return ;  
        }   
        if((*tree)->Left->Bit_L == horizontal){ 
            sbb_LL_transformation(tree); 
            *edge_inclination = horizontal; 
            return ; 
        } 
        if((*tree)->Left->Bit_R == horizontal){ 
            sbb_LR_transformation(tree);  
            *edge_inclination = horizontal; 
            return ; 
        }
    } 
    if(new_node.key <= (*tree)->node_register.key){ 
        printf("The not already exists in this tree!\n "); 
        *End = TRUE;  
    } 
    else { 
        // the node is bigger than the tree  
        // run in the right side  
        sbb_node_Internal_insert(new_node,&(*tree)->Right,&(*tree)->Bit_R,End); 
        if(*End) return ;   
        if((*tree)->Bit_R == vertical) { 
            *End = TRUE; 
            return ;  
        }    
        
        if((*tree)->Right->Bit_R == horizontal){ 
            sbb_RR_transformation(tree); 
            *edge_inclination = horizontal; 
            return ; 
        } 
        if((*tree)->Right->Bit_L == horizontal){ 
            sbb_RL_transformation(tree);  
            *edge_inclination = horizontal; 
            return ; 
        }
    } 

}
/******************************************************************************************/ 
void sbb_node_insert(node_register  new_node , SBB *tree){  
    short End ; edges edge_inclination;  
    sbb_node_Internal_insert(new_node,tree,&edge_inclination,&End);      
}  
/******************************************************************************************/  
void sbb_ShortLeft(pointer *p, short *End){ 

}
/******************************************************************************************/  
void sbb_ShorRight(pointer *p, short *End){ 

}  

/******************************************************************************************/  
void sbb_antecedent(pointer q , SBB *tree, short *End){ 

}

/******************************************************************************************/  
void sbb_node_internal_disconnect(node_register x, SBB *tree, short *End){ 
    pointer *AUX;  
    if(*tree == NULL){ 
        printf("The tree is void\n"); return; 
    }  
    if(x.key < (*tree)->node_register.key){ 
        sbb_node_internal_disconnect(x,(*tree)->Left,&End); 
        if(!End){ 
            sbb_ShortLeft(tree,End);
            return ;  
        }
    }
    if(x.key < (*tree)->node_register.key){
        sbb_node_internal_disconnect(x,(*tree)->Right,&End); 
        if(!End){ 
            sbb_ShortRight(tree,End);
            return ;  
        }
    }    
    // the node was been finded
    *End = FALSE ; AUX = *tree;  
    if((*AUX)->Right == NULL){ 
        tree = (*AUX)->Left ; 
        free(AUX);  
        if(*tree != NULL){ 
            *End = TRUE;   
            return;  
        }
    } 
    if((*AUX)->Left == NULL){ 
        tree = (*AUX)->Right ; 
        free(AUX);  
        if(*tree != NULL){ 
            *End = TRUE;   
            return;  
        }
    }
    sbb_antecedent(AUX,&(*tree)->Left,&End); 
    // repair with sort left, beacause the antecedent are at the left side  
    if(!*End){ 
        sbb_ShortLeft(tree,End);  
    }
}
/******************************************************************************************/ 
void  sbb_node_disconnect(node_register x, SBB *p){
    short *End; 
    sbb_node_internal_disconnect(x,p,&End); 
} 
/******************************************************************************************/ 
