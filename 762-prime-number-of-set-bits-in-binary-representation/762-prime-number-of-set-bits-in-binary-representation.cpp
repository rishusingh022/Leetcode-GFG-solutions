class Solution {
public:
    bool isPrime(int x){
        return (x == 2 || x == 3 || x == 5 || x == 7 ||
                x == 11 || x == 13 || x == 17 || x == 19);
    }
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(int i=left;i<=right;i++){
            int temp=i;
            int  cnt=0;
            while(temp>0){
                cnt++;
                temp=temp&(temp-1);
            }
            if(isPrime(cnt)){
                ans++;
            }
        }
        return ans;
    }
};