char* balancedSums(int arr_count, int* arr) 
{
    int _SUM_RIGHT_ = 0; // sum of right elements for the picked element
    int _SUM_LEFT_ = 0;  // sum of left elements for the picked element
    int _TOTAL_SUM_ = 0; // total sum of all elements 
    char * result =(char *)malloc(sizeof(char) * 3);
    result = "NO"; // intial value
    /*
        First we gonna to calculate the sum of array
    */
    for(int i = 0; i < arr_count; i++)
    {
        _TOTAL_SUM_ += arr[i];
    }
    
    _SUM_RIGHT_ = _TOTAL_SUM_;
    /*
        second calculate the sum elements right and left of each element
    */
    for(int j  = 0; j < arr_count; j++)
    {
        _SUM_RIGHT_ -= arr[j];
        _SUM_LEFT_ = _TOTAL_SUM_ - arr[j] - _SUM_RIGHT_;
        if(_SUM_RIGHT_ == _SUM_LEFT_)
        {
            result = "YES";
            break;
        }
        else
        {
            //nothing
        }
    }
    return result;
}