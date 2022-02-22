// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool checkforCycle(int s,int v,vector<int> adj[],vector<int> &vis){
        queue<array<int,2>> q;
        q.push({s,-1});
        vis[s]=true;
        while(q.empty()!=true){
            int node=q.front()[0];
            int par=q.front()[1];
            q.pop();
            for(auto i:adj[node]){
                if(!vis[i]){
                    vis[i]=true;
                    q.push({i,node});
                }
                else if(par!=i){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        vector<int> vis(v+1,false);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                if(checkforCycle(i,v,adj,vis)){
                    return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends