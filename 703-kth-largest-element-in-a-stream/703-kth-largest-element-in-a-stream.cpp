class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int t;
    KthLargest(int k, vector<int>& nums) {
        t=k;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()>k) pq.pop();
        }
       
    }
    int add(int val) {
        if(pq.size()<t){
            pq.push(val);
            return pq.top();
        }
        pq.push(val);
        pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */