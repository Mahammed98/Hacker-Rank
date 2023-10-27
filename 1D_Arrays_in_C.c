#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long int Number, Iterate, Sum = 0;
    long int * ptr;
    scanf("%ld", &Number);
    ptr = (long int *)malloc(sizeof(long int) * Number);

    if(ptr == NULL)
    {
        printf("heap is full");
    }
    else
    {
        for(Iterate = 0; Iterate < Number; Iterate++)
        {
            scanf("%ld", &ptr[Iterate]);
        }
        for(Iterate = 0; Iterate < Number; Iterate++)
        {
            Sum = Sum + ptr[Iterate];
        }
        printf("%d", Sum);
    }
    return 0;
}
