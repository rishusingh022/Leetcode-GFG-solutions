class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n=nums.size();
        vector<int> pref(n);
        vector<int> suf(n);
        int count0=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                count0++;
            }
            pref[i]=count0;
        }
        count0=0;
        for(int i=n-1;i>=0;i--){
            if(nums[i]==1){
                count0+=1;
            }
            suf[i]=count0;
        }
        unordered_map<int,vector<int>> mp;
        int mx=INT_MIN;
        for(int i=0;i<=n;i++){
            if(i==0){
                mx=max(mx,suf[i]);
                mp[suf[i]].push_back(i);
                continue;
            }
            if(i==n){
                mx=max(mx,pref[i-1]);
                mp[pref[i-1]].push_back(i);
                continue;
            }
            mx=max(mx,pref[i-1]+suf[i]);
            mp[pref[i-1]+suf[i]].push_back(i);
        }
        return mp[mx];
    }
};