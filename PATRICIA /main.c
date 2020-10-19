#include "PATRICIA.c" 
#define TRUE 1 
int main(){ 
    PATRICIA Patricia_Tree = NULL;  
    char Word[50];  
    int ans = 0 ; 
    while(ans == 0){ 
        printf("Input a word \n"); 
        scanf("%s",Word); 
        Patricia_Tree = PATRICIA_Insert(Word,&Patricia_Tree); 
        printf("1 to stop:\n"); 
        scanf("%d", &ans); 
        if(ans == 1) break;
    }  
    printf("Words in this tree:\n");
    PATRICIA_Print_Alphabetical_Order(Patricia_Tree);
    printf("Quantidade de Palavras: %d\n",Patricia_Tree->Node.measure_words);
    return 0; 
}