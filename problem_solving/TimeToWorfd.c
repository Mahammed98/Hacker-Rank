/*
Function Description

Complete the timeInWords function in the editor below.

timeInWords has the following parameter(s):

int h: the hour of the day
int m: the minutes after the hour
Returns

string: a time string as described
Input Format

The first line contains , the hours portion The second line contains , the minutes portion

Constraints
*************************************************************************
Sample Input 0

5
47
Sample Output 0

thirteen minutes to six
Sample Input 1

3
00
Sample Output 1

three o' clock
Sample Input 2

7
15
Sample Output 2

quarter past seve

**************************************************************************
*/



char* timeInWords(int h, int m) 
{
    static char arr[35];
    char * numbers[]= {"o' clock","one ","two ","three ","four ","five ","six ", "seven ","eight ","nine ",
    "ten ","eleven ", "twelve ", "thirteen ","quarter ","fifteen ","sixteen ","seventeen ","eighteen ",
    "ninteen ","twenty ", "twenty one ","twenty two ","twenty three ", "twenty four ", "twenty five ", 
    "twenty six ", "twenty seven ", "twenty eight ", "twenty nine ", "half "};
    
    if(m == 0)
    {
        strcat(arr,numbers[h]);
        strcat(arr, numbers[m]);
    }
    else if(m == 30)
    { 
        strcat(arr,"half past " );
        strcat(arr, numbers[h]);
    }
    else if(m == 15)
    {
        strcat(arr,"quarter past ");
        strcat(arr, numbers[h]);
    }
    else if(m == 45)
    {
        strcat(arr,"quarter to ");       
        strcat(arr, numbers[h+1]);
    }
    else if(m < 30)
    {   
        strcat(arr,numbers[m]);
        if(h == 1)
        {
            strcat(arr, "minute past ");
        } 
        else 
        {
            strcat(arr, "minutes past ");
        }        
        strcat(arr, numbers[h]);

    }
    else if(m > 30)
    {
        strcat(arr, numbers[60-m]);
        strcat(arr, "minutes to ");
        strcat(arr, numbers[h+1]);
    }
    return arr;
}