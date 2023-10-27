#include<stdio.h>
#include<stdlib.h>

/* 
    this function used to calculate number of digits
*/
int number_of_digit(int number)
{
    int n = 0;
    while(number)
    {
        number /= 10;
        n++;
    }
    return n;
}// end function

/* 
    this function used to calculate number of tens
*/

int tens_fun(int n)
{
    int ten = 1;
    while(n)
    {
        ten *= 10;
        n--;
    }
    return ten;
}// end function
  
void kaprekarNumbers(int p, int q)
{
    int digit_p;
    long long int number;
    int ten_p;
    long long int result1 = 0, result2 = 0;
    char flag = 0;
    //       i = 297
    for ( long int i = p; i <= q; i++)
    {
        // nubmer of digits in right side of square number must be equal to the number of digits in real number (i)
        digit_p = number_of_digit(i);   
        number  = i * i;   // squar of number 
        ten_p  = tens_fun(digit_p); 

        result1 = number / ten_p;  // left side
        result2 = number % ten_p;   // right side 
        
        
        if((result1 + result2) == i)
        {
            flag = 1;
            printf("%ld ", i);
        } 
    }
    /* if we didnot find any number in the interval */
    if(!flag)  
    {
        printf("INVALID RANGE");
    }
}

int main()
{       
    int n1 = 100, n2 = 300; 
    kaprekarNumbers(n1, n2);
    return 0;
}