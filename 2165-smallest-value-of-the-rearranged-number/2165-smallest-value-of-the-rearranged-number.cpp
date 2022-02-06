class Solution {
public:
    long long smallestNumber(long long num) {
        vector<int> arr;
        long long temp=abs(num);
        while(temp>0){
            arr.push_back(temp%10);
            temp/=10;
        }
        reverse(arr.begin(),arr.end());
        if(num>0){
            int ind=-1;
            sort(arr.begin(),arr.end());
            for(int i=1;i<=9;i++){
                ind=lower_bound(arr.begin(),arr.end(),i)-arr.begin();
                if(ind!=-1){
                    break;
                }
            }
            swap(arr[ind],arr[0]);
            reverse(arr.begin(),arr.end());
            long long res=0;
            for(int i=arr.size()-1;i>=0;i--){
                res=res*10+arr[i];
            }
            return res;
        }
        else{
            sort(arr.begin(),arr.end(),greater<int>());
            reverse(arr.begin(),arr.end());
            long long res=0;
            for(int i=arr.size()-1;i>=0;i--){
                res=res*10+arr[i];
            }
            res=-res;
            return res;
        }
    }
};