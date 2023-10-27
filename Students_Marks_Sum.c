#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
You are given an array of integers denoting the marks scored by students in a class.
The alternating elements, and so on denote the marks of boys.
Similarly, and so on denote the marks of girls.
*/

//Complete the following function.


int marks_summation(int* marks, int number_of_students, char gender) {
  //Write your code here.
  int student;
  int sum = 0;
  if (gender == 'b')
  {
      for (student = 0; student < number_of_students; student += 2)
      {
          sum += marks[student];
      }

  }
  else if(gender == 'g')
  {
      for (student = 1; student < number_of_students; student += 2)
      {
          sum += marks[student];
      }
  }
  else
  {
      printf("Wrong character : \n");
  }
  return sum;
}

int main() {
    int number_of_students;
    char gender;
    int sum;

    scanf("%d", &number_of_students);
    int *marks = (int *) malloc(number_of_students * sizeof (int));

    for (int student = 0; student < number_of_students; student++) {
        scanf("%d", (marks + student));
    }

    scanf(" %c", &gender);
    sum = marks_summation(marks, number_of_students, gender);
    printf("%d", sum);
    free(marks);

    return 0;
}
