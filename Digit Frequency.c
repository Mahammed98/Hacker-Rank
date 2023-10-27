#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char arr[500];
    char ch = 48;  // start from zero 48 -> 0
    int i = 0, counter = 0;
    scanf("%s", arr);
    /*
        Main loop for search the digits from 0 to 9
        ends when  ch equal to next sempol after 9 in ASC||
        */
    while (ch != 58)
    {
        /*
            search each number in arr
        */
        while (arr[i] != NULL)
      {
          if(arr[i] == ch)
          {
             counter++;
          }
          else
          {
              // no action needed
          }
          i++;
      }
       ch++;
       printf("%d ", counter);
       /*
         reset iteration and counter
         */
       i = 0;
       counter = 0;
    } // end main loop
    return 0;
}
