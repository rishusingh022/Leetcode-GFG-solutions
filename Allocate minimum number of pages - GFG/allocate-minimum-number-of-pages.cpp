// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool isPossible(int arr[],int n,int m,int mid){
        int cnt=1;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum>mid){
                cnt++;
                sum=arr[i];
            }
            if(cnt>m){
                return false;
            }
        }
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int m) 
    {
        int e=0;
        int s=INT_MIN;
        for(int i=0;i<n;i++){
            e+=arr[i];
            s=max(s,arr[i]);
        }
        int res=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(isPossible(arr,n,m,mid)==true){
                res=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends