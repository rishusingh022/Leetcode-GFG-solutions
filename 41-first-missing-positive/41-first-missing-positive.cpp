class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]>=1 && arr[i]<n){
                if(arr[i]!=arr[arr[i]-1]){
                    swap(arr[i],arr[arr[i]-1]);
                    i--;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]!=i+1){
                return i+1;
            }
        }
        return n+1;
    }
};