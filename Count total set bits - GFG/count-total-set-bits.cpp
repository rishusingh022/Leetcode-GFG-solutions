// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int solve(int n){
        int x=0;
        while((1<<x)<=n){
            x++;
        }
        return x-1;
        
    }
    int final_ans(int n){
        if(n==0 || n==1) return n;
        int x=solve(n);
        int sum2rx=(1<<(x-1))*x;
        int sum2grx=n-(1<<x)+1;
        int sumofrest=final_ans(n-(1<<x));
        return sum2rx+sum2grx+sumofrest;
    }
    int countSetBits(int n)
    {
        // Your logic here
        return final_ans(n);
    }
};


// { Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}
  // } Driver Code Ends