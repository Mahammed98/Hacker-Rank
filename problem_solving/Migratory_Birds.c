#include<stdio.h>
#include<stdlib.h>
int migratoryBirds (int *, const int);

int main()
{
    int size_of_array, indicator;
    scanf("%d", &size_of_array);
    
    int *ptr = (int *)malloc( size_of_array * sizeof(int));
    
    for(indicator = 0; indicator < size_of_array; indicator++)
    {
        scanf("%d", &ptr[indicator]);
    }
    
    printf("%d\n", migratoryBirds(ptr, size_of_array));
    
    free(ptr);
    return 0;   
}
/* this is optmization of  migratoryBirds function 
    using mode algorithm 
    */
int migratoryBirds (int *arr, const int number_of_elements)
{
    /*
        we define array with 6 elements, becuas type of birds from 1-5
     */
    int freq[6] = {0};   
    int indicator, contaner = 0, freq_value;
    
    for (indicator = 0; indicator < number_of_elements; indicator++)
    {
        ++freq[arr[indicator]];
    }
    for (indicator = 1; indicator <= 5; indicator++)
    {
        if(freq[indicator] > contaner)
        {
            contaner = freq[indicator];
            freq_value = indicator;
        }
    }
    return freq_value;
}

// this another algorithm but low efficiency, and take more excution time  
/*int migratoryBirds (int *arr, int number_of_elements)
{
    int counter_past = 1;
    int counter_present = 1;
    int contaner = 0;
    int indicator_for_loop_1, indicator_for_loop_2;
    for(indicator_for_loop_1 = 0; indicator_for_loop_1 < number_of_elements; indicator_for_loop_1++)
    {
        for (indicator_for_loop_2 = indicator_for_loop_1; indicator_for_loop_2 < number_of_elements; indicator_for_loop_2++)
             {
                if(arr[indicator_for_loop_1] == arr[indicator_for_loop_2 + 1])
                {
                    counter_present++;
                }
             } 
        if((counter_present > counter_past))
            {
                counter_past = counter_present;
                contaner = arr[indicator_for_loop_1];    
            } 
        else if((counter_present > 1) && (counter_present == counter_past))
        {
            if(contaner > arr[indicator_for_loop_1])
            {
                contaner = arr[indicator_for_loop_1];    
            }
        } 
        counter_present = 1;

    }
    return contaner;
    
}*/
