class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        int len=INT_MAX;
        int left=0;
        int right=0;
        int curr_sum=0;
        int n=nums.size();
        for(right=0;right<n;right++){
            curr_sum+=nums[right];
            while(curr_sum>=k && left<=right){
                len=min(len,right-left+1);
                curr_sum-=nums[left++];
            }
        }
        if(len==INT_MAX){
            return 0;
        }
        return len;
    }
};