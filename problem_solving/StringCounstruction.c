/*
    Amanda has a string of lowercase letters that she wants to copy to a new string. 
    She can perform the following operations with the given costs. She can perform them any number of times to construct a new string :

    Append a character to the end of string p at a cost of 1 dollar.
    Choose any substring of p and append it to the end of p at no charge.
    Given  n strings s[i], find and print the minimum cost of copying each s[i] to p[i] on a new line.

    For example, given a string s= abcabc, it can be copied for  3 dollars. Start by copying a, b
    and c individually at a cost of 1 dollar per character. String p = abc at this time. Copy  p[0:2] to the end of p at no cost to complete the copy.

    Function Description


    Sample Input
    2
    abcd
    abab

    Sample Output
    4
    2


*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int stringConstruction(char* s);
int main (void)
{
    char s[100000];
    scanf("%s", s);
    printf("%d \n",stringConstruction(s));
    return 0;

}

int stringConstruction(char* s) 
{
    int Counter = 0;
    int *fq = (int *)calloc(26, sizeof(int));
    
    for(int i = 0; i < strlen(s); i++)
    {
        ++fq[s[i] - 97];
    }
    for(int i = 0 ; i < 26; i++)
    {
        printf("%d ", fq[i]);
    }
    printf("\n");
    for(int j = 0; j < 26; j++)
    {
        if(fq[j] != 0)
        {
            Counter++;
        }
    }
    return Counter;
    
}