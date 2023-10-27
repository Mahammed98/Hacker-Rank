/* we put arr w (width) as a paramenter to the funcion */
int* serviceLane(int n, int cases_rows, int* w, int** cases, int* result_count) 
{
    int iteration1, iteration2, minimum = 3;
    
    static int arr[1001] = {0};  //return array
    
    for (iteration1 = 0; iteration1 < cases_rows; iteration1++)
    {
        for (iteration2 = cases[iteration1][0]; iteration2 <= cases[iteration1][1]; iteration2++)
        {
                // if we find minimum width between index's interval
            if(w[iteration2] < minimum)   
            {
                minimum = w[iteration2];
            } // end if
        }
        arr[iteration1] = minimum; // store minimum value 
        minimum = 3; // reset minimum value 
        (*result_count)++; // increament number of test case
    }
    return arr;
}