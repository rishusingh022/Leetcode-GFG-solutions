class Solution {
public:
    int n;
    map<vector<int>,int> m; 
    int bs;
    int solve(vector<int> cnt,int left){
    if(m.find(cnt)!=m.end()){
    return m[cnt];
    }
    int lim=cnt.size(); int temp=0;
    for(int i=1;i<lim;i++){
    if(cnt[i]>=1){//if a no. exists whose mod with batchsize gives remainder 1, then move along
    cnt[i]--;
    temp=max(temp,(left==0)+solve(cnt,(left+bs-i)%lim));
    cnt[i]++;
    }

        }
        m[cnt]=temp;
        return m[cnt];
    }
    int maxHappyGroups(int b, vector<int>& groups) {
        n=groups.size(); int res=0; vector<int> cnt(b,0);
        bs=b;
        for(int i=0;i<n;i++){
            if(groups[i]%b==0){
                res++;
            }
            else if(cnt[b-groups[i]%b]>=1){
                res++; cnt[b-groups[i]%b]--;
            }
            else{
                cnt[groups[i]%b]++;
            }
        }
        return solve(cnt,0)+res;
        
    }
};