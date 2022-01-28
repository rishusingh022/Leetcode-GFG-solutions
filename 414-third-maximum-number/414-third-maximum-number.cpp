class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for(auto i:nums) s.insert(i);
        if(s.size()<3){
            return *max_element(nums.begin(),nums.end());
        }
        else{
            int k=3;
            auto it=s.end();
            while(k--){
                it--;
            }
            return *it;
        }
    }
};