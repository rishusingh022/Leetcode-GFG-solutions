class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++) prefix[i]=prefix[i-1]+nums[i];
        for(int i=0;i<n;i++){
            if(prefix[i]-nums[i]==prefix[n-1]-prefix[i]) return i;
        }
        return -1;
    }
};