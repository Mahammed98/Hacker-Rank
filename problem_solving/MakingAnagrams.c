int makingAnagrams(char* s1, char* s2) 
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int Counter_Of_Deletion_Char = 0;
    
    int * _FQ1_ = (int *)calloc(26, sizeof(int));
    int * _FQ2_ = (int *)calloc(26, sizeof(int));
    /*
        first calculate the freq of each character from (a-z) on both strings
    */
    for(int i = 0; i < len1; i++)
    {
        _FQ1_[s1[i] - 97]++;
    }
    for(int j = 0; j < len2; j++)
    {
        _FQ2_[s2[j]- 97]++;
    }
    /*
        then calculate the diffrences between two fq array
    */
    for(int k = 0; k < 26; k++)
    {
        if(_FQ1_[k] != _FQ2_[k])
        {
            Counter_Of_Deletion_Char += abs(_FQ1_[k] - _FQ2_[k]);
        }
    }
    return Counter_Of_Deletion_Char;

}