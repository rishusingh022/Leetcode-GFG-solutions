class Solution {
public:
    void solve(int num1,int num2,int &cnt){
        if(num1==0 || num2==0){
            return;
        }
        if(num1>=num2){
            solve(num1-num2,num2,++cnt);
        }
        else{
            solve(num1,num2-num1,++cnt);
        }
    }
    int countOperations(int num1, int num2) {
        int cnt=0;
        solve(num1,num2,cnt);
        return cnt;
    }
};