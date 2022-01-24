class Solution {
public:
    int numberOfWays(string c) {
        
        int mod=pow(10,9)+7;
        vector<int> pos;
        int n=c.size();
        for(int i=0;i<n;i++){
            if(c[i]=='S'){
                pos.push_back(i);
            }
        }
        if(pos.size()==0 || pos.size()%2!=0){
            return 0;
        }
        long long ans=1;
        int prev=pos[1];
        for(int i=2;i<pos.size();i+=2){
            int len=pos[i]-prev;
            ans=(ans*len)%mod;
            prev=pos[i+1];
        }
        return ans;
    }
};