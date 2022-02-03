// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    int findNext (int n) 
    {
        //code here.
        int temp=n;
        vector<int> arr;
        while(temp>0){
            arr.push_back(temp%10);
            temp=temp/10;
        }
        reverse(arr.begin(),arr.end());
        next_permutation(arr.begin(),arr.end());
        int res=0;
        //for(auto i:arr) cout<<i<<" ";
        for(int i=0;i<arr.size();i++){
            res=res*10+arr[i];
        }
        if(n>=res) return -1;
        return res;
    }  
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n; cin >> n;
		Solution ob;
		int res = ob.findNext (n);
		if (res == -1)
		    cout << "not possible";
		else
		    cout << res;
		cout << endl; 
	}
}  // } Driver Code Ends