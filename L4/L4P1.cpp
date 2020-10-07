#include <bits/stdc++.h>
using namespace std;
string checkblance(string test){
        stack <char> st;
        char pop_val; 
        for(int i=0; i<test.length();i++){
         
        if(test[i]=='{'||test[i]=='['||test[i]=='(')
        {
        st.push(test[i]);
          }
        else {
        if(st.empty()){ return "Error:Unblanced";}
        else
        {       pop_val=st.top();
                st.pop();
                 if(test[i]=='}' && pop_val!='{'){cout<<"inner pop value"<<pop_val;return "unblanced }";}
                else if(test[i]==']' && pop_val!='['){cout<<"inner pop value"<<pop_val;return "unblanced ]";}
                else if(test[i]==')' && pop_val!='('){cout<<"inner pop value"<<pop_val;return "unblanced )";}         
        }
        }
        }
        if(st.empty()){return "Balanced";}
        else {   return "Error: Unblanced"; }

}
int main(){
        string test;
         getline(cin,test);
        cout<<checkblance(test);
        return 0;

}