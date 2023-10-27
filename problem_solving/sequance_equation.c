#include<stdio.h>
#include<stdlib.h>

int* permutationEquation(int, int*);

int main()
{
    int number_of_elements;
    scanf("%d", &number_of_elements);
    
    int *ptr = (int*)malloc(sizeof(int) * number_of_elements);
    
    for(int i = 0; i < number_of_elements; i++)
    {
        scanf("%d", &ptr[i]);
    }
     int *z =permutationEquation(number_of_elements, ptr);
     
    for(int i = 0; i < number_of_elements; i++)
    {
        printf("%d\n", z[i]);
    }
    free(ptr);
}

/* function*/

int* permutationEquation(int number, int* arr) 
{
    int x = 1, y;
    static int storing_arr[50]; 
    while (x <= number)
    {
         /*  start from x = 1 to number of elements 
            ex:
                p = [2,3,1]
                x = 1 equvilant to p[3] = p[p[2]] -> y = 2
                x = 2 equvilant to p[1] = p[p[3]] -> y = 3
                x = 3 equcilant to p[2] = p[p[1]] -> y = 1
        */
        
        for(int indicator_1 = 1; indicator_1 <= number; indicator_1++)
        {
            if(arr[indicator_1 - 1] == x)
            {
                for(int indicator_2 = 1; indicator_2 <= number; indicator_2++)
                {
                    if(arr[indicator_2 - 1] == indicator_1)
                    {
                        y = indicator_2;
                        storing_arr[x - 1] = y;
                        break;              // exit from sub loop
                    }
                }
                break;  // exit from main for loop
            }
        }
        x++;
    }
    return storing_arr;
}
