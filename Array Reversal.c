#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i, Temp;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++)
    {
        scanf("%d", arr + i);
    }
    for(i = 0; i < (num/2); i++)
     {
         Temp = arr[i];
         arr[i] = arr[num - 1 - i];
         arr[num - 1 - i] = Temp;

     }

    /* Write the logic to reverse the array. */

    for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}
