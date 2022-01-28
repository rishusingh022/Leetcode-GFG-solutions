class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int ind=floor(arr.size()*0.05);
        double sum=0;
        for(int i=ind;i<arr.size()-ind;i++){
            sum+=arr[i];
        }
        //cout<<arr.size();
        return sum/(arr.size()-2*ind);
    }
};