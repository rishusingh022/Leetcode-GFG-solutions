class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int max_count1=0;
        for(auto i:nums){
            if(i==1){
                max_count1++;
            }
        }
        int curr_count1=0;
        for(int i=0;i<max_count1;i++){
            if(nums[i]==1){
                curr_count1++;
            }
        }
        int win=max_count1;
        int mx=curr_count1;
        for(int i=win;i<n+win;i++){
            if(nums[i%n]==1){
                curr_count1++;
            }
            if(nums[(i-win)%n]==1){
                curr_count1--;
            }
            mx=max(mx,curr_count1);
        }
        return max_count1-mx;
    }
};