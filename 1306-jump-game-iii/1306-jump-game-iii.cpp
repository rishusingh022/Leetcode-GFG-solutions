class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        if(arr[start]==0) return true;
        if(n<=1) return false;
        
        queue<int> q;
        vector<bool> vi(n+1,false);
        q.push(start);
        vi[start]=true;
        
        while(!q.empty()){
            int ind=q.front();
            q.pop();
            vi[ind]=true;
            if(arr[ind]==0) return true;
            if(arr[ind]+ind<n && vi[arr[ind]+ind]!=true) q.push(arr[ind]+ind);
            if(ind-arr[ind]>=0 && vi[ind-arr[ind]]!=true) q.push(ind-arr[ind]);
        }
        return false;
    }
};