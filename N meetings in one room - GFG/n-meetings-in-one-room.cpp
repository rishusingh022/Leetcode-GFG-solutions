// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<array<int,2>> arr;
        for(int i=0;i<n;i++){
            arr.push_back({end[i],start[i]});
        }
        sort(arr.begin(),arr.end());
        int cnt=1;
        //int n=start.size();
        int j=0;
        for(int i=1;i<n;i++){
            if(arr[i][1]>arr[j][0]){
                cnt++;
                j=i;
            }
        }
        return cnt;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends