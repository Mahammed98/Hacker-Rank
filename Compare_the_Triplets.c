#include<stdio.h>
int* compareTriplets(int a_count, int* a, int b_count, int* b) 
{
        int Comp_Arr[2] = {0 , 0};
    int *Comp_Arr_ptr = Comp_Arr;
    int indecator;
    for(indecator = 0; indecator < a_count ; indecator++)
    {
        if(a[indecator] > b[indecator])
        {
            Comp_Arr[0] += 1;
        }
        else if(a[indecator] < b[indecator])
        {
            Comp_Arr[1] += 1;
        }
    } 
    return Comp_Arr_ptr;
   
}
int main(void)
{
    int result_count;
    int* result = compareTriplets(3, a, 3, b);

    for (int i = 0; i < 2; i++) 
        {
            printf("%d", *(result + i));

            if (i != 1) 
            {
                printf(" ");
            }  
        } 
    return 0;
}
