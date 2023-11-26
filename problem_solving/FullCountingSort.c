
/*
    https://www.youtube.com/watch?v=pEJiGC-ObQE : counting sort understand

*/

void countSort(int arr_rows, int arr_columns, char*** arr) 
{
    int i = 0;
    int j = 0;
    int _INTEGER_VALUE_;
    int _ORDER_OF_ELEMENT_IN_ORIGINAL_ARRAY_ = 0;
    int *fq = (int *)calloc(100, sizeof(int)); // we know the max number = 100
    /*
        first: creat new array to set sorting values on it 
    */
    char ***ptr = (char ***)calloc(arr_rows, sizeof(char**));
    for(int k = 0; k < arr_rows; k++)
    {
        ptr[k] = (char**)calloc(2, sizeof(char*));
        ptr[k][0] = (char*)calloc(100,sizeof(char));
        ptr[k][1] = (char*)calloc(27,sizeof(char));

    }
    /*
        second: convert first half of array to '-'
    */
    for(i = 0; i < (arr_rows/2); i++)
    {
        arr[i][1][0] = '-';
        arr[i][1][1] = '\0';
    }
    /*
        third: calculate the frequancy for each number on array
    */
    for(i = 0; i < arr_rows; i++)
    {
        _INTEGER_VALUE_ = atoi(arr[i][0]);  // convert string of numbers to integer
        fq[_INTEGER_VALUE_]++;
    }
    /*
        updating the freq array 
    */
    for(i = 1; i <= arr_rows; i++)
    {
        fq[i] += fq[i-1];
    }
    
    /*
        fourth: sorting array
    */
    for(j = arr_rows - 1; j >= 0; j--)
    {
        _INTEGER_VALUE_ = atoi(arr[j][0]);  // convert string of numbers to integer
        ptr[--fq[_INTEGER_VALUE_]] = arr[j];
    }
    // finally print array 
    for (int k = 0; k < arr_rows; k++)
    {
        printf("%s ", ptr[k][1]);
    }
}
