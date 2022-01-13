// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    int maxWater(int arr[], int n) {
        int left[n];
        int right[n];
        left[0]=arr[0];
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],arr[i]);
        }
        right[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],arr[i]);
        }
        int water_stored=0;
        for(int i=0;i<n;i++){
            if(min(right[i],left[i])-arr[i]>0){
                water_stored+=min(right[i],left[i])-arr[i];
            }
        }
        return water_stored;
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