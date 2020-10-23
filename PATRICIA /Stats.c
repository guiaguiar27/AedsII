#include "Stats.h"   
/**********************************************************************************/
void Sats_Init(PATRICIA_Stats *S){   
    S->measure_words = 0 ;    
    S->measure_memory = 0 ;  
    S->measure_comparisons = 0   ; 
} 
/**********************************************************************************/
void Stats_Print_Mount(PATRICIA_Stats S){ 
    printf("Number of words in this tree:  %d\n", S.measure_words);
} 
/**********************************************************************************/ 
void Stats_Print_Memory_Consumption(PATRICIA_Stats S){ 
    printf("Total of memory consumption:  %ld  kilobytes\n", S.measure_memory);
}  
/**********************************************************************************/ 
void  Stats_Print_Comparisons(PATRICIA_Stats S){ 
    printf("Total of comparison in the search:  %ld  \n", S.measure_comparisons);   
}
/**********************************************************************************/ 