#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    char ch;
    char s[30];
    char sen[50];
    char ch_sen;
    int i;

        scanf("%c", &ch);
        scanf("%s", s);
        getchar();          // we used this function to clear the buffer of stdin
                            // we also can use scanf("\n"); or fflush(stdin);
        gets(sen);
        printf("%c\n", ch);
        printf("%s\n", s);
        puts(sen);
        //printf("%s", sen);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
