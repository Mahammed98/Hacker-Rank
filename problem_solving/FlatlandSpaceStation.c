/*
    Flatland is a country with a number of cities, some of which have space stations. 
    Cities are numbered consecutively and each has a road of  length connecting it to the next city. It is not a circular route, 
    so the first city doesn't connect with the last city. Determine the maximum distance from any city to its nearest space station

STDIN   Function
-----   --------
5 2     n = 5, c[] size m = 2
0 4     c = [0, 4]
Sample Output 0
2

Explanation 0

This sample corresponds to following graphic:


The distance to the nearest space station for each city is listed below:

 c[0]has distance 0km, as it contains a space station.
 c[1]has distance 1km to the space station in c[0].
 c[2has  distance 2km to the space stations in  c[0]and .c[4]
 c[3]has distance 1km to the space station in c[4] .
 c[4]has distance 0km , as it contains a space station.
We then take .
max(0,1,2,1,0) = 2

Sample Input 1

6 6
0 1 2 4 3 5
Sample Output 1

0
Explanation 1

In this sample, n = m so every city has space station and we print  as our answer.

*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int flatlandSpaceStations(int n, int c_count, int* c);

int main(void)
{
    int n,m;
    printf("Enter Number of ciites: ");
    scanf("%d", &n);
    fflush(stdin);
    printf("Enter number of stations : ");
    scanf("%d", &m);
    int *ptr = (int *)malloc(sizeof(int) * m);
    for(int i = 0; i < m; i++)
    {
        scanf(" %d",&ptr[i]);
    }
    printf("maximum dis = %d ", flatlandSpaceStations(n, m, ptr));
    free(ptr);
    return 0;
}
int flatlandSpaceStations(int n, int c_count, int* c) 
{
    int max = 0;
    int *arr = (int*)calloc(n, sizeof(int));
    int result = 0;
    for(int i = 0; i < n; i++)
    {
        int min = 1000000;
        /*
            first calculate the nearest station for each city
        */
        for(int j = 0; j < c_count; j++)
        {
            result = abs(i - c[j]);
            if(result < min)
            {   
                min = result;
            }
        }
        arr[i] = min;
        printf("%d ", arr[i]);
        // then find the maximum distance for the cities from station 
        if(max < arr[i])
        {
            max = arr[i];
        }     
    }
    return max;
}