class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int max_profit=0;
        for(int i=1;i<n;i++){
            if(prices[i]>prices[i-1]){
                int profit=prices[i-1];
                i++;
                while(i<n){
                    if(prices[i]>=prices[i-1]){
                        i++;
                    }
                    else{
                        break;
                    }
                }
                int temp=profit;
                profit=prices[i-1]-temp;
                max_profit+=profit;
            }
        }
        return max_profit;
    }
};