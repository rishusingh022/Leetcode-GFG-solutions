class Solution {
public:
    bool strongPasswordCheckerII(string p) {
        if(p.size()<8){
            return false;
        }
        int flag1=0,flag2=0,flag3=0,flag4=0;
        for(int i=0;i<p.size();i++){
            if(islower(p[i])){
                flag1=1;
            }
            if(isupper(p[i])){
                flag2=1;
            }
            if(isdigit(p[i])){
                flag3=1;
            }
            if(p[i]=='!' || p[i]=='@' || p[i]=='#' || p[i]=='$' || p[i]=='%' ||p[i]=='^'|| p[i]=='&' || p[i]=='*' || p[i]=='(' || p[i]==')' || p[i]=='-' || p[i]=='+'){
                flag4=1;
            }
            if(i!=0 and p[i]==p[i-1]){
                return false;
            }
        }
        if(flag1==0 || flag2==0 || flag3==0 || flag4==0){
            return false;
        }
        return true;
    }
};