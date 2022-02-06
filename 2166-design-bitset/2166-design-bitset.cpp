class Bitset {
public:
    vector<int>res;
    int len;
    int yo;
    int fp;
    Bitset(int size) {
        res=vector<int>(size,0);
        len=size;
        yo=0;
        fp=0;
    }
    void fix(int idx) {
        if((res[idx]+fp)%2==0){
            res[idx]++;
            yo++;
        }
    }
    
    void unfix(int idx) {
        if((res[idx]+fp)%2!=0){
            res[idx]--;
            yo--;
        }
    }
    void flip() {
        yo=len-yo;
        fp++;
    }
    
    bool all() {
        if(yo==len) return true;
        else{
            return false;
        }
    }
    
    bool one() {

        if(yo>=1) return true;
        else return false;
    }
    
    int count() {
        return yo;
    }
    
    string toString() {
        string ans;
        for(int i=0;i<len;i++){
            if((fp+res[i])%2==0){
                ans.push_back('0');
            }
            else{
                ans.push_back('1');
            }
        }
        return ans;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */