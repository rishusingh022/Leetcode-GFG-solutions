class Solution {
public:
    //int mod=1e9+7;
    int solve(int m,int n,vector<vector<int>> &dp){
        if(m==1 || n==1){
            return 1;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        
        long long int left=dp[m-1][n];
        if(left==-1){
            left=solve(m-1,n,dp);
        }
        long long int right=dp[m][n-1];
        if(right==-1){
            right=solve(m,n-1,dp);
        }
        return dp[m][n]=left+right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(m,n,dp);
        
    }
};