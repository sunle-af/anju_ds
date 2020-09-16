#include <iostream>
using namespace std;
 void reverse(int a[],int start ,int end ){
    while(start<end){
        /* read about How to swap two numbers without using a temporary variable? 
        its a article about how using XOR we can reverse the or swap things  */
        a[start] ^= a[end]; 
        a[end] ^= a[start]; 
        a[start] ^= a[end]; 
        start++;
        end--;

    }

}
int main(){
    int n;cout<<"ENTER SIZE OF ARRAY ";
    cin>>n;
    
    int a[n];
    cout<<"ENTER VALUES ";
    for(int i =0; i<n;i++){
        cin>>a[i];
    }
     reverse(a,0,n-1);
         cout<<"OUTPUT ";
     for (int i=0 ; i<n; i++){
        cout<<a[i]<<"  ";
    }
    return 0;

}