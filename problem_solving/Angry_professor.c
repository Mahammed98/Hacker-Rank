#include<stdio.h>
#include<stdlib.h>

void angryProfessor(int *, int, int); 
int main()
{
    int Number_of_task, Number_of_elements, Number_of_student_attendences, Scan_array_elements;
    
    int *ptr;
    scanf("%d", &Number_of_task);
    
    while(Number_of_task--)
    {
        scanf("%d", &Number_of_elements);
        scanf("%d", &Number_of_student_attendences);
      
        ptr = (int *)malloc(sizeof(int) * Number_of_elements);
    
        for (Scan_array_elements = 0; Scan_array_elements < Number_of_elements; Scan_array_elements++ )
        {
            scanf("%d", &ptr[Scan_array_elements]);
        }
        
        angryProfessor(ptr, Number_of_elements, Number_of_student_attendences);
        free(ptr);
    }
    
}
void angryProfessor(int * arr, int number, int k)
{
    int counter = 0;
    int indicator;
    
    for(indicator = 0; indicator < number; indicator++)
    {
        if(arr[indicator] <= 0)
        {
            counter++;
        }
    }
    if(counter >= k)
    {
        printf("NO\n");
    }
    else
    {
        printf("YES\n");
    }
} 
