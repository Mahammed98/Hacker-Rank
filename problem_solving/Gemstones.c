/*
There is a collection of rocks where each rock has various minerals embeded in it. 
Each type of mineral is designated by a lowercase letter in the range . There may be multiple occurrences of a mineral in a rock. A mineral is called a gemstone if it occurs at least once in each of the rocks in the collection.

Given a list of minerals embedded in each of the rocks, 
display the number of types of gemstones in the collection.

*/


int cmp (const void * a, const void * b)
{
    return *(char *)a - *(char *)b;
}
///////////////////////////////////////////////////////////////
int gemstones(int arr_count, char** arr) 
{
    int counter = 0;
    int * fq = (int *)calloc(27, sizeof(int));
   
    // caculating the frequance of each element in all strings
    for(int i = 0; i < arr_count; i++)  
    {
        qsort(arr[i], strlen(arr[i]), sizeof(char), cmp);     // sorting each array of string
        for(int j = 0; j < strlen(arr[i]); j++) // j = 0, strlen = 6
        {
            if(arr[i][j] == arr[i][j+1]) 
            {
                continue; // if 2 elements behinde each other are the same  
            }
            else
            {
                fq[arr[i][j] - 97]++;     
            }
        }
    }
    for(int k = 0; k < 27; k++)
    {
        /*
            if any element exists in all strings, then counter++      
        */
        if(fq[k] == arr_count)
        {
            counter++;
        }
    }   
    return counter;
}