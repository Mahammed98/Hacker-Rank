/*
    Reduce a string of lowercase characters in range ascii[‘a’..’z’]by doing a series of operations. 
    In each operation, select a pair of adjacent letters that match, and delete them.       
    Delete as many characters as possible using this method and return the resulting string. 
    If the final string is empty, return Empty String
    Sample Input 0
        aaabccddd

    Sample Output 
        abd

    ************Explanation************
    Perform the following sequence of operations to get the final string:

    aaabccddd → abccddd → abddd → abd
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void ShiftElements(char * arr, int *len, int x);

int main()
{
    char s[10];
    printf("Enter the string : ");
    scanf("%s", s); // input string 
    int i = 0;
    int str = strlen(s);


    while(s[i] != '\0')
    {
        if(s[i] == s[i+1])
        {
            s[i] = '0';
            s[i+1] = '0';
            ShiftElements(s, &str, i);
            i = -1; // reste iteration (return to start of the array after each shift operation)
        }
        else
        {
            //nothing
        }
        i++;
        
    }
}
/*
    this function depend on shift two poisions which were replaced by two similar characters 
*/
void ShiftElements(char * arr, int *len, int x)
 {
    for (int y = x+2; y < *len; y++)
    {
       arr[x] = arr[y];
       x++;
    }
    arr[x] = '\0'; // put null terminator at the end of string
    *len  = x; // return new length of the array after shifting    
 }