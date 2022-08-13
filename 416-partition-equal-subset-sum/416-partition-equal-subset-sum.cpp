class Solution {
public:
    bool SubsetSum(vector<int> arr,int sum){
        int n=arr.size();
        int dp[n+1][sum+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0 || j==0){
                    if(i==0){
                        dp[i][j]=false;
                    }
                    if(j==0){
                        dp[i][j]=true;
                    }
                }
                else if(arr[i-1]<=j){
                    dp[i][j]= dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        int yo=accumulate(nums.begin(),nums.end(),0);
        if(yo%2!=0){
            return false;
        }
        else{
            return SubsetSum(nums,yo/2);
        }
    }
};