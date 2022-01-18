class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        //cornor cases
        
        if(n<=1) return true;
        if(nums[0]==0) return false;
        
        // main code starts
        int step=nums[0];
        int maxReach=nums[0];
        //int jump=1;
        int i=1;
        for(i=1;i<n;i++){
            if(i==n-1) return true;
            maxReach=max(maxReach,i+nums[i]);
            step--;
            if(step==0){
                if(i>=maxReach) return false;
                step=maxReach-i;
                //jump++;
            }
        }
        return false;
    }
};