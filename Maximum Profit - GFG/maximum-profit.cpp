// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int k, int n, int A[]) {
        // code here
        int dp[k+1][n];
        for(int i=0;i<=k;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
            }
        }
        for(int i=1;i<=k;i++){
            int max_so_far=INT_MIN;
            for(int j=1;j<n;j++){
                max_so_far=max(max_so_far,dp[i-1][j-1]-A[j-1]);
                dp[i][j]=max(dp[i][j-1],max_so_far+A[j]);
            }
        }
        return dp[k][n-1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends