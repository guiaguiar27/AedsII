#include "PATRICIA.c" 
#define TRUE 1 
void main(){ 
    PATRICIA *Patricia_Tree;  
    Key_Word Word;  
    int ans = 0 ; 
    while(TRUE){ 
        printf("Input a word \n"); 
        scanf("%s",Word); 
        *Patricia_Tree = PATRICIA_Insert(Word,Patricia_Tree); 
        printf("To continue press 1, otherwise, 0:\n"); 
        scanf("%d",ans); 
        if(ans == 0) break ;    
    } 
    

}