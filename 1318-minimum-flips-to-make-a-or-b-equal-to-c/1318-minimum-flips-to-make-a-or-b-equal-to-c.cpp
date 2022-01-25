class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count=0;
        while(a>0 || b>0 || c>0){
            int ai=a%2;
            int bi=b%2;
            int ci=c%2;
            if(ci==1)
            {
                if(ai==0 && bi==0)
                    count++;
            } 
            else if(ci==0)
            {
                if(ai==1 && bi==1)
                    count+=2;
                else if(ai==1 || bi==1)
                    count++;
            }
            a/=2;
            b/=2;
            c/=2;
        }
        return count;
    }
};