int workbook(int _Number_Of_Chapters, int _Number_Of_Problem_In_Page_, int* arr) 
{
    int Number_Of_Special_Problem = 0, indicator = 0;
    int Number_Of_Problems = 0;
    int _Number_Of_Page_ = 1;
     
/*  we make 3 loops,    
    first for chapter
    seconde for problems in each chapter
    third for problem in each page
    */
    
    while(_Number_Of_Chapters--)
    {  
        while(arr[indicator] != Number_Of_Problems)
        {
            do 
            {
                Number_Of_Problems++; 
        
                if(_Number_Of_Page_ == Number_Of_Problems )
                {
                    /* 
                        if find page as the same index of problem
                    */
                    Number_Of_Special_Problem++;         
                } 
        
                if(arr[indicator] == Number_Of_Problems)
                {
                    break;
                    /*
                        get out from loop if problems in chapter is finished 
                    */
                }
            
            }while((Number_Of_Problems % _Number_Of_Problem_In_Page_));
            
            _Number_Of_Page_++;  
        }
        
        indicator++;
        Number_Of_Problems = 0;  // reset number of problems 
    }  
    return Number_Of_Special_Problem ;
}