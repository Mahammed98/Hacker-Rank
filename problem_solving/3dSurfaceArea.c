typedef struct View
 {
    int Left;
    int Right;
    int Front;
    int Back;
     
 }CubeView;

int surfaceArea(int A_rows, int A_columns, int** A) 
{
    int i,j;
    int result = 0;
    CubeView c;
    /*
        first creat a 2d array which has zero on edge
        but increas size of rows and coloms by 
    */
    
    int **Cube = (int **)calloc(A_rows+2, sizeof(int*));
    for(int x = 0; x < A_rows+2; x++)
    {
        Cube[x] =(int *)calloc(A_columns+2, sizeof(int));      
    }
    for(i =  1; i <= A_rows; i++)
    {
        for(j = 1; j <= A_columns; j++)
        {
            Cube[i][j] = A[i-1][j-1];
        }
    }
    /*
        calculate the area for each cube
    */
    for(i =  1; i <= A_columns; i++)
    {
        for(j = 1; j <= A_rows; j++)
        {
            result += 2;   // top and bottom (1 unit for each side)
            c.Back = Cube[j][i] - Cube[j][i+1];
            if(c.Back > 0)  
            {
                result += c.Back;
            }
            c.Front = Cube[j][i] - Cube[j][i-1];
            if(c.Front > 0) 
            {
                result += c.Front;
            } 
            c.Left = Cube[j][i] - Cube[j-1][i];
            if(c.Left > 0) 
            {
                result += c.Left;
            } 
            c.Right = Cube[j][i] - Cube[j+1][i];
            if(c.Right > 0)  
            {
                result += c.Right;
            }    
            /*
            reset values, to taker another cube
            */
            c.Back = 0;
            c.Front = 0;
            c.Left = 0;
            c.Right = 0;   
        } // end second for loop
        
    }// end main loop
    return result;
}