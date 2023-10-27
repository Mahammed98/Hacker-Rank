int chocolateFeast(int n, int c, int m) 
{
    int Number_of_chocolate = n / c; 
    int indicator = 0;
    int result = Number_of_chocolate;
    
    while(Number_of_chocolate >= m)
    {
        if(indicator == m) // if we reach to the number of wrappers 
        {
            result++;  // win one free bar of chocolate ( tolalt chocolate bar which he had)
            indicator = 0;
            Number_of_chocolate = Number_of_chocolate - m + 1; //nubmer of chocolate decreased 
        }
        else   // if we don't reach to number of wrappers 
        {
            indicator++;    
        }
    }
    return result;
}