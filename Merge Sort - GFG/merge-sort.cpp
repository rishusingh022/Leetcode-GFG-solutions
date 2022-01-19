// { Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


 // } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int mid, int r)
    {
         // Your code here
         int n1=mid-l+1;
         int n2=r-mid;
         int a[n1];
         int b[n2];
         int j=0;
         for(int i=l;i<=mid;i++){
             a[j++]=arr[i];
         }
         j=0;
         for(int i=mid+1;i<=r;i++){
             b[j++]=arr[i];
         }
         int i=0;
         j=0;
         int k=l;
         while(i<n1 && j<n2){
             if(a[i]<b[j]){
                 arr[k]=a[i];
                 i++;k++;
             }
             else{
                 arr[k]=b[j];
                 j++;k++;
             }
         }
         while(i<n1){
             arr[k++]=a[i++];
         }
         while(j<n2){
             arr[k++]=b[j++];
         }
    }
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l<r){
            int mid=(l+r)/2;
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            merge(arr,l,mid,r);
        }
    }
};

// { Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends