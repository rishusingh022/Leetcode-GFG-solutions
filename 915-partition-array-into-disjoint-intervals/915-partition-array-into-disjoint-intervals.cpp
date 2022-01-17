class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n=nums.size();
        vector<int> left_max(n);
        left_max[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            left_max[i]=min(nums[i],left_max[i+1]);
        }
        //for(auto i:left_max) cout<<i<<" ";
        int mx=INT_MIN;
        int i=0;
        for(;i<n-1;i++){
            if(mx<nums[i]){
                mx=nums[i];
            }
            if(mx<=left_max[i+1]){
                return i+1;
            }
        }
        return i+1;
    }
    
};