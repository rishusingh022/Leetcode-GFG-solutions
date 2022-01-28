// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int maximumSumSubarray(int k, vector<int> &arr , int n){
        // code here 
        int curr_sum=0,max_sum,i;
        for(i=0;i<k;i++) curr_sum+=arr[i];
        max_sum=curr_sum;
        for(;i<n;i++){
            curr_sum-=arr[i-k];
            curr_sum+=arr[i];
            max_sum=max(max_sum,curr_sum);
        }
        return max_sum;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
}   // } Driver Code Ends