// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int> dist (n, INT_MAX);
	    dist[0] = 0;
	    for(int i = 0; i < n; i++){
	    for(auto &v : edges){
	        dist[v[1]] = std::min((long long)dist[v[0]] + v[2] , (long long)dist[v[1]]);
	    }
	    }
	    for(auto &v : edges){
	        if(dist[v[1]] > dist[v[0]] + v[2]){
	            return true;
	        }
	    }
	    return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends