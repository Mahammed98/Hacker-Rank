#include<stdio.h>
#include<stdlib.h>

int birthday_function(short int, short int *, short int, short int month);

int main()
{
    short int n, indicator_for_loop, month, day;
    short int* arr;
    scanf("%hd", &n);
    arr = (short int *)malloc(n*sizeof(short int));
    
    for(indicator_for_loop = 0; indicator_for_loop < n; indicator_for_loop++)
    {
        scanf("%hd", &arr[indicator_for_loop]);
    }
    
    scanf("%hd %hd", &day, &month);
    
    short int result = birthday_function(n, arr, day, month);
    printf("%hd\n", result);
    free(arr);
}

int birthday_function(short int number_of_bars, short int *ptr, short int _day_, short int _month_)
{
    short int indicator, indicator_for_sum , counter = 0;
    int sum = 0;
    
    for(indicator = 0; indicator < number_of_bars; indicator++) 
    {
        for(indicator_for_sum = indicator; indicator_for_sum < _month_ + indicator; indicator_for_sum++) 
            {
                sum += ptr[indicator_for_sum];
            }
        if (sum == _day_)
        {
           counter++; 
        }
        sum = 0;
    }
    return counter;
}
