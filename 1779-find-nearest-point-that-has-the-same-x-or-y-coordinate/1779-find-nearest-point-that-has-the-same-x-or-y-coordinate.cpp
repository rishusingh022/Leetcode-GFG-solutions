class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& p) {
        auto cmp=[&](array<int,2> a,array<int,2> b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]>b[0];
        };
        priority_queue<array<int,2>,vector<array<int,2>>,decltype(cmp)> pq(cmp);
        int key;
        for(int i=0;i<p.size();i++){
            if(p[i][0]!=x && p[i][1]!=y) continue;
            key=abs(x-p[i][0])+abs(y-p[i][1]);
            pq.push({key,i});
        }
        // while(!pq.empty()){
        //     cout<<pq.top()[0]<<"-->"<<pq.top()[1];
        //     cout<<endl;
        //     pq.pop();
        // }
        if(pq.empty()) return -1;
        return pq.top()[1];
    }
};