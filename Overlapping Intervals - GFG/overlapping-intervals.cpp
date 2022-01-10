// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& it) {
         // Code here
        vector<vector<int>> ans;
        sort(it.begin(),it.end());
        // for(auto i: it){
        //     cout<<i[0]<<" "<<i[1]<<" ";
        // }
        // cout<<endl;
        int l=it[0][0],r=it[0][1];
        for(int i=1;i<it.size();i++){
            if(r>=it[i][0]){
                r=max(r,it[i][1]);
            }
            else{
                ans.push_back({l,r});
                l=it[i][0];
                r=it[i][1];
            }
        }
        ans.push_back({l,r});
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends