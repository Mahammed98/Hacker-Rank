int beautifulTriplets(int d, int arr_count, int* arr) 
{
   int value1 = 0;
   int result = 0;
   for(int i = 0; i < arr_count - 2 ; i++)
   {
       for(int j = i+1; j < arr_count - 1; j++)
       {
            if(((arr[j] - arr[i]) == d) && (value1 == 0))
            {
                for(int k  = j+1; k < arr_count; k++)
                {
                    if(arr[k] - arr[j] == d)
                    {
                        result++;
                        break;
                    }
                }
                break;  
            }
       }
       value1 = 0; //reset value 
   } 
   return result;

}