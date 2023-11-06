#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    The encoded message is obtained by displaying the characters of each column, with a space between column texts. The encoded message for the grid above is:

    imtgdvs fearwer mayoogo anouuio ntnnlvt wttddes aohghn sseoau

    Create a function to encode a message.
*/
char * encryption(char *);

int main(void)
{
    char str [81];
    char * ptr;
    scanf("%s", str);
    ptr = encryption(str);

    for(int i = 0; i < strlen(ptr); i++)
    {
        printf("%c", ptr[i]);
    }
    return 0;

}

char* encryption(char* s) 
{
    int LenghtWithoutSpaces = 0;
    double LenghtRoot = 0.0;
    int Rows, Colums;
    int x = 0;
    int y = 0;
    int ColumsCount = 0;
    int RowsCount = 0;
    int flag = 0;
    static char result [81]  ={0};
    /*
        first calculate numbers of charactar on string without any spaces
    */
    
    LenghtWithoutSpaces = strlen(s);
    LenghtRoot = sqrt(LenghtWithoutSpaces);
    Rows = LenghtRoot;
    Colums = LenghtRoot;
    /*
        calculating the minimum area (row * colums must larger or equal to string length)
    */
    while((Rows * Colums) < LenghtWithoutSpaces)
    {
        if(flag % 2== 1)
        {
            Rows++;
            flag++;
        }
        else 
        {
            Colums++;
            flag++;
        }
    }

    while(ColumsCount != Colums)
    {
        while(RowsCount != Rows)
        {
            if((s[y]!= 32) && ((s[y] < 97) || (s[y] > 122)))
            {
                RowsCount++;
                continue;
            }
            result[x++] = s[y];
            y += Colums;
            RowsCount++;
        }
        result[x++] =' '; 
        ColumsCount++;
        y = ColumsCount;
        RowsCount = 0;
    }
    return result;
}