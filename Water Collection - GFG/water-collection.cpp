// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    int maxWater(int a[], int n) {
          int left[n];
     int right[n];
     
     left[0]=a[0];
     for(int i=1;i<n;i++){
         left[i]=max(a[i],left[i-1]);
     }
     
     right[n-1]=a[n-1];
     
     for(int i=n-2;i>=0;i--){
         right[i]=max(a[i],right[i+1]);
     }
     
     long int ans=0;
     for(int i=0;i<n;i++){
         ans=ans+(min(left[i],right[i])-a[i]);
     }
     
     return ans; 
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxWater(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends