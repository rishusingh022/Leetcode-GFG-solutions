class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>> pq;
        for(auto i:mp){
            pq.push({i.second,i.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top()[1]);
            pq.pop();
        }
        return res;
    }
};