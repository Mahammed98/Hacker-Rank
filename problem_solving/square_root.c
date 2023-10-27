
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* this is another code but taling larg excution time  
int squares(int a, int b) 
{
    int result = 0;
    for( double i = a ; i <= b; i++)
    { 
        if ((powf(i, 0.1f/0.2f) - (int)powf(i, 0.1f/0.2f)) == 0) 
        {
            result++;
        }
    }
    return result;
}
*/
int squares(int a, int b) 
{
    int result = 0;
    for( int i = sqrt(a); i <= sqrt(b); i++)
    { 
        if((i*i) >= a && (i*i) <= b )
        {
            result++;
        }
    }
    return result;
}
int main ()
{
    int q, x, y;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &x);
        scanf("%d", &y);
        printf("%d\n", squares(x, y));
    }
    return 0;
}
