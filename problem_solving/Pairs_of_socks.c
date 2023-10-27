#include "stdio.h"
#include "stdlib.h"

 void Bubble_Sort(int *, int);

int sockMerchant (int *, int);
int main()
{
    
    int number_of_elements;
    int indicator;
    scanf("%d", &number_of_elements);
    int *ptr = (int *)malloc(number_of_elements * sizeof(int));
    
    for (indicator = 0; indicator < number_of_elements; indicator++)
    {
        scanf("%d", &ptr[indicator]);
    }
    Bubble_Sort(ptr, number_of_elements);
    printf("%d", sockMerchant(ptr, number_of_elements));
    free(ptr);
    return 0;
}

// bubble sort function

void Bubble_Sort(int * a, int n)
{
    int i = 0, j = 0, tmp;

    for (i = 0; i < n; i++)
        {   // loop n times - 1 per element
          for (j = 0; j < n - i - 1; j++)
            { // last i elements are sorted already
              if (*(a+j) > *(a+j+1))
                 {  // swap if order is broken
                    tmp = *(a+j);
                    *(a+j) = *(a+j+1);
                    *(a+j+1) = tmp;
                 }
            }
        }
} // end function

int sockMerchant (int * Arr, int Number_Of_Socks)
{
    int Indicator_First_Loop;
    int Pairs_Of_Socks = 0;
    
    for(Indicator_First_Loop = 0; Indicator_First_Loop < Number_Of_Socks - 1;)
    {
                                            
        if( Arr[Indicator_First_Loop] == Arr[Indicator_First_Loop + 1])
        {   
            //if we found 2 pairs of socks 
            Pairs_Of_Socks++;
            Indicator_First_Loop += 2;
        }
        else 
        {
            Indicator_First_Loop++;
        }
    }
    return Pairs_Of_Socks;
} // end function 


/*int sockMerchant (int * Arr, int Number_Of_Socks)
{
    int Indicator_First_Loop, Indicator_Seconde_Loop;
    int Socks_Counter = 1;
    int Pairs_Of_Socks = 0;
    
    for(Indicator_First_Loop = 0; Indicator_First_Loop < Number_Of_Socks; Indicator_First_Loop++)
    {
        for(Indicator_Seconde_Loop = Indicator_First_Loop; Indicator_Seconde_Loop < Number_Of_Socks; Indicator_Seconde_Loop++)
        {
            if(Arr[Indicator_First_Loop] == Arr[Indicator_Seconde_Loop + 1])
            {
                Socks_Counter++;
            }
        }
        if(Socks_Counter % 2 == 0)
        {
            Pairs_Of_Socks += (Socks_Counter / 2);
        }
        else if( Socks_Counter > 2)
        {
            Pairs_Of_Socks += ((Socks_Counter - 1)/ 2);
        }
        else 
        {
            //no action 
        }
        Socks_Counter = 1;  // reset counter
    }
    return Pairs_Of_Socks;
}*/
