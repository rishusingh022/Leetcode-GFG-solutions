// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        if(n==1){
            return 0;
        }
        typedef long long ll;
        ll cost=0;
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        for(ll i=0;i<n;i++){
            pq.push(arr[i]);
        }
        
        while(pq.size()!=1){
            ll min1=pq.top();pq.pop();
            ll min2=pq.top();pq.pop();
            ll new_len=min1+min2;
            cost+=new_len;
            pq.push(new_len);
        }
        return cost;
    }
};


// { Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends