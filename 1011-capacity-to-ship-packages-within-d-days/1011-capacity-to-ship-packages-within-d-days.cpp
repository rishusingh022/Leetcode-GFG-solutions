class Solution {
public:
    bool isPossible(vector<int>&arr,int n,int d,int mid){
        int cnt=1;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum>mid){
                cnt++;
                sum=arr[i];
            }
            if(cnt>d){
                return false;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int s=*max_element(weights.begin(),weights.end());
        int e=accumulate(weights.begin(),weights.end(),0);
        int res=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(isPossible(weights,n,days,mid)==true){
                res=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return res;
    }
};