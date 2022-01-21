class Solution {
public:
    vector<int> sortByBits(vector<int>& a) {
        vector<int> arr=a;
        sort(arr.begin(),arr.end(),[](int a,int b){
            int cnt1=0;
            int c,d;
            c=a;
            d=b;
            while(a>0){
                if(a&1) cnt1++;
                a=a>>1;
            }
            int cnt2=0;
            while(b>0){
                if(b&1) cnt2++;
                b=b>>1;
            }
            if(cnt1!=cnt2){
                if(cnt1<cnt2){
                    return true;
                }
                else return false;
            }
            if(c<d) return true;
            else return false;
        });
        return arr;
    }
};