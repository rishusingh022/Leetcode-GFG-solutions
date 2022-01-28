class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto i:mp){
            pq.push(make_pair(i.second,i.first));
        }
        string ans="";
        while(!pq.empty()){
            char c=pq.top().second;
            int freq=pq.top().first;
            while(freq--){
                ans+=c;
            }
            pq.pop();
        }
        return ans;
    }
};