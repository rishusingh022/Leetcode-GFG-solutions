class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx_profit=INT_MIN;
        int min_price=INT_MAX;
        int n=prices.size();
        for(int i=0;i<n;i++){
            if(min_price>prices[i]){
                min_price=prices[i];
            }
            if(mx_profit<prices[i]-min_price){
                mx_profit=prices[i]-min_price;
            }
            
        }
        return mx_profit;
    }
};