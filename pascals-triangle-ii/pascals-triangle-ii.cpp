class Solution {
public:
    int dp[35][35];
    int solve(int i,int j){
        if(j==1 || j==i){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j]=solve(i-1,j-1)+solve(i-1,j);
    }
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<=rowIndex+1;i++){
            ans.push_back(solve(rowIndex+1,i));
        }
        return ans;
    }
};