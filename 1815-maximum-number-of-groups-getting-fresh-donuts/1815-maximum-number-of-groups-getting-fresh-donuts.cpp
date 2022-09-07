class Solution {
public:
int n;
map<vector<int>,int> m; 
int bs;
int solve(vector<int> cnt,int left){
    if(m.find(cnt)!=m.end()){
        return m[cnt];
    }
    int lim=cnt.size();
    int temp=0;
    for(int i=1;i<lim;i++){
        if(cnt[i]>0){
            cnt[i]--;
            temp=max(temp,(left==0)+solve(cnt,(left+bs-i)%lim));
            cnt[i]++;
        }
    }
    m[cnt]=temp;
    return m[cnt];
}
int maxHappyGroups(int batchSize,vector<int>&groups){
    int n=groups.size();
    int res=0;
    vector<int> cnt(batchSize,0);
    for(auto i:groups){
        if(i%batchSize==0){
            res++;
        }
        else if(cnt[batchSize-i%batchSize]>=1){
            res++;
            cnt[batchSize-i%batchSize]--;
        }
        else{
            cnt[i%batchSize]++;
        }
    }
    return solve(cnt,0)+res;
}
};