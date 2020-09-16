#include <iostream>

using namespace std;
	int partition(int arr[], int low, int high) 
	{ 
		int pivot = arr[high]; 
		int i = (low-1); // index of smaller element 
		for (int j=low; j<high; j++) 
		{ 
			// If current element is smaller than the pivot 
			if (arr[j] < pivot) 
			{ 
				i++; 

				// swap arr[i] and arr[j] 
				int temp = arr[i]; 
				arr[i] = arr[j]; 
				arr[j] = temp; 
			} 
		} 

		// swap arr[i+1] and arr[high] (or pivot) 
		int temp = arr[i+1]; 
		arr[i+1] = arr[high]; 
		arr[high] = temp; 

		return i+1; 
	} 


	/* The main function that implements QuickSort() 
	arr[] --> Array to be sorted, 
	low --> Starting index, 
	high --> Ending index */
	void sort(int arr[], int low, int high) 
	{ 
		if (low < high) 
		{ 
			/* pi is partitioning index, arr[pi] is 
			now at right place */
			int pi = partition(arr, low, high); 

			// Recursively sort elements before 
			// partition and after partition 
			sort(arr, low, pi-1); 
			sort(arr, pi+1, high); 
		} 
	} 

 int main()	{ 
	 	std::cout<<"Enter size of the array ";
		int n;//size of the array
         std::cin>>n;
         int a[n];
 		std::cout<<"Enter values of the array ";
		//this for loop is used for taking the input for the arrays or taking values
		 for (int i = 0; i < n; i++)
         { 
             std::cin>>a[i];
         }
        
		sort(a,0,n-1);//this is calling the fuction sort which use take the values as first an array named as arr then low which is 0 because staring index high values is n-1 which means last index value 

 		std::cout<<"Sorted array ";
		//this for loop is used for printing the array 
        for (int i = 0; i < n; i++)
         {

             std::cout<<a[i];

         }
         
         
	} 
