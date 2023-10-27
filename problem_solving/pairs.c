/*
Given an array of integers and a target value, determine the number of pairs of array elements that have a difference equal to the target value.

Example

There are three values that differ by k = 1: 2-1 = 1, 3-2 = 1, and 4-3 = 1. Return 3

*/


int cmp(const void* a, const void* b)
{
    return *(int *)a - *(int *)b;
}
int pairs(int k, int arr_count, int* arr) 
{
    int counter = 0;
    int j  = arr_count -2;
    qsort(arr, arr_count, sizeof(int), cmp);
    
    for(int i = arr_count - 1; i > 0; i--)
    {
       for(j = i-1; j >= 0; j--)
       {
           if(arr[i] - arr[j] == k)
           {
               counter++;
               break;
           }
       }
    }
    return counter;

}