#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.
/*
    This funtion used to caculat the maximum value of in each three bitwise operator
  AND , OR, XOR  we passing two integer number but must n greater than k or equal  to enter a function

  a b   and or xor
  1 2   0   3  3
  1 3   1   3  2
  2 3   2   3  1

Max_And =  2
Max_Or  =  0
Max_Xor =  2

*/
void calculate_the_maximum(int n, int k) {
  //Write your code here.
  int Frist_Number, Seconde_Number, Max_And = 0, Max_Or = 0, Max_Xor = 0 ;
  for (Frist_Number = 1; Frist_Number <= k; Frist_Number++)
  {
      for (Seconde_Number = Frist_Number+1; Seconde_Number <= n; Seconde_Number++)
      {
          if(((Frist_Number & Seconde_Number) < k) & ((Frist_Number & Seconde_Number) > Max_And))
            {
                Max_And = Frist_Number & Seconde_Number;
            }
          if(((Frist_Number | Seconde_Number) < k) & ((Frist_Number | Seconde_Number) > Max_Or))
            {
                Max_Or = Frist_Number | Seconde_Number;
            }
          if(((Frist_Number ^ Seconde_Number) < k) & ((Frist_Number ^ Seconde_Number) > Max_Xor))
            {
                Max_Xor = Frist_Number ^ Seconde_Number;
            }
      } // end seconde for loop

  } // end first for loop
  printf("%d\n%d\n%d",Max_And, Max_Or, Max_Xor);
}


int main() {
    int n, k;

    scanf("%d %d", &n, &k);
    if  ( n >= k)
    {
        calculate_the_maximum(n, k);
    }
    else
    {
        printf("Wrong Number");
    }
    return 0;
}
