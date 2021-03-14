/*
Find the Unique Element
Send Feedback
You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].
Now, in the given array/list, 'M' numbers are present twice and one number is present only once.
You need to find and return that number which is unique in the array/list.
*/

/*
APPROACH 1 : BRUTE FORCE

Go through the entire array, count the elements' frequency and check which element comes only once.
O ( n^2)
*/


// APPROACH 2 : BETTER

// Sort Array, then check if the element at current index is equal to the one at the next. 
// Then switch the count to check the index after the next index
// Keep doing until unique element is found

int findUnique(int ar[], int ar_size){
    mergeSort(ar, 0, ar_size-1);   
    
    for(int i = 0; i < ar_size; i = i+2)
    {
        if (ar[i] != ar[i+1])
            return ar[i];
    }
        
}

// O ( n * log(n) )


// APPROACH 3 : BEST

// Use XOR operator throughout the array
// The result at the end will be the unique element because a XOR a is 0

int findUnique(int ar[], int ar_size){
  
    int res = ar[0]; 
        for (int i = 1; i < ar_size; i++) 
            res = res ^ ar[i]; 
  
        return res;
        
}
// O ( n )
