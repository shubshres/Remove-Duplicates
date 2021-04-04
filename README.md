# Remove-Duplicates
 A C program that takes a sequence of n integer values and removes duplicate occurences. 


This program...
 - Reads an input sequence of values, with each value giveing an ordered pair (value, position indicator)
 - Sorts the pairs in ascending order by value in a stable fashion. If the sort is stable, then the key is just the value. If the chosen sort is unstable, the key is extended with the position indicator. 
 - Uses O(n) time to sort over the result and remove any occurences beyond the first one for a key. 
 - Sorts the paris using the "unique" position indicator as the kye. 
 - Outputs the number of unuque values followed by the values (without the position indicators). 
 - Sorts the numbers utilizing qsort()
