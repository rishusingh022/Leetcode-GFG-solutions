class Solution {
public:
    bool isInside(int i,int j,int r,int c){
        if(i>=0 && i<=r-1 && j>=0 && j<=c-1){
            return true;
        }
        return false;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        stack<array<int,2>> st;
        
        int r=image.size();
        int c=image[0].size();
        vector<vector<bool>> vis(r,vector<bool>(c,false));
        
        st.push({sr,sc});
        int check=image[sr][sc];
        image[sr][sc]=newColor;
        vis[sr][sc]=true;
        
        while(!st.empty()){
            array<int,2> cor=st.top();
            st.pop();
            int i=cor[0];
            int j=cor[1];
            if(isInside(i+1,j,r,c) && !vis[i+1][j] && image[i+1][j]==check){
                image[i+1][j]=newColor;
                vis[i+1][j]=true;
                st.push({i+1,j});
            }
            if(isInside(i,j+1,r,c) && !vis[i][j+1] && image[i][j+1]==check){
                image[i][j+1]=newColor;
                vis[i][j+1]=true;
                st.push({i,j+1});
            }
            if(isInside(i-1,j,r,c) && !vis[i-1][j] && image[i-1][j]==check){
                image[i-1][j]=newColor;
                vis[i-1][j]=true;
                st.push({i-1,j});
            }
            if(isInside(i,j-1,r,c) && !vis[i][j-1] && image[i][j-1]==check){
                image[i][j-1]=newColor;
                vis[i][j-1]=true;
                st.push({i,j-1});
            }
        }
        return image;
    }
};