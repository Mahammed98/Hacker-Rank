#include<stdio.h>
#include<stdlib.h>
 /*int saveThePrisoner(int Number_of_prisoners, int number_of_sweets, int Chair_number) 
{
    int  result = Chair_number;  //        3 
    
    while(--number_of_sweets)
    {
       
        if(result == Number_of_prisoners)
        {
            result = 1;
        }  
        else 
        {
            result++;
        }    
    }
    return result;
}
*/
int saveThePrisoner(int Number_of_prisoners, int number_of_sweets, int Chair_number) 
{
     int result;
     result = ((number_of_sweets + Chair_number- 1) % Number_of_prisoners) ;
     if(result == 0)
        result = Number_of_prisoners;
     return result;
}

int main ()
{
    int t, m, n, s, result;
    
    scanf("%d", &t);
    
    
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        scanf("%d", &m);
        scanf("%d", &s);
        printf("%d\n", saveThePrisoner(n, m, s));
    }
}