class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum=0;
        for(auto i:arr) sum+=i;
        int temp_sum=0;
        int count=0;
        if(sum%3!=0) return false;
        for(auto i:arr){
            temp_sum+=i;
            if(temp_sum==sum/3) {
                temp_sum=0;
                count++;
            }
        }
        return count>=3;
    }
};