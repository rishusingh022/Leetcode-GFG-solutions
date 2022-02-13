/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        map<int,int> mp;
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* curr=root;
        while(!st.empty() || curr!=NULL){
            if(curr!=NULL){
                st.push(curr);
                curr=curr->left;
            }
            else{
                curr=st.top();
                st.pop();
                mp[curr->val]++;
                curr=curr->right;
            }
        }
        priority_queue<array<int,2>> pq;
        for(auto i:mp){
            pq.push({i.second,i.first});
        }
        int mx=pq.top()[0];
        while(!pq.empty()){
            if(mx!=pq.top()[0]) break;
            auto it=pq.top();
            pq.pop();
            res.push_back(it[1]);
        }
        return res;
    }
};