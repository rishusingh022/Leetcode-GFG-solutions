// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    void dfs(int node,stack<int> &st,vector<int>& vis,vector<int> adj[]){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,st,vis,adj);
            }
        }
        st.push(node);
    }
    void revDfs(int node,vector<int> &vis,vector<int> transpose[]){
        vis[node]=1;
        for(auto it:transpose[node]){
            if(!vis[it]){
                revDfs(it,vis,transpose);
            }
        }
    }
    int kosaraju(int v, vector<int> adj[])
    {
        //code here
        stack<int> st;
        vector<int> vis(v,0);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                dfs(i,st,vis,adj);
            }
        }
        vector<int> transpose[v];
        int res=0;
        for(int i=0;i<v;i++){
            vis[i]=0;
            for(auto it:adj[i]){
                transpose[it].push_back(i); 
            }
        }
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!vis[node]){
                revDfs(node,vis,transpose);
                res++;
            }
        }
        return res;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends