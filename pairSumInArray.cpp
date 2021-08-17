/*
Pair sum in array

You have been given an integer array/list(ARR) and a number 'num'. Find and return the total number of pairs in the array/list which sum to 'num'.

Note:
Given array/list can contain duplicate elements. 

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the first array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.

Third line contains an integer 'num'.

Output format :
For each test case, print the total number of pairs present in the array/list.

Output for every test case will be printed in a separate line.

Constraints :

1 <= t <= 10^2
0 <= N <= 10^4
0 <= num <= 10^9

Time Limit: 1 sec

Sample Input 1:
1
9
1 3 6 2 5 4 3 2 4
7

Sample Output 1:
7
*/

// O(n^2) solution, by recursion. Can be done using iteration as well.

int pairSum(int *arr, int n, int num)
{
    
    if(n == 1 || n == 0)
        return 0;
    
    int numOfPairs = 0;
    
    int first = 0;
    int second = 0;
    
    int smallSum = pairSum(arr+1, n-1, num);
    
    first = arr[0];
    second = num - first;
    
    int newPairs = 0;
    
    for(int i = 1; i < n; i++)
    {
        if(arr[i] == second)
            newPairs++;
    }
    
    numOfPairs = smallSum + newPairs;
    
    return numOfPairs;
}

--------------------------------------------------------------------------------------------------------------------------

// O(n * log n) solution (incomplete)

//MERGE ARRAYS CODE FROM GFG
void mergeArrays(int arr1[], int arr2[], int n1, int n2, int arr3[])
{
    int i = 0, j = 0, k = 0;
 
    // Traverse both array
    while (i<n1 && j <n2)
    {
        // Check if current element of first
        // array is smaller than current element
        // of second array. If yes, store first
        // array element and increment first array
        // index. Otherwise do same with second array
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }
 
    // Store remaining elements of first array
    while (i < n1)
        arr3[k++] = arr1[i++];
 
    // Store remaining elements of second array
    while (j < n2)
        arr3[k++] = arr2[j++];
}

//SELF
void createHalves(int h1[], int h2[], int s1, int s2, int original[])
{
    
    for ( int i = 0; i < s1; i++ )
        h1[i] = original[i];
    for ( int j = 0; j < s2; j++ )
        h2[j] = original[s1 + j];    
}


void mergeSort(int input[], int size){
  
    if (size == 0 or size == 1)
        return;
    else
    {
        const int size1 = size/2 ;
        const int size2 = size - (size/2) ;
        
        int half1[size1];
        int half2[size2];
        createHalves(half1, half2, size1, size2, input);
        
        mergeSort(half1, sizeof(half1)/sizeof(int) );
        mergeSort(half2, sizeof(half2)/sizeof(int) );
        
        mergeArrays(half1, half2, size1, size2, input);
    }
}

//2 2 2 2 2 
//1 1 1 3 3 

int pairSum(int *arr, int n, int num)
{
    
    if(n == 1 || n == 0)
        return 0;
    
    int numOfPairs = 0;
    
    int sum = 0;
    
    mergeSort(arr, n);
    
    int i = 0;
    int j = n - 1;
    
    while (i < j && i < n && j > -1)
    {
        sum = arr[i] + arr[j];
        
        int num1 = arr[i];
        int num2 = arr[j];
        
        if(sum == num)
        {
            
            int c1 = 0;
            int c2 = 0;
            
            
            while(i < j && i < n && j > -1 && (arr[i] == num1 || arr[j] == num2))
            {
                if(arr[i] == num1)
            	{
                	c1++;
                	i++;
            	}
            
            	if(arr[j] == num2)
            	{
                	c2++;
                	j--;
            	}
            }

            
            
            if(i == j && arr[i] == num1 && arr[i] == num2)
            {
                c1 = c1 + c2 + 1;
                numOfPairs += (c1*(c1-1))/2 ;
            }
            else
                numOfPairs += c1 * c2;
            
            
        }
        else if(sum > num)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    
    
    return numOfPairs;
}
