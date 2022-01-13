class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int ans=arr[0];
        int prod=1;
        int n=arr.size();
        for(int i=0;i<n;i++){
            prod*=arr[i];
            ans=max(ans,prod);
            if(arr[i]==0){
                prod=1;
            }
        }
        prod=1;
        for(int i=n-1;i>=0;i--){
            prod*=arr[i];
            ans=max(ans,prod);
            if(arr[i]==0){
                prod=1;
            }
        }
        return ans;
    }
};