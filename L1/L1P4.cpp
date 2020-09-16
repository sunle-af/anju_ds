/* Radix sort 
first step is to sort array using counting sort and key for that is use last digit of the numbers
for eg we have an array 53 89 150 36 633 233
so sorting by using last digit 150 53 633 233 36 89
now another thing is counting sort is a stable sorting alogrithm that means if there is any repeataiton then it will appear in 
same order as befre eg 53 633 233 are placed in order as in original array
now this is very important for using counting sort in radix sort it must be in stable sort it wont work 
now again sort using second last digit 
633 233 36 150 53 89
now again with next third last digit no like 53 89 36 don't have any digit we assume 0 
36 53 89 150 233 633 and there you have it its sorted
Radix 
bigO of counting is O(n+k)
radix O(d(n+b))
 */
#include <iostream>
using namespace std;
/* A utility function to get maximum value in arr[] \
But what is porpose of finding max vaule if we get how what is max value we can easily find what how many digit will there
and that will help in finding number of passes*/
int getMax(int arr[], int n) 
{ 
    int mx = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > mx) 
            mx = arr[i]; 
    return mx; 
} 
void countSort(int arr[], int n, int exp) 
{ 
    int output[n]; // output array 
    int i, count[10] = {0}; 
  
    // Store count of occurrences in count[] 
    for (i = 0; i < n; i++) 
        count[ (arr[i]/exp)%10 ]++; 
  
    // Change count[i] so that count[i] now contains actual 
    //  position of this digit in output[] 
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    // Build the output array 
    for (i = n - 1; i >= 0; i--) 
    { 
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
        count[ (arr[i]/exp)%10 ]--; 
    } 
  
    // Copy the output array to arr[], so that arr[] now 
    // contains sorted numbers according to current digit 
    for (i = 0; i < n; i++) 
        arr[i] = output[i]; 
}  
// The main function to that sorts arr[] of size n using  
// Radix Sort 
void radixsort(int arr[], int n) 
{ 
    // Find the maximum number to know number of digits 
    int m = getMax(arr, n); 
  
    // Do counting sort for every digit. Note that instead 
    // of passing digit number, exp is passed. exp is 10^i 
    // where i is current digit number 
    for (int exp = 1; m/exp > 0; exp *= 10) 
        countSort(arr, n, exp); 
} 
  
 
  
// Driver program to test above functions 
int main() 
{   
    int n;
    cout<<"ENTER SIZE OF ARRAY ";

    cin>>n;
    int a[n];
    cout<<"ENTER VALUES ";
    
    
    for(int i=0;i<n; i++){
        cin>>a[i];

    } 

    radixsort(a, n); 
        cout<<"OUTPUT  ";
     for(int i=0;i<n; i++){
        cout<<a[i]<<"  ";

    } 
    return 0; 
} 
  

