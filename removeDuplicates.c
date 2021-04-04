// Program that takes a sequence of n integers and removes duplicates. 

#include <stdio.h>
#include <stdlib.h>


//creating struct so we can organize utilizing value and key
typedef struct list 
{
    int value; 
    int key; 
} orderedPair;

//this function is utilized during qsort and compares the values of the struct in ascending order
int valueOrder(const void *p1, const void *p2)
{
    const orderedPair *num1 = p1; 
    const orderedPair *num2 = p2; 
    return num1->value - num2->value; 
}

//this function is utilized by qsort and compares the keys of the struct in ascending order
int keyOrder(const void *p1, const void *p2)
{
    const orderedPair *num1 = p1; 
    const orderedPair *num2 = p2; 
    return num1->key - num2->key; 
}

//function for printing
void printOutput(int n, orderedPair localArray[])
{
    //printing the number of values after sorting
    printf("\n\n%d\n", n); 
    int i;

    //printing list
    for (i = 0; i < n; i++)
    {
        printf("%d\n", localArray[i].value);
    }
}

int main(void)
{
    int n; // initializing size of array

    scanf("%d", &n); //taking in input of array size

    orderedPair localArray[n]; 

    //filling up arrays and its values
    int i; 

    for (i = 0; i < n; i++)
    {
        scanf("%d", &localArray[i].value);   //assigning user input to array position
        localArray[i].key = i; //setting the current position value
    }
    
    //qsort... sort the pairs in ascending order by value in a stable fashion. 
    qsort(localArray, n, sizeof(orderedPair), valueOrder);

    //for loop that checks for duplicates
    //initializing variables for for loop
    int j; 
    int duplicateCount = 0; 

    //this loop assigns the keys for duplicates to negative one
    //this is done so on the next for loop we can identify which ones are duplicates since the keys start at 0. 
    for(j = 0; j < n; j++)
    {
        if(localArray[j].value == localArray[j+1].value)
        {
            localArray[j+1].key = -1;
            duplicateCount++;
        }   
    }

    //initizlizing variable newCount, which will hold the new size of array
    int newCount = (n - (duplicateCount));

    //initializing orderedPair array to hold values without duplicates
    orderedPair localArrayNoDups[newCount];

    // initializing variables for the next for loop.
    int a = 0; //initializing idependent counter variable for the array without duplicates
    int k; //initializing int we can utilizize for our for loop

    //this loop copies the values from the localArray that do not have a key value of -1
    for(k = 0; k < n; k++)
    {
        if(localArray[k].key != -1)
        {
            localArrayNoDups[a].key =localArray[k].key ;//localArray[k].key;
            localArrayNoDups[a].value =localArray[k].value;
            a++;
        }
    }

    //calling qsort function once more and utilizng function that orders by key
    qsort(localArrayNoDups, newCount, sizeof(orderedPair), keyOrder);

    //printing out array without duplicates and in order of key
    printOutput(newCount, localArrayNoDups); 

    return 0; //returning without errors
}
