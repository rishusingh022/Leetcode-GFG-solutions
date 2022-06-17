class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long s=0,e=0,res=0,sum=nums[0];
        long long n=nums.size();
        while(s<n and e<n){
            if(sum*(e-s+1)<k){
                e++;
                if(e>=s){
                    res+=e-s;
                }
                if(e<n){
                    sum+=nums[e];
                }
            }
            else{
                sum-=nums[s];
                s++;
            }
        }
        return res;
    }
};