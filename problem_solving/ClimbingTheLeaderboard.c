int* climbingLeaderboard(int ranked_count, int* ranked, int player_count, int* player, int* result_count) 
{
    *result_count = player_count;
    int value = ranked[0];
    int RankeNumber = 0;
    int counter = 1;
    int flag = 0;
    int low, high;
    int * ptr = (int *)calloc(ranked_count, sizeof(int));
    int * result = (int*)calloc(player_count, sizeof(int));
    ptr[0] = value;
    /*
        Creat a table of ranking 
    */
    for(int i = 1; i < ranked_count; i++)
    {
        if(ranked[i] != value)
        {
            value = ranked[i];
            ptr[++RankeNumber] = value;
            counter++;
        }   
    }
    for(int i = 0; i < player_count; i++)
    {
        /*
            first check if player record exceesting the recording table
         */
        if(player[i] < ptr[counter-1])
        {
            result[i] = counter+1;
        }
        else if(player[i] > ptr[0])
        {
            result [i] = 1;
        }
        // if not exceest go to search on recording table 
        // using binary search algorithm
        else 
        {
            low = counter -1;
            high = 0;
            while(low >= high)
            {
                int middle = (low + high) / 2;
                /*
                    if player recording is existing on recording table, then it will take the same order
                */
                if(player[i] == ptr[middle]) 
                {
                    result[i] = middle + 1;
                    flag = 1;
                    break;
                }
                else if(player[i] < ptr[middle])
                {
                    high = middle + 1;
                }
                else if(player[i] > ptr[middle])
                {
                    low = middle - 1;
                }
            }
            if(flag == 0)
            {
                result[i] = low + 2;
            }
            flag = 0;
        }
      
    }
    return result;
}