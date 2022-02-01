class Solution {
public:
    int pivot(vector<int> &arr,int start,int end,int n){
        int mid;
        int next,prev;
        while(start<=end){
            mid=start+(end-start)/2;
            next=(mid+1)%n;
            prev=(mid+n-1)%n;
            //cout<<prev<<" "<<mid<<" "<<next<<endl;
            if(arr[mid]<=arr[next] && arr[mid]<=arr[prev]){
                return mid;
            }
            else if(arr[0]<=arr[mid]){
                start=mid+1;
            }
            else if(arr[mid]<=arr[n-1]){
                end=mid-1;
            }
        }
        return -1;
    }
    int binarySearch(vector<int>& arr, int target,int start,int end){
        int mid;
        while(start<=end){
            mid=start+(end-start)/2;
            if(arr[mid]==target){
                return mid;
            }
            else if(arr[mid]>target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int ind=pivot(nums,0,n-1,n);
        if(ind==-1) return binarySearch(nums,target,0,n-1);
        if(nums[ind]==target) return ind;
        int res=-1;
        res=binarySearch(nums,target,0,ind-1);
        if(res==-1){
            res=binarySearch(nums,target,ind+1,n-1);
        }
        return res;
    }
};