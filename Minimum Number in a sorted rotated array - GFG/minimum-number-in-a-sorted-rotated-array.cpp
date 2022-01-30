// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
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
    //Function to find the minimum element in sorted and rotated array.
    int minNumber(int arr[], int low, int high)
    {
        // Your code here
        lower=low;
        upper=high;
        return arr[pivotValue(arr,low,high)];
        
    }
};

// { Driver Code Starts.


int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];	
		Solution obj;
		cout << obj.minNumber(a,0,n-1) << endl;
	}
	return 0;
}  // } Driver Code Ends