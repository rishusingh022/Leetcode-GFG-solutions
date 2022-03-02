// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

bool cmp(Job a,Job b){
    if(a.profit==b.profit){
        a.dead<b.dead;
    }
    return a.profit>b.profit;
}
struct DisjointSet{
    vector<int> parent;
    DisjointSet(int n){
        parent=vector<int>(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int find(int s){
        if(s==parent[s]){
            return s;
        }
        return parent[s]=find(parent[s]);
    }
    void merge(int u,int v){
        parent[v]=u;
    }
};
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        int cnt=0,maxProfit=0;
        sort(arr,arr+n,cmp);
        int maxDeadline=INT_MIN;
        for(int i=0;i<n;i++){
            maxDeadline=max(maxDeadline,arr[i].dead);
        }
        DisjointSet ds(maxDeadline);
        
        for(int i=0;i<n;i++){
            int availableSlot=ds.find(arr[i].dead);
            if(availableSlot>0){
                ds.merge(ds.find(availableSlot-1),availableSlot);
                cnt++;
                maxProfit+=arr[i].profit;
            }
        }
        return {cnt,maxProfit};
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends