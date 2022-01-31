class Solution {
public:
    vector<vector<int>> dp;
    int solve(int start,int end){
        if(start>=end) return 0;
        int res=INT_MAX;
        if(dp[start][end]!=-1) return dp[start][end];
        for(int i=start;i<=end;i++){
            res=min(res,i+max(solve(start,i-1),solve(i+1,end)));   
        }
        dp[start][end]=res;
        return res;
    }
    int getMoneyAmount(int n) {
        dp=vector<vector<int>>(n+1,vector<int>(n+1,-1));
        return solve(1,n);
    }
};