class Solution {
public:
    int arrayPairSum(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int sum=0;
        for(int i=0;i<arr.size();i++){
            if(i%2!=0) continue;
            sum+=arr[i];
        }
        return sum;
    }
};