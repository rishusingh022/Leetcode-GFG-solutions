class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> res(spells.size(),0);
        for(int i=0;i<spells.size();i++){
            double rem=ceil((double)success/(double)spells[i]);
            //cout<<rem<<" ";
            if(rem>potions[potions.size()-1]){
                res[i]=0;
                continue;
            }
            int ind=lower_bound(potions.begin(),potions.end(),rem)-potions.begin();
            res[i]=potions.size()-ind;
        }
        return res;
    }
};