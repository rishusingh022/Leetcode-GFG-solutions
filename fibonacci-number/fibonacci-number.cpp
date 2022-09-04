class Solution {
public:
    map<int,int> mp;
    int fib(int n) {
        if(n==0 || n==1){
            return n;
        }
        if(mp.find(n)!=mp.end()){
            return mp[n];
        }
        return mp[n]=fib(n-1)+fib(n-2);
    }
};