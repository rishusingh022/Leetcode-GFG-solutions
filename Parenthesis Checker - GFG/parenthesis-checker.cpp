// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        if(x.size()==0){
            return true;
        }
        stack<char> st;
        for(char c:x){
            if(st.size()==0){
                st.push(c);
            }
            else if(c=='{' ||c=='[' || c=='('){
                st.push(c);
            }
            else if(st.top()=='(' and c==')'){
                st.pop();
            }
            else if(st.top()=='{' and c=='}'){
                st.pop();
            }
            else if(st.top()=='[' and c==']'){
                st.pop();
            }
            else{
                st.push(c);
            }
        }
        if(st.size()>0){
            return false;
        }
        else{
            return true;
        }
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends