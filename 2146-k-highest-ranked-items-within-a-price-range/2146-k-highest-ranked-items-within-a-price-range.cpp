#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
class Solution {
public:
    
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& p, vector<int>&start,int k) {
        // calculating  distance using bfs
        vector<vector<int>> final_ans;
        final_ans.reserve(1000000);
        int n=grid.size();
        int m=grid[0].size();
        int dis[n][m],vis[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dis[i][j]=1e9;
                vis[i][j]=0;
            }
        }
        int id1[1000000],id2[1000000];
        int cnt=1;
        dis[start[0]][start[1]]=0;
        queue<int> q;
        id1[1]=start[0];
        id2[1]=start[1];
        vis[start[0]][start[1]]=1;
        q.push(cnt);
        cnt++;
        while(!q.empty()){
            int idx=q.front();
            int i=id1[idx];
            int j=id2[idx];
            q.pop();
            if(i-1>=0 && grid[i-1][j]!=0 && !vis[i-1][j]){
                dis[i-1][j]=1+dis[i][j];
                q.push(cnt);
                id1[cnt]=i-1;
                id2[cnt]=j;
                cnt++;
                vis[i-1][j]=1;
            }
            if(i+1<n && grid[i+1][j]!=0 && !vis[i+1][j]){
                dis[i+1][j]=1+dis[i][j];
                q.push(cnt);
                id1[cnt]=i+1;
                id2[cnt]=j;
                cnt++;
                vis[i+1][j]=1;
            }
            if(j-1>=0 && grid[i][j-1]!=0 && !vis[i][j-1]){
                dis[i][j-1]=1+dis[i][j];
                q.push(cnt);
                id1[cnt]=i;
                id2[cnt]=j-1;
                cnt++;
                vis[i][j-1]=1;
            }
            if(j+1<m && grid[i][j+1]!=0 && !vis[i][j+1]){
                dis[i][j+1]=1+dis[i][j];
                q.push(cnt);
                id1[cnt]=i;
                id2[cnt]=j+1;
                cnt++;
                vis[i][j+1]=1;
            }
        }
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<dis[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<array<int,4>> all;
        all.reserve(1000000);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                
                if(grid[i][j]>1 && grid[i][j]>=p[0] && grid[i][j]<=p[1]){
                    if(vis[i][j]){
                        all.push_back({dis[i][j],grid[i][j],i,j});
                    }
                }
                
            }
        }
        sort(all.begin(),all.end());
        int a=all.size();
        int f=min(a,k);
        for(int i=0;i<f;i++){
            final_ans.push_back({all[i][2],all[i][3]});
        }
        return final_ans;
    }
};