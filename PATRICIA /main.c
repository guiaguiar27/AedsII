#include "PATRICIA.c"  
#define TRUE 1 
int main(){ 
    PATRICIA Patricia_Tree = NULL;   
    PATRICIA_Stats S ; 
    char Word[50];  
    int ans = 0 ;   
    Sats_Init(&S);
    while(ans == 0){ 
        printf("Input a word \n"); 
        scanf("%s",Word); 
        Patricia_Tree = PATRICIA_Insert(Word,&Patricia_Tree,&S);  
        
        printf("1 to stop:\n"); 
        scanf("%d", &ans); 
        if(ans == 1) break;
    }  
    printf("Words in this tree:\n");
    PATRICIA_Print_Alphabetical_Order(Patricia_Tree);
    Stats_Print_Mount(S); 
    Stats_Print_Memory_Consumption(S); 
    printf("Word to search :\n"); 
    scanf("%s",Word); 
    PATRICIA_Node_Search(Word,Patricia_Tree,&S); 
    Stats_Print_Comparisons_Search(S); 
    Stats_Print_Comparisons_Insert(S);
    return 0; 
}