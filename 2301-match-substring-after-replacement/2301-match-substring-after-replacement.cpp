class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        int n=s.size();
        int m=sub.size();
        vector<vector<bool>> allowed(256,vector<bool>(256));
        for(int i=0;i<256;i++){
            allowed[i][i]=true;
        }
        for(auto i:mappings){
            allowed[i[0]][i[1]]=true;
        }
        for(int i=0;i<n-m+1;i++){
            bool ok_this_works=true;
            for(int j=0;j<m;j++){
                if(!allowed[sub[j]][s[i+j]]){
                    ok_this_works=false;
                }
            }
            if(ok_this_works){
                return true;
            }
        }
        return false;
    }
};