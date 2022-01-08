class Solution {
public:
    string capitalizeTitle(string title) {
        string ans="";
        if(title.size()==1 || title.size()==2){
            for(int i=0;i<title.size();i++){
                ans+=tolower(title[i]);
            }
            return ans;
        }
        vector<int> arr;
        int n=title.size();
        for(int i=0;i<n;i++){
            if(title[i]==' '){
                arr.push_back(i);
            }
        }
        if(arr.size()==0){
            ans+=toupper(title[0]);
            for(int i=1;i<title.size();i++){
                ans+=tolower(title[i]);
            }
            return ans;
        }
        // first word
        string temp1=title.substr(0,arr[0]);
        if(temp1.size()==1 || temp1.size()==2){
            for(int i=0;i<temp1.size();i++){
                ans+=tolower(temp1[i]);
            }
        }
        else{
           ans+=toupper(temp1[0]);
            for(int i=1;i<temp1.size();i++){
                ans+=tolower(temp1[i]);
            } 
        }
        ans+=' ';
        
       
        for(int i=0;i<arr.size()-1;i++){
            string temp=title.substr(arr[i]+1,arr[i+1]-arr[i]-1);
            if(temp.size()==1 || temp.size()==2){
                for(int j=0;j<temp.size();j++){
                    ans+=tolower(temp[j]);
                }
            }
            else{
                ans+=toupper(temp[0]);
                for(int j=1;j<temp.size();j++){
                    ans+=tolower(temp[j]);
                }
            }
            ans+=' ';
        }
        
        string temp=title.substr(arr[arr.size()-1]+1,title.size()-arr[arr.size()-1]);
        if(temp.size()==1 || temp.size()==2){
            for(int i=0;i<temp.size();i++){
                ans+=tolower(temp[i]);
            }
        }
        else{
           ans+=toupper(temp[0]);
            for(int i=1;i<temp.size();i++){
                ans+=tolower(temp[i]);
            } 
        }
        return ans;
    }
};