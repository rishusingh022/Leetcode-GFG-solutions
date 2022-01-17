// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& arr1, vector<int>& arr2)
    {
        // Your code goes here
        
        int n=arr1.size();
        int m=arr2.size();
        int i=0,j=0,k=n-1;
        while(i<=k && j<m){
            if(arr1[i]<arr2[j]){
                i++;
            }
            else{
                swap(arr1[k--],arr2[j++]);
            }
        }
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());
        vector<int> arr3(n+m);
        merge(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), arr3.begin());
        //for(auto i:arr3) cout<<i<<" ";
        if(arr3.size()%2==0){
            return (double)(arr3[arr3.size()/2-1]+arr3[arr3.size()/2])/2;
        }
        else{
            return arr3[arr3.size()/2];
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends