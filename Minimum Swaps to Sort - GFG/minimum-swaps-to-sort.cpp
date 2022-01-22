// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int n=nums.size();
	    vector<bool> vis(n,false);
	    vector<pair<int,int>> arr;
	    
	    for(int i=0;i<n;i++){
	        arr.push_back({nums[i],i});
	        //vis[nums[i]]=false;
	    }
	    
	    sort(arr.begin(),arr.end());
	    
	    int ans=0;
	    for(int i=0;i<arr.size();i++){
	        int cycle=0;
	        int ind=arr[i].second;
	        while(!vis[ind]){
	            cycle++;
	            vis[ind]=true;
	            ind=arr[ind].second;
	        }
	        //cout<<cycle<<" ";
	        if(cycle!=0) ans+=(cycle-1);
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends