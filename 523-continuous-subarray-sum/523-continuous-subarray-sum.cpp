class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0;
        int n=nums.size();
        if(n==1){
            return false;
        }
        mp[0]=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int mod=sum%k;
            if(mod==0 and i>=1) return true;
            if(mp.find(mod)==mp.end()) mp[mod]=i;
            else if(mp.find(mod)!=mp.end() and i-mp[mod]>=2) return true;
            
        }
        return false;
    }
};