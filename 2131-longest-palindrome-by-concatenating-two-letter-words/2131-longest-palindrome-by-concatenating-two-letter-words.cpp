class Solution {
public:
  
    int longestPalindrome(vector<string>& words) {
        
        unordered_map<string,int> seen1;
        unordered_map<string,int> seen2;
        
        for(int i=0;i<words.size();i++){
            if(words[i][0]==words[i][1]){
                seen1[words[i]]++;
            }
            else{
                seen2[words[i]]++;
            }
        }
        for(auto i:seen1){
            cout<<i.first<<" "<<i.second<<endl;
        }
        cout<<endl;
        for(auto i:seen2){
            cout<<i.first<<" "<<i.second<<endl;
        }
        int ans=0;
        for(auto i:seen1){
            if(i.second%2!=0){
                ans+=(i.second-1)*2;
            }
            else{
                ans+=(i.second)*2;
            }
        }
        for(auto i:seen1){
            if(i.second%2==1){
                ans+=2;
                break;
            }
        }
        for(int i=0;i<words.size();i++){
            if(words[i][0]==words[i][1]){
                continue;
            }
            string temp=words[i];
            reverse(temp.begin(),temp.end());
            int a=min(seen2[words[i]],seen2[temp]);
            ans+=a*4;
            seen2[words[i]]-=a;
            seen2[temp]-=a;
        }
        
        return ans;
    }
};