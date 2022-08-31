class Solution {
public:
    bool isValid(vector<vector<char>>& board,int row,int col){
        for(int i=0;i<board.size();i++){
            if(i!=row && board[i][col]==board[row][col]){
                return false;
            }
        }
        for(int i=0;i<board[0].size();i++){
            if(i!=col && board[row][i]==board[row][col]){
                return false;
            }
        }
        int check=sqrt(board.size());
        int rowStart=row-row%check;
        int colStart=col-col%check;
        for(int i=rowStart;i<rowStart+check;i++){
            for(int j=colStart;j<colStart+check;j++){
                if(i!=row && j!=col && board[i][j]==board[row][col]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]!='.'){
                    if(!isValid(board,i,j)){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};