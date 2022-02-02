class Solution {
public:
    int trailingZeroes(int n) {
        int cnt=0;
        int temp=n;
        int f=5;
        while(f<=temp){
            cnt+=(temp/f);
            f*=5;
        }
        return cnt;
    }
};