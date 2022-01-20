// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
#define RANGE 255


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    //Function to arrange all letters of a string in lexicographical 
    //order using Counting Sort.
    string countSort(string arr){
        // code here
        int freq[26]={0};
        for(int i=0;i<arr.size();i++){
            freq[arr[i]-'a']++;
        }
        for(int i=1;i<26;i++){
            //cout<<freq[i]<<" ";
            freq[i]=freq[i-1]+freq[i];
            //cout<<freq[i]<<" ";
        }
        
        string ans=arr;
        for(int i=arr.size()-1;i>=0;i--){
            char ch=arr[i];
            int idx=freq[ch-'a']-1;
            ans[idx]=ch;
            freq[ch-'a']--;
        }
        return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr;
        cin>>arr;
        Solution obj;
        cout<<obj.countSort(arr)<<endl;
    }
    return 0;
}
  // } Driver Code Ends