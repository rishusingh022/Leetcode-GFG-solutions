// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

bool compare(int a,int b) {
    int cnta = 0;
    int cntb = 0;
    while(a>0) {
        ++cnta;
        a = a&(a-1);
    }
    while(b>0) {
        ++cntb;
        b = b&(b-1);
    }
    if(cnta != cntb) {
        return cnta > cntb;
    }
    return a<b;
}
class Solution{
    public: 
    void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
        stable_sort(arr,arr+n,compare);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends