class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int n=arr.size();
        int cand1,cand2;
        int vote1=0,vote2=0;
        for(int i=0;i<n;i++){
            if(arr[i]==cand1) vote1++;
            else if(arr[i]==cand2) vote2++;
            else if(vote1==0) cand1=arr[i],vote1=1;
            else if(vote2==0) cand2=arr[i],vote2=1;
            else vote1--,vote2--;
        }
        int count1=0,count2=0;
        for(int i=0;i<n;i++){
            if(arr[i]==cand1) count1++;
            else if(arr[i]==cand2) count2++;
        }
        if(count1>n/3 && count2>n/3) return {cand1,cand2};
        else if(count1>n/3) return {cand1};
        else if(count2>n/3) return {cand2};
        else return {};
    }
};