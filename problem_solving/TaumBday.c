

#include<stdio.h>

long long taumBday (long long, long long, long long, long long, long long);

int main()
{
    short int iteration = 0;
    long long b, w, bc, wc, z;
    
    scanf("%hd", &iteration);
    
    for(short int j = 0; j < iteration; j++)
    {
        scanf("%lld %lld %lld %lld %lld", &b, &w, &bc, &wc, &z);
        printf("%lld\n",taumBday(b, w, bc, wc, z));
    }
    return 0;   
}

/*
    This function calculate the minimum cost to purchase the gifts
    ex:
        5 9     b = 5, w = 5
        2 3 4   bc = 2, wc = 3, z = 4
        cannot decrease the cost of black or white gifts by converting colors. 
        Z is too high. He will buy gifts at their original prices
        final_result = ( 5 * 2) + (9 * 3);
*/
long long taumBday (long long b, long long w, long long bc, long long wc, long long z)
{
    long long Result_1 = (b * bc) + (w * wc);
    long long Result_2 = (w * (bc + z)) + (b * bc);   // to convert from white to black
    long long Result_3 = (b * (wc + z)) + (w * wc);   // to convert from black to white
    long long Final_Result = 0;
    if( Result_1 <= Result_2 && Result_1 <= Result_3)
    {
        Final_Result = Result_1;
    }
    else if( Result_2 <= Result_1 && Result_2 <= Result_3)
    {
        Final_Result = Result_2;
    }
    else if( Result_3 <= Result_2 && Result_3 <= Result_1)
    {
        Final_Result = Result_3;
    }
    return Final_Result; 
}
