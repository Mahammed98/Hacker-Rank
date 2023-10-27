#include <stdio.h>
#include <stdlib.h>


void fairRations(int B_count, int* B) 
{
    static char *result = "No";
    int indicator, Odd_Counter = 0;
    int number_of_loaves = 0;
     /*
        check first the number of odd numbers
        */
    for(indicator = 0; indicator < B_count; indicator++)
    {
        if((B[indicator] % 2) == 1)
        {
            Odd_Counter++;
        }   
    }
    
    if((Odd_Counter % 2))
    {
        printf("%s", "NO");
    }
    else 
    {
        for(indicator = 0; indicator < B_count; indicator++)
        {
            if(B[indicator] % 2) // if number is odd
            {
                B[indicator]++; // increament 
                B[indicator + 1]++; // increament the next
                number_of_loaves += 2;  // increament number of loaves +2
            }   
        }
        printf("%d", number_of_loaves);
    }   
}

 int main()
 {
     
    int n;
    scanf("%d", &n);
    
    int *ptr = (int *)malloc(sizeof(int) * n);
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }
    
    fairRations(n, ptr);
    
    free(ptr);
       
    return  0;  
 }