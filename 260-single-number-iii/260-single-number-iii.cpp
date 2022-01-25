class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long res=0;
        int n=nums.size();
        if(n==2){
            return nums;
        }
        for(int i=0;i<n;i++){
            res^=nums[i];
        }
        long long cnt=res & ~(res-1);
        int a=0;
        int b=0;
        for(int i=0;i<n;i++){
            if(nums[i]&cnt) a^=nums[i];
            else b^=nums[i];
        }
        return {a,b};
    }
};