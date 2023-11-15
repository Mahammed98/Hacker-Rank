/*
    Given a string, remove characters until the string is made up of any two alternating characters. 
    When you choose a character to remove, all instances of that character must be removed. D
    etermine the longest string possible that contains just two alternating letters.

Example
s = abaacdabd
Delete a, to leave bcdbd. Now, remove the character c to leave the valid string bdbd with a length of 4.
 Removing either b or d at any point would not result in a valid string. Return 4.

Given a string s, convert it to the longest possible string t made up only of alternating characters. Return the length of string t. 
If no string  tcan be formed, return 0.

*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int twochar(char *);
int main(void)
{
    char st[200];
    int i = 0;
    printf("Pleas enter the string : ");
    scanf("%s", st);
    printf("%d\n", twochar(st));
    return 0;
}
int alternate(char* s) 
{
    int str = strlen(s);
    int CounterOfUniqeChar = 0;
    int CounterOfAlternatingChar = 0;
    int maximum = 0;
    int flag = 0;
    int i = 0, j  = 0,k = 0;
    int *Fq = (int *)calloc(27, sizeof(int));
    // calculate frequancy of each character
    for(i = 0; i < str; i++)
    {
        Fq[s[i]-97]++;
    }
    char * ptr =(char*)malloc(sizeof(char));
    for(i = 0; i < 27; i++)
    {
        if(Fq[i] > 0)
        {
            CounterOfUniqeChar++;
            ptr = (char*)realloc(ptr, CounterOfUniqeChar+1);
            ptr[j++] = (i+97);
        }
    }
     // creating alternating characters array
    static char result[1000] = {0};
    //compaedr each two string of alternating array to main array(main string s)
    for(i = 0; i < CounterOfUniqeChar - 1; i++)
    {
        for(k = i+1; k < CounterOfUniqeChar; k++)
        {
           for(j = 0; j < str; j++)
            {
                if(ptr[i] == s[j] || ptr[k] == s[j])
                {
                    result[CounterOfAlternatingChar++] = s[j];
                }
            }
            // check if we have two repeated characters
            for( j = 0; j < CounterOfAlternatingChar; j++)
            {
                if(result[j] == result[j+1])
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
            {
                flag = 0;
            }
            else 
            {   
                if(maximum < CounterOfAlternatingChar)
                {
                    maximum  = CounterOfAlternatingChar;
                }
            }
            CounterOfAlternatingChar = 0;
        }
        
    }
    return maximum;
     
}