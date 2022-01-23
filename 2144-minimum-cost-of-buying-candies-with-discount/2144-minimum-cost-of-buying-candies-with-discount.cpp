class Solution {
public:
    int minimumCost(vector<int>& c) {
        sort(c.begin(),c.end());
        int n=c.size();
        int cnt=0;
        int cost=0;
        for(int i=n-1;i>=0;i--){
            if(cnt==2){
                cnt=0;
                continue;
            }
            cnt++;
            cost+=c[i];
        }
        return cost;
    }
};