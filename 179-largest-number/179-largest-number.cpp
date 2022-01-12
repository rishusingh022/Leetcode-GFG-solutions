class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int count_0=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count_0++;
            }
        }
        if(count_0==nums.size()){
            return "0";
        }
        sort(nums.begin(),nums.end(),[](int num1,int num2){
            vector<int> temp1;
            vector<int> temp2;
            if(num1==num2){
                return true;
            }
            if(num1==0){
                temp1.push_back(0);
            }
            if(num2==0){
                temp2.push_back(0);
            }
            while(num1>0){
                temp1.push_back(num1%10);
                num1=num1/10;
            }
            while(num2>0){
                temp2.push_back(num2%10);
                num2=num2/10;
            }
            int n=temp1.size();
            int m=temp2.size();
            reverse(temp2.begin(),temp2.end());
            reverse(temp1.begin(),temp1.end());
            vector<int> temp3;
            for(auto i:temp1){
                temp3.push_back(i);
            }
            for(auto i:temp2){
                temp3.push_back(i);
            }
            vector<int> temp4;
            for(auto i:temp2){
                temp4.push_back(i);
            }
            for(auto i:temp1){
                temp4.push_back(i);
            }
            
            for(int i=0;i<n+m;i++){
                if(temp3[i]!=temp4[i]){
                    if(temp3[i]>temp4[i]){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
            }
            return true;
        });
        
        string ans="";
        for(auto i:nums){
            ans+=to_string(i);
        }
        return ans;
        
    }
};