#include <stdio.h>
#include <stdlib.h>

/*
    Manasa is out on a hike with friends. She finds a trail of stones with numbers on them. 
    She starts following the trail and notices that any two consecutive stones' numbers differ by one of two values.
    Legend has it that there is a treasure trove at the end of the trail. If Manasa can guess the value of the last stone, the treasure will be hers.

TDIN   Function
-----   --------
2       T = 2 (test cases)
3       n = 3 (test case 1)
1       a = 1
2       b = 2
4       n = 4 (test case 2)
10      a = 10
100     b = 100

Sample Output
2 3 4 
30 120 210 300 

Explanation:
With differences 1 and 2, all possible series for the first test case are given below:

0,1,2
0,1,3
0,2,3
0,2,4
Hence the answer 2 3 4.

With differences 10 and 100, all possible series for the second test case are the following:

0, 10, 20, 30
0, 10, 20, 120
0, 10, 110, 120
0, 10, 110, 210
0, 100, 110, 120
0, 100, 110, 210
0, 100, 200, 210
0, 100, 200, 300
Hence the answer 30 120 210 300.

*/
void stones(int n, int a, int b);
int cmp(const void  *x, const void  *y);

int main()
{
    int n , a, b;
    int *ar;
    int testcases = 0;
    printf("enter number of test cases : ");
    scanf("%d", &testcases);
    while(testcases--)
    {
        printf("enter number of stones : ");
        scanf("%d", &n);
        printf("enter dif 1 : ");
        scanf("%d", &a);
        printf("enter dif 2 : ");
        scanf("%d", &b);

        stones(n, a, b);  // call function 
    }
    
}
/////////////////////////////////////////////////////////////////////////////////////////
void stones(int n, int a, int b)
{
    static int arr[1000] = {0}; //1000 is max number of n (condition)
    int i , j;
    int k = 0;
    int number = 0;
    for(i = 0; i < n; i++)
    {
        number = (b*i) + (a*(n-i-1));
        if(number == arr[k-1])  // if same number is existing 
        {
            continue;
        }
        else  // new number 
        {
            arr[k++] = number;
        }
    }
    qsort(arr, k, sizeof(int),cmp);
    /*
        print array (final result)
    */
    for(int i = 0; i < k; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

} // end function 
int cmp(const void  *x, const void  *y)
{
    return (*(int *)x - *(int *)y);
}
