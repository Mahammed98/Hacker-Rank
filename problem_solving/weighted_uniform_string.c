#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void weightedUniformStrings(unsigned char* , unsigned int , unsigned int*, unsigned int );

int main()
{
    unsigned char string_arr[100000];
    unsigned int Number_Of_Q_elements, i = 0;
    unsigned int *Ptr_Queries;

     scanf("%s", string_arr);
 
    fflush(stdin);
    scanf("%d", &Number_Of_Q_elements);
    fflush(stdin);
    Ptr_Queries = (unsigned int *)malloc(sizeof(int) * Number_Of_Q_elements);

    for( i = 0; i < Number_Of_Q_elements; i++)  // input string
    {
        scanf("%d", &Ptr_Queries[i]);
    }// end loop

    int len = strlen(string_arr); 
    weightedUniformStrings(string_arr, Number_Of_Q_elements, Ptr_Queries, len);
    free(Ptr_Queries);
}

/////////////////////////////  function  ////////////////////////////////////////
void weightedUniformStrings(unsigned char* s, unsigned int queries_count, unsigned int* queries, unsigned int len) 
{
    unsigned int iteration = 0, result = 0, j = 0;
    unsigned int *ptr_result = (unsigned int *)malloc(sizeof(int) * len);

    while(s[iteration])
    {
        if(s[iteration] == s[iteration + 1])
        {
            result += (s[iteration] - 96);
            ptr_result[j] = result;
        }// end if
        else 
        { 
            result += (s[iteration] - 96);  // we subtracte -96 because s will only contain lowercase English letters, ascii[a-z].
            ptr_result[j] = result;
            result = 0; // reset result 
        }
        j++;
        iteration++;
    }// end while loop

    /*
        this for loop to compare the final result to queries result 
    */
   for( iteration = 0; iteration < queries_count; iteration++)
   {
        for (j = 0; j < len; j++)
        {
            if(queries[iteration] == ptr_result[j])
            {
                printf("Yes\n");
                break;
            }
        }// end seconde loop

        if( j == len)       // if donot match elements 
        {
            printf("No\n");
        } // end if
   }// end for loop
}