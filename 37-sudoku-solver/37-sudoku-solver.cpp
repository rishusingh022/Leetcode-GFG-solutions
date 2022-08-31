class Solution {
public:
    bool isSafe(vector<vector<char>>& board,int row,int col,char number){
        for(int i=0;i<board.size();i++){
            if(board[i][col]==number){
                return false;
            }
        }
        for(int i=0;i<board.size();i++){
            if(board[row][i]==number){
                return false;
            }
        }
        int yo=sqrt(board.size());
        int rowstart=row-row%yo;
        int colstart=col-col%yo;
        
        for(int r=rowstart;r<rowstart+yo;r++){
            for(int c=colstart;c<colstart+yo;c++){
                if(board[r][c]==number){
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        int n=board.size();
        int row=-1;
        int col=-1;
        
        bool emptyLeft=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='.'){
                    row=i;
                    col=j;
                    emptyLeft=false;
                    break;
                }
            }
            if(emptyLeft==false){
                break;
            }
        }
        
        if(emptyLeft==true){
            return true;
        }
        
        for(int num=1;num<=9;num++){
            if(isSafe(board,row,col,num+'0')){
                char temp=num+'0';
                board[row][col]=temp;
                if(solve(board)){
                    return true;
                }
                else{
                    board[row][col]='.';
                }
                
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        // for(auto i:board){
        //     for(auto j:i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
    }
    
    
};