#include "alunos.c" 
int main(){ 
    bst student_tree; 
    int answer = 8 ; 
    student_tree = bst_student_initialize(); 
    float highest, lowest ;   
    //Group *students_groups = (Group*)malloc(sizeof(Group)); 
    bst_student_reads_archieve(&student_tree);   
    while(answer > 0){
    printf("Press the number corresponding what you wanna do \n"); 
    printf("0 - to quit; \n1 - To print in descending order\n2 - To print how much students are registred in this class\n"); 
    printf("3 - To print how much students are above the average in this class \n");
    printf("4 - To see the highest\n5 - To see the lowest grade in this class \n");
    scanf("%d",&answer);   
    if(answer == 1 )
        bst_student_descending_print(student_tree);
    if(answer == 2 ) 
        printf("This class has %d studets registred\n",student_tree->Quantity_students.number_students_registreds); 
    if(answer == 3 )  
        printf("This class has %d studets above the average\n",student_tree->Quantity_students.number_students_Average);
    if(answer == 4 )    
        printf("The highest score is : %.3f\n",bst_student_highest_grade(student_tree));  
    if(answer == 5)
        printf("The lowest score is : %.3f\n",bst_student_lowest_grade(student_tree));  
    else if(answer == 0)  
        break;
    
    }
    return 0;  
}