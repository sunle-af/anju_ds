 #include <bits/stdc++.h> 
#include <vector>
using namespace std; 

// A recursive binary search function. It returns 
// location of x in given array arr[l..r] is present, 
// otherwise -1 
int binarySearch(vector <int> arr, int l, int r, int x) 
{ 
	if (r >= l) { 
		int mid = l + (r - l) / 2; 

		// If the element is present at the middle 
		// itself 
		if (arr[mid] == x) 
			return mid; 

		// If element is smaller than mid, then 
		// it can only be present in left subarray 
		if (arr[mid] > x) 
			return binarySearch(arr, l, mid - 1, x); 

		// Else the element can only be present 
		// in right subarray 
		return binarySearch(arr, mid + 1, r, x); 
	} 

	// We reach here when element is not 
	// present in array 
	return -1; 
} 

int main(void) 
{  
    cout<<"Enter length of array ";
    int n ;
    std::cin>>n;
    cout<<"Enter the sorted values ";
    int input =0;
    vector <int> arr;
   //taking input for vector   
    for(int i=0; i<n;i++){
     
      cin>>input;
      arr.push_back(input);
    }
	 
	cout<<"Enter the key value ";
     int x;// so key basically what we want to find 
    std::cin>>x;
    

	int result = binarySearch(arr, 0, n - 1, x); 
    if(result==-1){
        cout<<"The nuber is not present ";

    }else cout<<"the number is at index "<<result;

	return 0; 
} 
