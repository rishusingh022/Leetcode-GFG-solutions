// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        // code here
        vector<int> parent(v,-1);
        vector<bool> mstSet(v,false);
        vector<int> key(v,INT_MAX);
        key[0]=0;
        parent[0]=-1;
        for(int count=0;count<v-1;count++){
            int mini=INT_MAX,u;
            for(int i=0;i<v;i++){
                if(mstSet[i]==false && key[i]<mini){
                    mini=key[i],u=i;
                }
            }
            mstSet[u]=true;
            for(auto it:adj[u]){
                int v=it[0];
                int w=it[1];
                if(mstSet[v]==false && w<key[v]){
                    parent[v]=u;
                    key[v]=w;
                }
            }
        }
        return accumulate(key.begin(),key.end(),0);
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends