// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    bool isPossible(int arr[], int n, int k,long long mid){
        long long  cnt=1;
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum>mid){
                cnt++;
                sum=arr[i];
            }
            if(cnt>k){
                return false;
            }
        }
        return true;
    }
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        typedef long long ll;
        ll s=INT_MIN;
        ll e=0;
        for(int i=0;i<n;i++){
            s=max(s,(long long)arr[i]);
            e+=arr[i];
        }
        
        ll res=-1;
        while(s<=e){
            ll mid=s+(e-s)/2;
            if(isPossible(arr,n,k,mid)==true){
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

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends