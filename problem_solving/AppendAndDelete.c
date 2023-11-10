/*
    You have two strings of lowercase English letters. You can perform two types of operations on the first string:
    1- Append a lowercase English letter to the end of the string.
    2- Delete the last character of the string. Performing this operation on an empty string results in an empty string.
    Sample Input 0

hackerhappy
hackerrank
9
Sample Output 0

Yes
Explanation 0

We perform  5 delete operations to reduce string s to hacker. Next, we perform  4 append operations (i.e., r, a, n, and k), 
to get hackerrank. Because we were able to convert  s to t by performing exactly k =9 operations, we return Yes.
****************************************************************************************************
Sample Input 1

aba
aba
7
Sample Output 1

Yes
Explanation 1

We perform  4 delete operations to reduce string  s to the empty string. Recall that though the string will be empty after 3 deletions, 
we can still perform a delete operation on an empty string to get the empty string. Next, we perform 3 append operations (i.e., a, b, and a). 
Because we were able to convert  s to t by performing exactly k = 7 operations, we return Yes.

Sample Input 2

ashley
ash
2
Sample Output 2

No
Explanation 2

To convert ashley to ash a minimum of  3 steps are needed. Hence we print No as answer.

*/


char* appendAndDelete(char* s, char* t, int k) 
{
    int flag = 0;
    char * result = (char *)calloc(3, sizeof(char));
    int i = 0, j = 0;
    int CounterDiffrent = 0;
    int Container = 0;
    int str1 = strlen(s);
    int str2 = strlen(t);
    /*
        first calculating diffrent characters 
    */
    while((s[i] != '\0') || (t[j] != '\0'))
    { 
        if(s[i] != t[j] || flag == 1)
        {
            if(flag == 0)
            {
                flag = 1;
            }
            CounterDiffrent++; 
        }     
        if(s[i] == '\0')
        { 
            // do nothing  
        } 
        else 
        {
            i++;
        }
        if(t[j] == '\0')
        {
            // do nothing  
        }
        else 
        {
            j++;
        }
            
    }  
    if(flag == 0) // both string have the same charactars
    {
        result = "Yes";
    }
    else 
    {
        if(str1 == str2)
        {
            Container = CounterDiffrent*2;
            if(Container <= k )
            {
                result = "Yes";
            }
            else 
            {
                result = "No";
            }
        }
        else  // if str1 < str2 or str1 > str2
        {
           int innerflag = 0;
            Container  = CounterDiffrent;
            while(Container <= k)
            {
                Container += 2;    
                if(str1 > str2 && (Container == k || (Container - 1) == k))
                {
                    result = "Yes";
                    innerflag = 1;
                    break;
                }
                else if(str1 < str2 && (Container == k))
                {
                    result = "Yes";
                    innerflag = 1;
                    break;
                }              
            }  
            if(innerflag == 0)
            {
                result = "No";           
            }                     
        }
    }
    return result;
}