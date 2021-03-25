#include <iostream>
#include <algorithm>
#include <vector>
class Solution {
public:
    int binarySearchRecursive(vector<int>& arr, int l, int r, int x){
        if (r >= l) { 
            int mid = l + (r - l) / 2; 
            if (arr[mid] == x){
                arr[mid]=-1;
                return mid; 
            }
            if (arr[mid] > x) 
                return binarySearchRecursive(arr, l, mid - 1, x); 
            return binarySearchRecursive(arr, mid + 1, r, x); 
        }
        return -1; 
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        while(binarySearchRecursive(nums,0,nums.size()-1,target)!=-1){
            sort(nums.begin(),nums.end());
            int a=binarySearchRecursive(nums,0,nums.size()-1,target);
            result.push_back(a);
        }
        return result;
    }
};
int main(){
    Solution s;
    vector<int> nums={5,7,7,8,8,10};
    int target=8;
    vector<int> result=s.searchRange(nums,target);
}