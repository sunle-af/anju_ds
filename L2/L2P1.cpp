#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>
using namespace std;
//creating a method to find Kth smallest number
int Kthsmallest(vector <int> vect, int k){
    // for undersandting this basically we created a priority queue named as PQ 
    // now this quque take the values from a vector named as "vect" so the line vect.begin(), vect.end() simply means that
    // we taken all the values and make a priority quque of that 
    // now for creating a min-heap priority queue we need to write the "greater" this things are just as it is now max-heap we just need to wirte less
    // so basically it means we created a priority queue named as PQ and we inserted the values from a vector named as vect
     priority_queue < int , vector <int>, greater <int>> PQ(vect.begin(),vect.end());
    //meaning of this line is basically extraction and this extraction is carried out kth time for that we did this loop
    while(--k){
        PQ.pop();
    }
    //we are returning the value
    return PQ.top();
}
int main(){
    //this few lines of code simply means how to make a vector and input the values in it
    cout<<"Enter the size of Array: ";
    int n;
    cin>>n;
    cout<<"Enter the elements: ";
    int x; vector <int> vect;
    for(int i=0; i<n;i++){
        cin>>x;
        vect.push_back(x);
    }
    cout<<"Enter the Kth smallest you want to find: ";
    int k;
    cin>>k;
    //final result
    cout<<"Kth smallest element: ";
    
    cout<<Kthsmallest(vect,k);
    return 0;
}