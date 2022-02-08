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
    int ans;
    int solve(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int ld=solve(root->left);
        int rd=solve(root->right);
        ans=max(ans,1+ld+rd);
        return 1+max(ld,rd);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ans=0;
        int temp=solve(root);
        return ans-1;
    }
};