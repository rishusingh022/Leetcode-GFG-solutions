class Solution {
public:
    
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& p, vector<int>&start,int k) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        dis[start[0]][start[1]]=0;
        queue<array<int,2>> q;
        q.push({start[0],start[1]});
        while(!q.empty()){
            auto idx=q.front();
            int i=idx[0];
            int j=idx[1];
            q.pop();
            if(i-1>=0 && grid[i-1][j]!=0 && dis[i-1][j]==INT_MAX){
                dis[i-1][j]=1+dis[i][j];
                q.push({i-1,j});
            }
            if(i+1<n && grid[i+1][j]!=0 && dis[i+1][j]==INT_MAX){
                dis[i+1][j]=1+dis[i][j];
                q.push({i+1,j});
            }
            if(j-1>=0 && grid[i][j-1]!=0 && dis[i][j-1]==INT_MAX){
                dis[i][j-1]=1+dis[i][j];
                q.push({i,j-1});
            }
            if(j+1<m && grid[i][j+1]!=0 && dis[i][j+1]==INT_MAX){
                dis[i][j+1]=1+dis[i][j];
                q.push({i,j+1});
            }
        }
        auto cmp=[](array<int,4>a ,array<int,4>b){
            if(a[0]==b[0]){
                if(a[1]==b[1]){
                    if(a[2]==b[2]){
                        return a[3]>b[3];
                    }
                    return a[2]>b[2];
                }
                return a[1]>b[1];
            }
            return a[0]>b[0];
        };
        priority_queue<array<int,4>,vector<array<int,4>>,decltype(cmp)> pq(cmp);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>1 && grid[i][j]<=p[1] && grid[i][j]>=p[0]){
                    pq.push({dis[i][j],grid[i][j],i,j});
                }
            }
        }
        vector<vector<int>> ans;
        int yo=k;
        while(!pq.empty() && yo--){
            array<int,4> temp=pq.top();
            if(temp[0]==INT_MAX) break;
            ans.push_back({temp[2],temp[3]});
            pq.pop();
        }
        return ans;
    }
};