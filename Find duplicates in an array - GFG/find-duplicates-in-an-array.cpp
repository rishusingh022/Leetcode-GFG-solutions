// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            if(arr[i]!=i){
                if(arr[arr[i]]==arr[i]){
                    continue;
                }
                swap(arr[i],arr[arr[i]]);
                i--;
            }
        }
        
        //cout<<endl;
        for(int i=0;i<n;i++){
            if(arr[i]!=i){
                ans[arr[i]]=arr[i];
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<ans[i]<<" ";
        // }
        vector<int> temp;
        for(auto i:ans){
            if(i!=-1){
                temp.push_back(i);
            }
        }
        if(temp.size()==0){
            return {-1};
        }
        return temp;
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends