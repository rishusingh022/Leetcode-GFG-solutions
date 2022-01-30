// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
    int lower,upper;
    int pivotValue(int arr[],int l,int h){
        int mid=l+(h-l)/2;
        if(mid==lower){
            if(arr[mid]<=arr[mid+1]){
                return mid;
            }
        }
        else if(mid==upper){
            if(arr[mid]<=arr[mid-1]){
                return mid;
            }
        }
        else if(arr[mid]<=arr[mid+1] && arr[mid]<=arr[mid-1]){
            return mid;
        }
        else{
            if(arr[mid]<=arr[mid+1] && arr[mid]<=arr[mid-1]){
                return mid;
            }
            else if(arr[mid]>arr[h]){
                return pivotValue(arr,mid+1,h);
            }
            else if(arr[mid]<arr[h]){
                return pivotValue(arr,l,mid-1);
            }
        }
    }
	int findKRotation(int arr[], int n) {
	    // code here
	    lower=0;
	    upper=n-1;
	    int ind=pivotValue(arr,0,n-1);
	    return ind;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends