class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](vector<int> a,vector<int> b){
            return (a[1])>=(b[1]);
        });
        // for(auto i:boxTypes){
        //     cout<<i[0]<<" "<<i[1]<<endl;
        // }
        int res=0;
        for(int i=0;i<boxTypes.size();i++){
            if(truckSize>=boxTypes[i][0]){
                res+=(boxTypes[i][0]*boxTypes[i][1]);
                //cout<<res<<endl;
                truckSize-=boxTypes[i][0];

            }
            else{
                res+=(truckSize*boxTypes[i][1]);
                break;
            }
        }
        
        return res;
    }
};