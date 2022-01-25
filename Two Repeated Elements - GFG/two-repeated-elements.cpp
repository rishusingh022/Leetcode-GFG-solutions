// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to find two repeated elements.
    vector<int> twoRepeated (int arr[], int n) {
        // Your code here
        vector<int> arr2;
        for(int i=0;i<n+2;i++) arr2.push_back(arr[i]);
        for(int i=0;i<n+2;i++){
            if(arr[i]!=arr[arr[i]-1]){
                swap(arr[i],arr[arr[i]-1]);
                i--;
            }
        }
        // for(int i=0;i<n+2;i++) cout<<arr[i]<<" ";
        // cout<<endl;
        vector<int> temp;
        for(int i=0;i<n+2;i++){
            if(arr2[i]==arr[n] || arr2[i]==arr[n+1]) temp.push_back(arr2[i]);
        }
        if(temp[0]==temp[1]){
            return {temp[0],temp[2]};
        }
        if(temp[0]==temp[2]){
            return {temp[0],temp[1]};
        }
        return {temp[1],temp[0]};
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        
        int a[n+2];
        
        for(int i=0;i<n+2;i++)
            cin>>a[i];
        
        Solution obj;
        vector<int> res;
        res = obj.twoRepeated(a, n);
        cout<<res[0]<<" "<<res[1]<<endl;
    }
    return 0;
}
  // } Driver Code Ends