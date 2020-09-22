#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <queue>   

using namespace std;
int kthsmallest(vector <int> vect, int k){
    priority_queue< int , vector<int>, greater <int>> PQ(vect.begin(), vect.end());
    		 

    while(--k){
        PQ.pop();
    }
        return PQ.top();
}
int main(){ 
    int n; 
    cin>>n;
    vector <int> vect;
    int x;
    for(int i=0;i<n;i++){
          cin>>x;
            vect.push_back(x);
    }
    int k;
    cin>>k;
    cout<<kthsmallest(vect,k);

}