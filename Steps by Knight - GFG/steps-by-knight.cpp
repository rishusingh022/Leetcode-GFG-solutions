// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
 
class Solution
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    bool isInside(int x,int y,int n){
        if(x>=1 && x<=n && y>=1 && y<=n){
            return true;
        }
        return false;
    }
	int minStepToReachTarget(vector<int>&knightPos,vector<int>&targetPos,int n)
	{
	    // Code here
	    int dx[]={-2,-1,1,2,-2,-1,1,2};
	    int dy[]={-1,-2,-2,-1,1,2,2,1};
	    queue<array<int,3>> q;
	    q.push({knightPos[0],knightPos[1],0});
	    
	    vector<vector<bool>> vis(n+1,vector<bool>(n+1,false));
	    vis[knightPos[0]][knightPos[1]]=true;
	    
	    while(!q.empty()){
	        array<int,3> cor=q.front();
	        q.pop();
	        if(cor[0]==targetPos[0] && cor[1]==targetPos[1]) return cor[2];
	        for(int i=0;i<8;i++){
	            int x=cor[0]+dx[i];
	            int y=cor[1]+dy[i];
	            if(isInside(x,y,n) && !vis[x][y]){
	                vis[x][y]=true;
	                q.push({x,y,cor[2]+1});
	            }
	        }
	    }
	    return 0;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends