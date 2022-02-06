class Solution {
public:
    int minimumSum(int num) {
        int mi=num;
        vector<int> arr;
        int temp=num;
        while(temp>0){
            arr.push_back(temp%10);
            temp=temp/10;
        }
        sort(arr.begin(),arr.end());
        return (arr[0]*10+arr[3])+(arr[1]*10+arr[2]);
    }
};