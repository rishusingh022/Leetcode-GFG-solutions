class Solution {
public:
    int clumsy(int n) {
        if(n==1 ||n==2){
            return n;
        }
        int clumsy_fac= n * (n-1) / (n-2) + (n-3);
        n-=4;
        while(n>3){
            clumsy_fac=clumsy_fac- n * (n-1) / (n-2) + (n-3);
            n-=4;
        }
        if(n==1){
            clumsy_fac-=1;
        }
        else if(n==2){
            clumsy_fac-=2;
        }
        else if(n==3){
            clumsy_fac-=6;
        }
        return clumsy_fac;
    }
};