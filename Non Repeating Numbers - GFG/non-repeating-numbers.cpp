// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int res=0;
        for(int i=0;i<nums.size();i++){
            res=res^nums[i];
        }
        int cnt=res&~(res-1);
    
        vector<int> a;
        vector<int> b;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]&cnt) a.push_back(nums[i]);
            else b.push_back(nums[i]);
        }
        // for(auto i:a) cout<<i<<" ";
        // cout<<endl;
        // for(auto i:b) cout<<i<<" ";
        
        int num2=res;
        for(int i=0;i<a.size();i++){
            num2^=a[i];
        }
        int num1=num2^res;
        
        return {min(num1,num2),max(num1,num2)};
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}  // } Driver Code Ends