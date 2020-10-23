
// THIS FILE IS WILL USE TO QUANTIFY SOME MEASURES OF THE PATRICIA TREE
#include <sys/resource.h>
#include <errno.h>
#include <unistd.h>
typedef struct{ 
    int measure_words;  
    long int measure_memory;  
    long int measure_comparisons ;  
}PATRICIA_Stats;    
/** 
 * \brief Initialize and set to 0 the respective values 
 * \param S The data type that will be archieve all the metrics 
 */
void Sats_Init(PATRICIA_Stats *S);  
/** 
 * \brief Show the metrics
 */
void Stats_Print_Mount(PATRICIA_Stats S);  
void Stats_Print_Memory_Consumption(PATRICIA_Stats S); 
void Stats_Print_Comparisons(PATRICIA_Stats S);