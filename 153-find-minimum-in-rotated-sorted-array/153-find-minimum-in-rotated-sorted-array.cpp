class Solution {
public:
    int pivot(vector<int> &arr,int start,int end,int n){
        int mid,prev,next;
        while(start<=end){
            mid=start+(end-start)/2;
            prev=(mid-1+n)%n;
            next=(mid+1)%n;
            if(arr[mid]<=arr[prev] && arr[mid]<=arr[next]){
                return mid;
            }
            else if(arr[mid]>=arr[0]){
                start=mid+1;
            }
            else if(arr[mid]<=arr[n-1]){
                end=mid-1;
            }
        }
        return -1;
    }
    int findMin(vector<int>& nums) {
        int ind=pivot(nums,0,nums.size()-1,nums.size());
        if(ind==-1) return nums[0];
        else return nums[ind];
    }
};