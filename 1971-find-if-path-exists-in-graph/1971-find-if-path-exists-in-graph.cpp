class Solution {
public:
    void addEdge(vector<int> adj[], int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool bfs(vector<int> adj[],int s,int d,int n)
    {
        if(s==d){
            return true;
        }
        queue<int> q;
        vector<bool> visited(n,false);
        q.push(s);
        visited[s]=true;
        while(!q.empty()){
            int curr=q.front();
            if(curr==d) return true;
            q.pop();
            for(auto i:adj[curr]){
                if(visited[i]!=true){
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++){
            addEdge(adj,edges[i][0],edges[i][1]);
        }
        return bfs(adj,source,destination,n);
    }
};