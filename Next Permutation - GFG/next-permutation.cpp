// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void solve(vector<int> arr,int l,int r){
        if(l==r){
            for(int i=0;i<arr.size();i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        for(int i=l;i<=r;i++){
            swap(arr[l],arr[i]);
            solve(arr,l+1,r);
            swap(arr[l],arr[i]);
        }
    }
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int ind1=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                ind1=i;
                break;
            }
        }
        if(ind1==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        int ind2=-1;
        for(int i=n-1;i>=0;i--){
            if(nums[i]>nums[ind1]){
                ind2=i;
                break;
            }
        }
        swap(nums[ind1],nums[ind2]);
        reverse(nums.begin()+ind1+1,nums.end());
    }
    vector<int> nextPermutation(int n, vector<int> arr){
        // code here
        nextPermutation(arr);
        return arr;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends