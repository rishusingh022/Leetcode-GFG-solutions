class Solution {
public:
    vector<int> frequencySort(vector<int>& s) {
        unordered_map<int,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        auto cmp=[](pair<int,int> a,pair<int,int> b){
            if(a.first==b.first){
                return a.second<b.second;
            }
            return a.first>b.first;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
        for(auto i:mp){
            pq.push(make_pair(i.second,i.first));
        }
        int i=0;
        while(!pq.empty()){
            int c=pq.top().second;
            int freq=pq.top().first;
            while(freq--){
               s[i++]=c; 
            }
            pq.pop();
        }
        return s;
    }
};