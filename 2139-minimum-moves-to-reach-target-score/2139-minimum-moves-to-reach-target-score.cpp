class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ans=0;
        if(maxDoubles==0){
            return target-1;
        }
        while(true){
            if(target<=1){
                break;
            }
            if(target%2==0 && maxDoubles>0){
                target=target/2;
                maxDoubles--;
                ans++;
            }
            else{
                --target;
                ans++;
            }
            
        }
        return ans;
    }
};