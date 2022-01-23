class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int n=nums.size();
        if(n==1){
            return nums;
        }
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]!=1){
                continue;
            }
            if(i==0 ||i==n-1){
                if(i==0){
                    if(nums[i]+1!=nums[i+1]){
                        ans.push_back(nums[i]);
                    }
                }
                if(i==n-1){
                    if(nums[i]-1!=nums[i-1]){
                        ans.push_back(nums[i]);
                    }
                }
                continue;
            }
            if(nums[i]-1!=nums[i-1] && nums[i]+1!=nums[i+1]){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};