class Solution {
public:
    bool isPrime(int n){
        if(n==0 || n==1){
            return false;
        }
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0) return false;
        }
        return true;
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