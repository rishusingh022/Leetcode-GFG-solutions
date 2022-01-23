class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt=0;
        int n=nums.size();
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]>nums[0] && nums[i]<nums[n-1]) cnt++;
        }
        return cnt;
    }
};