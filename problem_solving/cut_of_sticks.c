#include<stdio.h>
#include<stdlib.h>

int* cutTheSticks(int arr_count, int* arr, int* result_count) 
{
    int indicator_loop;
    int minimum = 1001;
    int sticks_cut = 0;
    static int result[1000] = {0};
    static int result_counter = 0;
    
    while(1)
    {
         sticks_cut = 0;
         
         /* loop for get minimum stick lengh*/
         
        for (indicator_loop = 0; indicator_loop < arr_count; indicator_loop++)
        {
            if((arr[indicator_loop] < minimum) && (arr[indicator_loop] > 0))
            {
                minimum = arr[indicator_loop];
            }
            if(arr[indicator_loop] > 0)
            {
                sticks_cut++;
            }
        } // end for loop
    
        if(sticks_cut == 0) break;  // end of sticks 
        
        result[result_counter] = sticks_cut;
        
        /* loop to decrease array elements */
        
        for (indicator_loop = 0; indicator_loop < arr_count; indicator_loop++)
        {    
            arr[indicator_loop] -= minimum;
        }     
        result_counter++;  // increase sticks-cut's array elements 
        minimum = 1001;  // reset minimum at each iletration    
    }
   *result_count = result_counter;
    return result;   
}

int main()
{
    int n;
    scanf("%d", &n);   
    int *ptr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }
    int result;
    int *arr = cutTheSticks( n, ptr, &result);
    for (int j = 0 ; j < result; j++)
    {
        printf("%d\n", arr[j]);
    }
    free(ptr);
    return 0;
    
}
