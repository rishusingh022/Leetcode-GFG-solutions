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
    map<int,TreeNode*> mp;
    void solve(TreeNode* root,int level){
        if(root==NULL) return;
        mp[level]=root;
        solve(root->left,level+1);
        solve(root->right,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        //unordered_map<int,Node*> mp;
        solve(root,0);
        vector<int> res;
        for(auto i:mp){
            res.push_back(i.second->val);
        }
        return res;
    }
};