class Solution {
public:
    map<int,int> mp;
    int climbStairs(int n) {
        if(n==1 || n==2){
            return n;
        }
        if(mp.find(n)!=mp.end()){
            return mp[n];
        }
        return mp[n]=climbStairs(n-2)+climbStairs(n-1);
    }
};