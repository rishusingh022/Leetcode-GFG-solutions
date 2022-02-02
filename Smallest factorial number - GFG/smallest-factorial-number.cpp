// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
        bool isValid(int num,int n){
            int cnt=0;
            int f=5;
            int temp=num;
            while(f<=temp){
                cnt+=(temp/f);
                f*=5;
            }
            return (cnt>=n);
        }
        int findNum(int n)
        {
            int s=0;
            int e=5*n;
            int res=-1;
            while(s<=e){
                int mid=s+(e-s)/2;
                if(isValid(mid,n)==true){
                    res=mid;
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }
            }
            return res;
        }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends