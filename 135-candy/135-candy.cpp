class Solution {
public:
    int candy(vector<int>& r) {
        int n=r.size();
        vector<int> ans(n,1);
        //sort(r.begin(),r.end());
        for(int i=1;i<n;i++){
            if(r[i]>r[i-1]){
                ans[i]=ans[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(r[i]>r[i+1] && ans[i]<=ans[i+1]){
                ans[i]=ans[i+1]+1;
            }
        }
        // for(auto i:ans) cout<<i<<" ";
        // cout<<endl;
        // for(auto i:r) cout<<i<<" ";
        
        return accumulate(ans.begin(),ans.end(),0);
    }
};