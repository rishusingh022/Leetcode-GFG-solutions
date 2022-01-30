// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int lower,upper;
    int pivot(int arr[],int l,int h){
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
                return pivot(arr,mid+1,h);
            }
            else if(arr[mid]<arr[h]){
                return pivot(arr,l,mid-1);
            }
        }
    }
    int binarySearch(int arr[], int l, int h, int key){
        while(l<=h){
            int mid=l+(h-l)/2;
            if(arr[mid]==key){
                return mid;
            }
            else if(arr[mid]>key){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return -1;
    }
    
    int search(int arr[], int l, int h, int key){
    //complete the function here
         lower=l;
         upper=h;
         int ind=pivot(arr,l,h);
         //cout<<arr[ind]<<endl;
         if(arr[ind]==key){
             return ind;
         }
         
         else{
             int ind1=binarySearch(arr,l,ind,key);
             int ind2=binarySearch(arr,ind+1,h,key);
             if(ind1!=-1) return ind1;
             if(ind2!=-1) return ind2;
         }
    }
};

// { Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}  // } Driver Code Ends