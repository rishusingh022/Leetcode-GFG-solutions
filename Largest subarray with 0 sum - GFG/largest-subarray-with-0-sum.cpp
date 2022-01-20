// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        // Your code here
        unordered_map<int,vector<int>> mp;
        int sum=0;
        mp[0].push_back(-1);
        for(int i=0;i<n;i++){
            sum+=arr[i];
            mp[sum].push_back(i);
        }
        int len=0;
        for(auto i:mp){
            vector<int> temp=i.second;
            len=max(len,temp[temp.size()-1]-temp[0]);
        }
        return len;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends