int* missingNumbers(int arr_count, int* arr, int brr_count, int* brr, int* result_count) 
{
    int *fq = (int*)calloc(100, sizeof(int));
    
    int *result = (int*)malloc(sizeof(int)*100);

    int i = 0;
    int j = 0;
    int k = 0;
    int maximum = 0;
    /* 
        first caculate the maximum nubmer on array brr
    */
    for(int x = 0; x < brr_count; x++)
    {
        if(brr[x] > maximum)
        {
            maximum = brr[x];
        }    
    }
    /*
        increase number of elements which frequante on brr
    */
    for(i  = 0; i < brr_count; i++)
    {
        fq[maximum - brr[i]]++;
    }
    /*
        decrease number of elements which frequnate on original array (brr)
    */
    for(i  = 0; i < arr_count; i++)
    {
        fq[maximum - arr[i]]--;
    } 
    /*
        if any elemnet of frq arr is greater than 0,
        then it is not included on arr
    */
    for(k  =  99; k >= 0; k--)
    {
        if(fq[k] > 0)
        {
            result[j++] = maximum - k;
        }
    }
    *result_count = j;
    return result;
}