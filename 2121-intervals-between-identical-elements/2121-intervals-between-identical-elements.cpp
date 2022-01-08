class Solution {
public:
    void print(vector<long long> arr){
        for(auto i:arr){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    vector<long long> getDistances(vector<int>& arr) {
        map<int,vector<int>> mp;
        vector<long long> ans(arr.size(),0);
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        int n=arr.size();
        vector<long long> pref(n,0);
        for(auto a:mp){
            vector<int> temp=a.second;
            for(int i=1;i<temp.size();i++){
                pref[temp[i]]=pref[temp[i-1]]+(long long)i*(long long)(temp[i]-temp[i-1]);
            }
        }
        vector<long long> suf(n,0);
        for(auto a:mp){
            vector<int> temp=a.second;
            for(int i=temp.size()-2;i>=0;i--){
                suf[temp[i]]=suf[temp[i+1]]+(long long)(temp.size()-1-i)*(long long)(temp[i+1]-temp[i]);
            }
        }
        for(int i=0;i<n;i++){
            ans[i]=pref[i]+suf[i];
        }
        return ans;
    }
};