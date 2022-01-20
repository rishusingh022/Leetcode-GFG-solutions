// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
#define ll long long
class Solution{   
public:
    long long subarraySum(long long arr[], long long n)
    {
        // Your code goes here
        ll mod=pow(10,9)+7;
        ll sum=0;
        for(ll i=0;i<n;i++){
            sum=(sum%mod+((arr[i]%mod)*((n-i)%mod)*((i+1)%mod))%mod)%mod;
        }
        return sum%mod;
    }
};

// { Driver Code Starts.
int main()
 {
     long long t; 
     cin>>t;
     while(t--)
     {
         long long n; cin>>n;
         long long a[n+5];
         for(long long i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.subarraySum(a, n)<<endl;
     }
    return 0;
}
  // } Driver Code Ends