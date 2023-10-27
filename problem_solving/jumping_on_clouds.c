#include<stdio.h>
#include<stdlib.h>

int jumpingOnClouds(int c_count,   int* c, int k) 
{
   int i = 0; 
   int Energy = 100;  // intial energy to 100
   
   while(1)
   {
       i = (i + k) % c_count;
       
       if (i)   // if i positive (not reached to start point) 
       {
           if(c[i] == 1)
           {
               Energy = Energy - 3;
           }// end if 
           
           else 
           {
               Energy--;
           } // end else
           
       } // end if 
       
       else  // if reached to start point 
       {
           if(c[0] == 1)  // if start point has thundercloud
           {
               Energy = Energy - 3;
           }
           else 
           {
              Energy--; 
           }       
           break;  // exit from while loop
       } // end else 
   }
   return Energy;
}

int main ()
{
    int c, k, result;
     
    scanf("%d", &c);
    scanf("%d", &k);
    
    int *ptr = (int *)malloc(sizeof(int) * c);
    
    for(int i = 0; i < c; i++)
    {
        scanf("%d", &ptr[i]);
    }
   result =  jumpingOnClouds(c, ptr, k);
   
   printf("%d", result);

}