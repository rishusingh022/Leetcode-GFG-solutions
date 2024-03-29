// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void solve(stack<int>st,vector<int>& res){
        if(st.size()==1){
            res.push_back(st.top());
            return ;
        }
        int a=st.top();
        st.pop();
        res.push_back(a);
        solve(st,res);
    }
    vector<int> Reverse(stack<int> St){
        vector<int> res;
        solve(St,res);
        return res;
    }
};

// { Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        vector<int> ans=ob.Reverse(St);
        for(int i=0;i<N;i++){
            cout<<ans[i];
            if(i!=N-1) cout<<" ";
        }
        cout<<endl;
    }
}  // } Driver Code Ends