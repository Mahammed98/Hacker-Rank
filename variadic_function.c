#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/*
    there are the macros should be used with variadic function
    1- va_start(variable with data type va_list, number of argument)
    2- va_arg(variable with data type va_list, data type of list of arguments)
    3- va_end(variable with data type va_list); 
*/

int  sum (int count,...)
{
    va_list variable;       // variable from va_list data type
    int i, sum = 0;

    va_start(variable,count);    // start the list of arguments

    for(i = 0; i < count; i++)
    {
        sum += va_arg(variable, int);
    }
    va_end(variable);  // end the list of arguments
    return sum;

}


int min(int count,...)
{
    va_list variable;       // variable from va_list data type
    int i, x;
    int minimum = 0;



    va_start(variable,count);   // start the list of arguments

    for(i = 0; i < count; i++)
    {
        x = va_arg(variable, int);
        if (i == 0)
        {
           x = minimum;
        }
        else if(minimum > x)
        {
            minimum  = x;
        }

    }
    va_end(variable);  // end the list of arguments

    return minimum;
}

int max(int count,...)
{
    va_list variable;       // variable from va_list data type
    int i, x;
    int maximum = 0;



    va_start(variable,count);   // start the list of arguments

    for(i = 0; i < count; i++)
    {
        x = va_arg(variable, int);
        if (i == 0)
        {
           x = maximum;
        }
        else if(maximum < x)
        {
            maximum  = x;
        }

    }
    va_end(variable);  // end the list of arguments

    return maximum;
}
