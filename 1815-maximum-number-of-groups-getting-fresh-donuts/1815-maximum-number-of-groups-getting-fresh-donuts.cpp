class Solution {
public:

int solve(vector<int> cnt,int left,int bs,int n,map<vector<int>,int> &m){
    if(m.find(cnt)!=m.end()){
        return m[cnt];
    }
    int lim=cnt.size();
    int temp=0;
    for(int i=1;i<lim;i++){
        if(cnt[i]>0){
            cnt[i]--;
            temp=max(temp,(left==0)+solve(cnt,(left+bs-i)%lim,bs,n,m));
            cnt[i]++;
        }
    }
    m[cnt]=temp;
    return m[cnt];
}
int maxHappyGroups(int batchSize,vector<int>&groups){
    int n=groups.size();
    int yo=0;
    map<vector<int>,int> m; 
    int bs;
    vector<int> cnt(batchSize,0);
    for(auto i:groups){
        if(i%batchSize==0){
            yo++;
        }
        else if(cnt[batchSize-i%batchSize]>=1){
            yo++;
            cnt[batchSize-i%batchSize]--;
        }
        else{
            cnt[i%batchSize]++;
        }
    }
    return solve(cnt,0,bs,n,m)+yo;
}
};