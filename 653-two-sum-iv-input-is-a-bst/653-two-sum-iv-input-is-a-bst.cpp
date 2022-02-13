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
    unordered_set<int> seen;
    bool solve(TreeNode* root,int k){
        if(root==NULL){
            return false;
        }
        if(solve(root->left,k)==true){
            return true;
        }
        if(seen.find(k-root->val)!=seen.end()){
            return true;
        }
        seen.insert(root->val);
        return solve(root->right,k);
    }
    bool findTarget(TreeNode* root, int k) {
        seen=unordered_set<int>();
        return solve(root,k);
    }
};