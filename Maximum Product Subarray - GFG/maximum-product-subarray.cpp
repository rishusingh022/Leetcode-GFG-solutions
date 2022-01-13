// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    long long max_ending_here=1,min_ending_here=1;
	    long long max_so_far=0;
	    int flag=0;
	    if(n==1){
	        return arr[0];
	    }
	    for(int i=0;i<n;i++){
	        if(arr[i]>0){
	            max_ending_here=max_ending_here*arr[i];
	            min_ending_here=min(min_ending_here*arr[i],(long long)1);
	        }
	        else if(arr[i]==0){
	            max_ending_here=1;
	            min_ending_here=1;
	        }
	        else{
	            long long temp=max_ending_here;
	            max_ending_here=max(min_ending_here*arr[i],(long long)1);
	            min_ending_here=temp*arr[i];
	        }
	        if(max_ending_here>max_so_far){
	            max_so_far=max_ending_here;
	        }
	    }
	    if(flag==0 && max_so_far==0){
	        return 0;
	    }
	    return max_so_far;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends