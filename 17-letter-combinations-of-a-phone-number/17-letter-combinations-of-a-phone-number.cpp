class Solution {
public:
    map<int,string> mp={{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
    void solve(string p,string s,int i,vector<string> &res){
        if(i>=s.size()){
            if(p==""){
                return;
            }
            res.push_back(p);
            return;
        }
        string yo=mp[s[i]-'0'];
        for(int j=0;j<yo.size();j++){
            string temp=p+yo[j];
            solve(temp,s,i+1,res);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string p="";
        solve(p,digits,0,res);
        return res;
    }
};