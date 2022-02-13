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
    TreeNode* prev=NULL;
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        bool ans=true;
        if(root->left!=NULL){
            ans=ans&isValidBST(root->left);
        }
        if(prev!=NULL and root->val<=prev->val){
            ans=false;
        }
        prev=root;
        if(root->right!=NULL){
            ans=ans&isValidBST(root->right);
        }
        return ans;
    }
};