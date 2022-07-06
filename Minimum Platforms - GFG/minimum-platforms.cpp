// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	vector<int> yo(2360,0);
    	
    	for(int i=0;i<n;i++){
    	    yo[arr[i]]++;
    	    //if(dep[i]<yo.size()-1){
    	        yo[dep[i]+1]--;
    	    //}
    	}
    	int res=yo[0];
    	for(int i=1;i<yo.size();i++){
    	    yo[i]+=yo[i-1];
    	    res=max(yo[i],res);
    	}
    	return res;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends