class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        set<pair<int,int>> s;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            
            for(int j=i+1;j<n;j++){
                
                if(abs(nums[j]-nums[i])==k){
                    s.insert(make_pair(nums[i],nums[j]));
                }
            }
        }
        return s.size();
    }
};