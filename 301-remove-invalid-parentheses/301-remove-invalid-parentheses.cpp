class Solution {
public:
    vector<string> ans;
    bool valid(string s){
        if(s.size()==0){
            return true;
        }
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]!='(' and s[i]!=')'){
                continue;
            }
            if(!st.empty() && st.top()=='(' && s[i]==')'){
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        if(st.empty()==true){
            return true;
        }
        return false;
    }
    unordered_set<string> vis;
    void solve(string s){
        queue<string> q;
        q.push(s);
        bool flag = false;
        while(!q.empty()){
            string top = q.front();
            q.pop();
            if(valid(top)){
                ans.push_back(top);
                flag=true;
            }
            if(flag){
                continue;
            }
            int sz = top.length();
            for(int i=0; i<sz; i++){
                if(top[i]>='a' && top[i]<='z'){
                    continue;
                }
                
                string next = top.substr(0,i)+top.substr(i+1);
                if(vis.find(next)==vis.end()){
                    q.push(next);
                    vis.insert(next);
                }
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        ans=vector<string>();
        solve(s);
        return ans;
    }
};