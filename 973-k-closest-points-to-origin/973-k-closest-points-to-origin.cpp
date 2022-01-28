class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        priority_queue<array<int,3>> pq;
        int key;
        for(int i=0;i<p.size();i++){
            key=p[i][0]*p[i][0]+p[i][1]*p[i][1];
            pq.push({key,p[i][0],p[i][1]});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>> res;
        while(!pq.empty()){
            res.push_back({pq.top()[1],pq.top()[2]});
            pq.pop();
        }
        return res;
    }
};