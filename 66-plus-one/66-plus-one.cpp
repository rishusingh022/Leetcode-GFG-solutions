class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        int carry=0;
        if(digits[0]!=9){
            digits[0]+=1;
            reverse(digits.begin(),digits.end());
            return digits;
        }
        else{
            digits[0]=0;
            carry=1;
            for(int i=1;i<digits.size();i++){
                if(digits[i]==9){
                    digits[i]=0;
                    carry=1;
                }
                else{
                    digits[i]+=carry;
                    carry=0;
                    break;
                }
            }
            if(carry>0) digits.push_back(carry);
            reverse(digits.begin(),digits.end());
            return digits;
        }
    }
};