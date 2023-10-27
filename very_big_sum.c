#include<stdio.h>
#include<stdlib.h>
int diagonalDifference(int arr_rows, int arr_columns, int** arr) 
{
    int primar_diagonal = 0, secondary_diagonal = 0;
    int sum = 0;
    char Raw, columns;
    
    for(Raw = 0, columns = 0; Raw < arr_rows; Raw++,columns++)
    {
        primar_diagonal += arr[Raw][columns];
       // printf("the elements: %d \n",primar_diagonal);
    }
    for(Raw = 0 , columns = arr_columns - 1; Raw < arr_rows; Raw++,columns--)
    {
        secondary_diagonal += arr[Raw][columns];
       // printf("the elements: %d \n",secondary_diagonal);
    }
    return abs(primar_diagonal - secondary_diagonal);
}
int main()
{
    int n;
    printf("%s","enter the number of array elements: ");
    scanf("%d", &n);
     
     int** arr = malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++)
     {
        *(arr + i) = malloc(n * (sizeof(int)));
     }
     for(int i =  0; i < n; i++)
        for(int j = 0; j < n; j++)
            arr[i][j] = j * 2;

    int result = diagonalDifference(n, n, arr);
    printf("\n the result: %d", result);

    //for (int i = 0; i < n; i++)
       // free(arr + i);
    free(arr);
    return 0;

}