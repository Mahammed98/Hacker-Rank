/*
There is a strange counter. At the first second, it displays the number 3. Each second, the number displayed by 1 decrements by 1 until it reaches . 
In next second, the timer resets to 2*initail number for the prior cycle, and continues counting down.
 The diagram below shows the counter values for each time  in the first three cycles:
   t -> v       t -> v       t  -> v
   1 -> 3       4 -> 6       10 -> 12
   2 -> 2       5 -> 5       11 -> 11
   3 -> 1       6 -> 4       12 -> 10
                7 -> 3       13 -> 9
                8 -> 2       14 -> 8
                9 -> 1       15 -> 7
                             16 -> 6
                             17 -> 5
                             18 -> 4
                             19 -> 3
                             20 -> 2
                             21 -> 1
*/






long strangeCounter(long t) 
{
    long NumberOfTable = 0;
    long value = 0;
    
    for(NumberOfTable = 1, value = 3;;)
    {
        NumberOfTable += value;
        value *= 2;
        if(NumberOfTable > t)
        {
            return (NumberOfTable - t);
        }
    }
}
