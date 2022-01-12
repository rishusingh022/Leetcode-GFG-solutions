// { Driver Code Starts

// Program to find best buying and selling days
#include <bits/stdc++.h>

using namespace std;

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int *, int);

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, i;
        cin >> n;
        int price[n];
        for (i = 0; i < n; i++) cin >> price[i];
        // function call
        stockBuySell(price, n);
    }
    return 0;
}
// } Driver Code Ends


// User function template for C++

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n) {
    // code here
    vector<vector<int>> ans;
    for(int i=1;i<n;i++){
        vector<int> temp;
        if(price[i]>price[i-1]){
            temp.push_back(i-1);
            i++;
            while(i<n){
                if(price[i]>=price[i-1]){
                    i++;
                }
                else{
                    break;
                }
            }
            temp.push_back(i-1);
            ans.push_back(temp);
        }
        
    }
    if(ans.empty()){
        cout << "No Profit" << endl;
        return;
    }
    for(auto i:ans){
        cout << "(";
        cout << i[0] << " ";
        cout << i[1] << ") ";
    }
    cout<<endl;
}