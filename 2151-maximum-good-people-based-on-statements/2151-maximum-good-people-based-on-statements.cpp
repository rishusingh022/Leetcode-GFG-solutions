class Solution {
public:
    int maximumGood(vector<vector<int>>& s) {
        int n=s.size();
        int states=pow(2,n);
        
        auto check=[&](int m){
            for(int i=0;i<n;i++){
                if(m>>i&1){
                    for(int j=0;j<n;j++){
                        int good=m>>j&1;
                        if((s[i][j]==0 and good==1) || (s[i][j]==1 and good==0)) return false;
                    }
                }
            }
            return true;
        };
        int ans=0;
        for(int i=1;i<states;i++){
            if(check(i)) ans=max(ans,__builtin_popcount(i));
        }
        return ans;
    }
};