#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int **M_2D_Array(int );

int main()
{
  int _Number_, i, _end_, _start_, _Size_, Raw, Colom;

  scanf("%d", &_Number_);

  int **ptr;
  _Size_ = _Number_*2 - 1;
  _start_ = 0;
  _end_ = _Size_ - 1;

  ptr = M_2D_Array(_Size_);


/*
                  4 4 4 4 4 4 4
                  4 3 3 3 3 3 4
                  4 3 2 2 2 3 4
                  4 3 2 1 2 3 4
                  4 3 2 2 2 3 4
                  4 3 3 3 3 3 4
                  4 4 4 4 4 4 4
*/
    while(_Number_ != 0)
    {
      for (Raw = _start_; Raw <= _end_; Raw++)
      {
          for (Colom = _start_; Colom <= _end_; Colom++)
          {
              if((Raw == _start_ )|| (Raw == _end_) || (Colom == _start_) || (Colom == _end_))
              {
                  ptr[Raw][Colom] = _Number_;
              } // end condition

          } // end seconde loop

      } // end first loop
      _Number_--;
      _start_++;
      _end_--;
    } // end while loop
/*
  print array
*/
    for (Raw = 0; Raw < _Size_; Raw++)
    {
        for (Colom = 0; Colom < _Size_; Colom++)
        {
            printf("%d ", ptr[Raw][Colom]);

        } // end seconde loop
        printf("\n");

    } // end first loop

  	// Complete the code to print the pattern.

    for(i = 0; i < _Number_; i++)
    {
        free(ptr[i]);
        ptr[i] = NULL;
    }// end for loop

    free(ptr);
    ptr = NULL;


    return 0;

}

/*
 This function used to allocate 2D array dynamically
 we passing 1 parameter which is the size of array
 and it is return the addres of the allocate space
 */
int **M_2D_Array(int _Size_)
{
    int **arr ,i ;
    arr = (int **) malloc(sizeof(int *) * _Size_);

      for(i = 0; i < _Size_ ; i++)
      {
          arr[i] = (int *) malloc(sizeof(int) * _Size_);
      }// end for loop
      return arr;

}
