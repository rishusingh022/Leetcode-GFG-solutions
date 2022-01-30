class Solution {
public:
    int findFinalValue(vector<int>& nums, int o) {
        int n=nums.size();
        set<int> s;
        int t=o;
        for(auto i:nums) s.insert(i);
        while(1){
            if(s.find(t)!=s.end()){
                t*=2;
            }
            else{
                break;
            }
        }
        return t;
    }
};