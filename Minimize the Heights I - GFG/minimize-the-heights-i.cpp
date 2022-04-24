// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr,arr+n);
        int max_ele=arr[n-1],min_ele=arr[0];
        int a=arr[0]+k;
        int b=arr[n-1]-k;
        int res=max_ele-min_ele;
        for(int i=1;i<n;i++){
            max_ele=max(arr[i-1]+k,b);
            min_ele=min(arr[i]-k,a);
            res=min(res,max_ele-min_ele);
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends