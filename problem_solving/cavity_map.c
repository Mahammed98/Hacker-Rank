#include <stdio.h>
#include <stdlib.h>
#include<string.h>

char **cavityMap(int , char **);

int  main()
{
    int number_of_element_matrix, i, j;
    char *arr1[100];  // array of pointer == char **arr1
    char temp[100];  
    int ch;
    
    scanf("%d", &number_of_element_matrix);
    
    /* append array */
    
    for(i = 0; i < number_of_element_matrix; i++)
    {
        scanf("%s", temp);
        arr1[i] = (char *)malloc(sizeof(char) * (strlen(temp)+1));
        strcpy(arr1[i] , temp);
    }
    
    
    char **result = cavityMap(number_of_element_matrix, arr1);
    
    for(i = 0; i < number_of_element_matrix; i++)
    {
        for (j = 0; j < number_of_element_matrix; j++)
        {
             printf("%c", result[i][j]);    
        }
        printf("\n");
    }
    return 0;
}

char** cavityMap(int grid_count, char** grid)
{
        int indicator_1, indicator_2;
        char ** returned_value;
        returned_value = grid;
        /* we canceld a first and last raw and column cuz border 
           (if this cell is not on the border)
        */
        for(indicator_1 = 1; indicator_1 < grid_count - 1; indicator_1++)
        {
            for (indicator_2 = 1; indicator_2 < grid_count - 1; indicator_2++)
            {        
                 if((grid[indicator_1][indicator_2] > grid[indicator_1][indicator_2 - 1]) && (grid[indicator_1][indicator_2] > grid[indicator_1][indicator_2 + 1]) && (grid[indicator_1][indicator_2] > grid[indicator_1 + 1][indicator_2]) && (grid[indicator_1 - 1][indicator_2 ] < grid[indicator_1][indicator_2 ]))
                {
                    returned_value[indicator_1][indicator_2] = 'X';
                }
            }
        }
        return returned_value;
}