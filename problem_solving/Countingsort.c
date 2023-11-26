int* countingSort(int arr_count, int* arr, int* result_count) 
{
   /*
        counting sort need one more array to put frequancy of each element
        of the original array
        
        first: creat loop to calculate the maximum number in the array
        seconde: creat another array, ant calculate frq of each element
        third: 
        


        Note: this counting sort only used with numbers only
        
    */
    *result_count = arr_count;   
    int _ORDER_OF_ELEMENT_IN_ORIGINAL_ARRAY_ = 0;
    int *fq = (int *)calloc(100, sizeof(int));
    
    for(long long int i = 0; i < arr_count; i++)
    {
        fq[arr[i]]++;
    }
    for(int _ORDER_OF_ELEMENT_IN_FRQ_ARRAY_ = 0; _ORDER_OF_ELEMENT_IN_FRQ_ARRAY_ < 100; _ORDER_OF_ELEMENT_IN_FRQ_ARRAY_++) // here we a have 100, which is a maximum number on the array 
        // if we donot no the max make a for loop to find it , and replace number 100 with it 
    {   
        while(fq[_ORDER_OF_ELEMENT_IN_FRQ_ARRAY_]--)
        {
            arr[_ORDER_OF_ELEMENT_IN_ORIGINAL_ARRAY_++] = _ORDER_OF_ELEMENT_IN_FRQ_ARRAY_; // modify original array by sorting elements 
        }
        
    }
    return arr;
}