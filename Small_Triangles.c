#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
float calculate_area(triangle tr)
{
	 /*
	 		sqrt function return double and take double
	*/
    float p = (float)(tr.a + tr.b + tr.c)/2;
    float area;
    double under_sqrt;
    under_sqrt = p * (p - tr.a) * (p - tr.b) * (p - tr.c);
    area = (float)sqrt(under_sqrt);
    return area;

}
void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
    int i, j;
    triangle temp;
    for (j = 0; j < n; j++)
        {
            for(i = 0; i < n - 1; i++)
            {
                if(calculate_area(tr[i]) > calculate_area(tr[i+1]))
                    {
                        temp = tr[i];
                        tr[i] = tr[i+1];
                        tr[i+1] = temp;
                    }
                else
                    {
                        // no action needed
                    }
            }
        }
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
