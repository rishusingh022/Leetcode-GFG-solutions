class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return 0;
        if(nums[0]==0) return -1;
        
        // main code starts
        int step=nums[0];
        int maxReach=nums[0];
        int jump=1;
        int i=1;
        for(i=1;i<n;i++){
            if(i==n-1) return jump;
            maxReach=max(maxReach,i+nums[i]);
            step--;
            if(step==0){
                if(i>=maxReach) return -1;
                step=maxReach-i;
                jump++;
            }
        }
        return -1;
        
    }
};