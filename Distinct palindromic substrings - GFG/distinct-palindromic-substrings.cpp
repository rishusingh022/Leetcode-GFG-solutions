// { Driver Code Starts
// C++ program to find all distinct palindrome sub-strings
// of a given string
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

set<string>st;
bool isPalindrome(int i, int j, string &s, vector<vector<int>>&dp){
    if(i>=j) 
    return 1;

    if(dp[i][j]!=-1) 
    return dp[i][j];

    if(s[i]!=s[j]) 
    return dp[i][j] = 0;

    return dp[i][j] = isPalindrome(i+1,j-1,s,dp);
}

class Solution{
  public:
    int palindromeSubStrs(string s) {
      st=set<string>();
      int n=s.size();
        vector<vector<int>>dp(n, vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,s,dp)){
                    st.insert(s.substr(i,j-i+1));
                }
            }
        }
        return st.size();
    }
};

// { Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.palindromeSubStrs(str) << endl;
    }
    return 0;
}
  // } Driver Code Ends