class Solution {
public:
    int maxArea(vector<int>& h) {
        int n=h.size();
        vector<int>left(n);
        vector<int>right(n);
        left[0]=h[0];
        right[n-1]=h[n-1];
        for(int i=1;i<n;i++) left[i]=max(left[i-1],h[i]);
        for(int i=n-2;i>=0;i--) right[i]=max(right[i+1],h[i]);
        int ans=0;
        int i=0;
        int j=n-1;
        while(i<j){
            ans=max(ans,min(left[i],right[j])*(j-i));
            if(left[i]<right[j]){
                i++;
            }
            else if(left[i]>right[j]){
                j--;
            }
            else{
                i++;
                j--;
            }
        }
        return ans;
    }
};