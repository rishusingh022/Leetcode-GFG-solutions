class Solution {
public:
    void solve(int num,int &cnt){
        if(num==0){
            return;
        }
        if(num%2==0){
            solve(num/2,++cnt);
        }
        else{
            solve(num-1,++cnt);
        }
    }
    int numberOfSteps(int num) {
        int cnt=0;
        solve(num,cnt);
        return cnt;
    }
};