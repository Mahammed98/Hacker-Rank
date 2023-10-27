#include<stdio.h>
#include<stdlib.h>

void caesar_Cipher(unsigned char* , int , int );

 int main ()
 {
    int String_Lena , Number_of_Shift;
    unsigned char *str;

    scanf("%d ", &String_Lena);

    str = (unsigned char *) malloc(sizeof(unsigned char) * (String_Lena+1));

    for(int i = 0; i < String_Lena + 1; i++)
    {
        scanf("%c", &str[i]);
    }// enter string
    
    fflush(stdin);  // to clear stdin buffer
    
    scanf("%d", &Number_of_Shift);
    
    caesar_Cipher(str, String_Lena , Number_of_Shift); // call function 

    free (str);
    return 0;
 }

void caesar_Cipher(unsigned char* s, int S_len, int N_Shift) 
{
    int iteration = 0;
    while(s[iteration] != '\0')
    {
        //   a to z
        if((s[iteration] >= 97) && (s[iteration] <= 122)) 
        {
            s[iteration] += N_Shift; 
            while(s[iteration] > 122 )
            {
                s[iteration] = s[iteration] - 26;
            }
        }
        //    A to Z
        else if ((s[iteration] >= 65) && (s[iteration] <= 90))
        {
            s[iteration] += N_Shift; 
            while(s[iteration] > 90)
            {
                s[iteration] = s[iteration] - 26;
            }
        }
   
        iteration++;
    }
    for(int j = 0; j < S_len + 1; j++)
    {
        printf("%c", s[j]);
    } // print string
}
