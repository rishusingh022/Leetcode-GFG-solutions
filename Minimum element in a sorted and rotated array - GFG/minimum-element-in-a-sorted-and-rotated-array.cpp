// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
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
    int findMin(int arr[], int n){
        lower=0;
        upper=n-1;
        return arr[pivotValue(arr,0,n-1)];
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}  // } Driver Code Ends