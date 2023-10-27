#include<stdio.h>
#include<stdlib.h>
#include <string.h>


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


    for(int i = 0; i < n; i++)
        printf("%d\n", count_dist(arr[i]));
    printf("\n");
  }
