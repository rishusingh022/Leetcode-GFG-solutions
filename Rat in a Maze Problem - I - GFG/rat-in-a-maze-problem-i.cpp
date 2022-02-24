// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isSafe(int row,int col,vector<vector<int>> &m,int n,vector<vector<bool>> &vis){
        if(row==-1 || row==n || col==-1 || col==n || vis[row][col] || m[row][col]==0){
            return false;
        }
        return true;
    }
    void solve(int row,int col,vector<vector<int>> &m,int n,string &path,vector<string> &res,vector<vector<bool>> &vis){
        if(row==-1 || row==n || col==-1 || col==n || vis[row][col] || m[row][col]==0){
            return;
        }
        if(row==n-1 && col==n-1){
            res.push_back(path);
            return;
        }
        vis[row][col]=true;
        if(isSafe(row+1,col,m,n,vis)){
            path.push_back('D');
            solve(row+1,col,m,n,path,res,vis);
            path.pop_back();
        }
        if(isSafe(row,col-1,m,n,vis)){
            path.push_back('L');
            solve(row,col-1,m,n,path,res,vis);
            path.pop_back();
        }
        if(isSafe(row-1,col,m,n,vis)){
            path.push_back('U');
            solve(row-1,col,m,n,path,res,vis);
            path.pop_back();
        }
        if(isSafe(row,col+1,m,n,vis)){
            path.push_back('R');
            solve(row,col+1,m,n,path,res,vis);
            path.pop_back();
        }
        vis[row][col]=false;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> res;
        string ans;
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        solve(0,0,m,n,ans,res,vis);
        return res;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends