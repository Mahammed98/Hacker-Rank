#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  this function ussed to calcolate the number unique charactes on string
  */
 int count_dist (const char* a)
{

    int hash[128] = { 0 };
    int i, c = 0;

    // reading each character of str[]
    for (i = 0; i < strlen(a); ++i) {
        // set the position corresponding
        // to the ASCII value of str[i] in hash[] to 1
        hash[a[i]] = 1;
    }

    // counting number of unique characters
    // repeated elements are only counted once
    for (i = 0; i < 128; ++i) {
        c += hash[i];
    }

    return c;
}

/*
  return 0 if two stings are equels
  return -1 if first string is less than seconde string
  return 1 if first string is greater  than seconde string
   */

  int lexicographic_sort(const char* a, const char* b)
{
    return strcmp(a,b);
}

int lexicographic_sort_reverse(const char* a, const char* b)
{
        return strcmp(b,a);
}

/*
  to sort the strings in non-decreasing order of the number of distinct characters present in them.
  If two strings have the same number of distinct characters present in them,
  then the lexicographically smaller string should appear first.
  */
int sort_by_number_of_distinct_characters(const char* a, const char* b)
{
    int i = 0;
    int result = -1;
    int count_first_string = count_dist(a);
    int count_second_string = count_dist(b);


        if(count_first_string == count_second_string)
        {
           // printf("come to function\n");
            result = lexicographic_sort(a, b);
        }
        else if (count_first_string > count_second_string)
        {
            result = 1;
        }


    return result;

}
/*
  to sort the strings in non-decreasing order of their lengths.
  If two strings have the same length,
   then the lexicographically smaller string should appear first.
   */

int sort_by_length(const char* a, const char* b)
{
    int result = strlen(a) - strlen(b) ;

    if(result == 0)
    {
        result = lexicographic_sort(a, b);
    }
    else if (result > 0)
    {
        result = 1;
    }

   return result;
}


/*
  this function using bubble sort algotithem

  */
void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    char * temp ;
    int i, j;

    for(i = 0; i < len; i++)
        for(j = 0; j < len - 1 ; j++)
        {
            if(((*cmp_func)(arr[j], arr[j+1])) > 0)
                {
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
        }
}


int main()
{
    int n;
    scanf("%d", &n);

    char** arr;
	arr = (char**)malloc(n * sizeof(char*));

    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }

    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");
}
