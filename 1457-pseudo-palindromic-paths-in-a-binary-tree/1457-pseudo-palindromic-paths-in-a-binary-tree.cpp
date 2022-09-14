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
    int ans=0;
    unordered_map<int,int> mp;
    bool check(){
        int count = 0;
        for(auto i:mp){
            if(i.second==0){
                continue;
            }
            if(i.second%2!=0){
                if(count!=0){
                    return false;
                }
                count++;
            }
        }
        return true;
    }
    void solve(TreeNode* root){
        if(root==NULL){
            return;
        }
        mp[root->val]++;
        if(root->left==NULL && root->right==NULL){
            if(check()){
                ans++;
            }
            mp[root->val]--;
            return;
        }
        solve(root->left);
        solve(root->right);
        mp[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        solve(root);
        return ans;
    }
};