class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people,0);
        int j=1;
        int i=0;
        int sum=0;
        while(sum+j<=candies){
            if(i==num_people) i=0;
            ans[i++]+=j;
            sum+=(j++);
        }
        if(sum<=candies){
            if(i==num_people) i=0;
            ans[i]+=candies-sum;
        }
        return ans;
    }
};