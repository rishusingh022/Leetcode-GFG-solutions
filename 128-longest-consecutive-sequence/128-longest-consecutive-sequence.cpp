class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n=arr.size();
        unordered_set<int> s;
        for(auto i:arr){
            s.insert(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(s.find(arr[i]-1)==s.end()){
                int j=arr[i];
                while(s.find(j)!=s.end()){
                    j++;
                }
                ans=max(ans,j-arr[i]);
            }
            
        }
        return ans;
    }
};