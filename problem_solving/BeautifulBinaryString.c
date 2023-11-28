int beautifulBinaryString(char* b) 
{
    char SubSring [3] = "010";
    int i = 0, j = 0;
    int counter = 0;
    int counter_of_right_nubmers = 0 ; 
    int flag = 0;
    
    while(b[i] != '\0')
    {
        if(b[i] == '0')
        {
            int k = 0;
            for(j = i; j < i + 3; j++)
            {      
                if(b[j] != SubSring[k++])
                {
                    break; // get out from loop(sub string did not found)
                }
                else 
                {
                    counter_of_right_nubmers++;
                }
            }
            if(counter_of_right_nubmers == 3) // if all elements of substring are found 
            {
                flag = 1;
            }
            else 
            {
                //nothing
            }
        }
        counter_of_right_nubmers = 0; // reset value
        if(flag == 1)
        {
            counter++;
            i = j;  // i starts after substring is found
            flag = 0;  // reset flag 
        }
        else
        {
            i++;
        }
    }
    return counter;
}