class Solution {
public:
    int maxProfit(int k, vector<int>& arr) {
        int n=arr.size();
        if(n==0){
            return 0;
        }
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
                max_so_far=max(max_so_far,dp[i-1][j-1]-arr[j-1]);
                dp[i][j]=max(dp[i][j-1],max_so_far+arr[j]);
            }
        }
        return dp[k][n-1];
    }
};