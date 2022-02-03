class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 0;
        }
        int start=0;
        int end=nums.size()-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(mid==0 && nums[mid]>nums[mid+1])
                  return mid;
            if(mid==n-1 && nums[mid]>nums[mid-1])
                  return mid;
            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1])
                  return mid;
            else if(nums[mid]<nums[mid+1])
                start=mid+1;
            else
                end=mid-1;    
        }
       return -1;
     }
};