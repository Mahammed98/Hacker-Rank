int jumpingOnClouds(int c_count, int* c) 
{
   int Number_of_jumps = 0;
   static int indicator = 0;
   while (indicator != (c_count - 1))
    {
        if(c[indicator+2] == 0)
        {
            if((indicator+2) == c_count)  // check if last element is NULL
            {
                indicator++;
            }
            else 
            {
                indicator += 2;
            }
        }
        else
        {
            indicator++;
        }
        
        Number_of_jumps++;
    }
    return Number_of_jumps;
}