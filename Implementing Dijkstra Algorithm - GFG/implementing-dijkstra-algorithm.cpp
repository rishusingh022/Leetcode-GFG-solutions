// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int source)
    {
        // Code here
        priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>> >pq;
        vector<int> distTo(v+1,INT_MAX);
        distTo[source]=0;
        pq.push({0,source});
        while(!pq.empty()){
            int dist=pq.top()[0];
            int prev=pq.top()[1];
            pq.pop();
            for(auto i:adj[prev]){
                int next=i[0];
                int nextDist=i[1];
                if(distTo[next]>distTo[prev]+nextDist){
                    distTo[next]=distTo[prev]+nextDist;
                    pq.push({distTo[next],next});
                }
            }
        }
        return distTo;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends