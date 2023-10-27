#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int n, i;
    printf("enter the number: ");
    scanf("%d", &n);
    
    char *ptr = (char*)malloc( sizeof(char) * n);
    if(ptr == NULL)
    {
        printf(" no space");
    }
    else 
    {
        for(i = 0; i < n; i++)
        {
         scanf("%c", &ptr[i]);
        }
        for( i = 0; i < n; i++)
        {
        printf("%c", ptr[i]);
         }
        printf("\n");
        int z = n / 2;

        ptr = (char *)realloc(ptr, z);

        for( i = 0; i < n; i++)
        {
            printf("%c", ptr[i]);
        }
        printf("\n%d",sizeof(ptr));
    }
     
     free(ptr);
     return 0;
}