class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a[32]={0};
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<32;j++){
                if((nums[i]>>j)&1) a[j]++;
            }
        }
        int ans=0;
        for(int i=31;i>=0;i--){
            ans+=(a[i]%3)*(1<<i);
        }
        return ans;
    }
};