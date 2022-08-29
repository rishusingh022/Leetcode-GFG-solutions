class Solution {
public:
   int solve(vector<vector<int>>& oG,int i,int j,vector<vector<int>> &dp){
       if(i==oG.size()-1 && j==oG[0].size()-1){
            return 1;
       }
       if(oG[i][j]==1){
           return 0;
       }
       if(dp[i][j]!=-1){
           return dp[i][j];
       }
       int left=0,right=0;
       if(i<oG.size()-1){
           if(dp[i+1][j]!=-1){
               left=dp[i+1][j];
           }
           else{
               left=solve(oG,i+1,j,dp);
           }
           
       }
       if(j<oG[0].size()-1){
           if(dp[i][j+1]!=-1){
               right=dp[i][j+1];
           }
           else{
               right=solve(oG,i,j+1,dp);
           }
       }
       return dp[i][j]=left+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1){
            return 0;
        }
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(obstacleGrid,0,0,dp);
    }
};