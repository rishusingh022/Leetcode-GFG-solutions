class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper) {
        long long ans=0;
        long long mi=0;
        long long mx=0;
        for(int i=0;i<diff.size();i++){
            ans+=diff[i];
            mi=min(mi,ans);
            mx=max(mx,ans);
        }
        cout<<mi<<" "<<mx;
        long long temp=(long long)upper-lower;
        if(temp-(mx-mi)+1>0){
            return temp-(mx-mi)+1;
        }
        else{
            return 0;
        }
    }
};