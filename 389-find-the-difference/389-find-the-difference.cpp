class Solution {
public:
    char findTheDifference(string s, string t) {
        int res=0;
        for(auto i:s) res^=i;
        for(auto i:t) res^=i;
        return (res);
    }
};