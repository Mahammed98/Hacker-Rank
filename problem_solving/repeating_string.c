long repeatedString(char* s, long n) 
{
    int len = strlen(s);
    long long i = 0, j = 0, k;
    long long counter = 0;    
    for(k = 0; k < len; k++)
    {
        if(s[k] == 'a')
        {
            counter++;  // 2
        }
    }
    
    i = n / len;  // 10/3 = 3
    
    counter = i * counter;  // 3 * 2 = 6
    
    j = n - (len * i) ; // 3 * 3 = 9 - N(10) = 1
     
    for (k = 0; k < j; k++)
    {
        if(s[k] == 'a')
        {
            counter++;
        }
    }
    
    /*
    if(counter == len)
    {
        result = n;
    }
    else 
    {
        while(i != n)
        {
            // 0     3
            if(j == len )
            {
                j = 0;
                continue;
            }
            //   s[0]
            else if(s[j] == 'a')
            {
                result++;  // 7
            } 
                i++;  // 10
                j++;  // 3
        }
    }  
    */
        
    return counter;  
}
