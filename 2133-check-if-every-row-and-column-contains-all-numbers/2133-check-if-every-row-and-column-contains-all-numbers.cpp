class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            arr[i]=i+1;
        }
        for(int i=0;i<n;i++){
            vector<int> temp(n);
            for(int j=0;j<n;j++){
                temp[j]=matrix[i][j];
            }
            sort(temp.begin(),temp.end());
            if(arr!=temp){
                return false;
            }
        }
        for(int i=0;i<n;i++){
            vector<int> temp(n);
            for(int j=0;j<n;j++){
                temp[j]=matrix[j][i];
            }
            sort(temp.begin(),temp.end());
            if(arr!=temp){
                return false;
            }
        }
        
        return true;
        
    }
};