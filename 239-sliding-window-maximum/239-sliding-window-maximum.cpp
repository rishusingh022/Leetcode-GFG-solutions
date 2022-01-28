class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<array<int,2>> pq;
        int n=nums.size();
        for(int i=0;i<k;i++){
            pq.push({nums[i],i});
        }
        vector<int> res;
        res.push_back(pq.top()[0]);
        for(int i=k;i<n;i++){
            pq.push({nums[i],i});
            while(!pq.empty() && pq.top()[1]<=i-k){
                pq.pop();
            }
            res.push_back(pq.top()[0]);
        }
        return res;
    }
};