class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(k>=n){
            return nums[n-1]-nums[0];
        }
        int mn=INT_MAX;
        int i=0,j=k-1;
        //for(auto i:nums) cout<<i<<" ";
        //cout<<endl;
        mn=min(mn,nums[j++]-nums[i++]);
        //cout<<mn<<" ";
        while(j<n){
            //cout<<mn<<" ";
            mn=min(mn,nums[j++]-nums[i++]);
        }
        return mn;
    }
};