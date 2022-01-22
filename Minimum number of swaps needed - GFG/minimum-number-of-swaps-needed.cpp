// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
    int merge(vector<int> &arr,int l,int mid,int r){
        int inv=0;
        int n1=mid-l+1;
        int n2=r-mid;
        vector<int> temp1(n1);
        for(int i=0;i<n1;i++){
            temp1[i]=arr[l+i];
        }
        vector<int> temp2(n2);
        for(int i=0;i<n2;i++){
            temp2[i]=arr[mid+1+i];
        }
        int i=0,j=0,k=l;
        while(i<n1 && j<n2){
            if(temp1[i]<=temp2[j]){
                arr[k++]=temp1[i++];
            }
            else{
                arr[k++]=temp2[j++];
                inv+=(n1-i);
            }
        }
        while(i<n1){
            arr[k++]=temp1[i++];
        }
        while(j<n2){
            arr[k++]=temp2[j++];
        }
        return inv;
        
    }
    int mergeSort(vector<int>&arr,int l,int r){
        
        int inv=0;
        if(l<r){
            int mid=(l+r)/2;
            inv+=mergeSort(arr,l,mid);
            inv+=mergeSort(arr,mid+1,r);
            inv+=merge(arr,l,mid,r);
        }
        return inv;
    }
	int countSwaps(int a[], int n)
	{
	    // Your code goes here
	    vector<int> arr(n,0);
	    for(int i=0;i<n;i++){
	        arr[i]=a[i];
	    }
	    
	    int ans=mergeSort(arr,0,n-1);
	    //for(auto i:arr) cout<<i<<" ";
	    return ans;
	}
};

// { Driver Code Starts.

int main() 
{
   
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countSwaps(arr, n);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends