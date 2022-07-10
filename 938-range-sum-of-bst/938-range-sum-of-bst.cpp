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
    int solve(TreeNode* root, int low, int high,int &sum){
        if(root==NULL){
            return 0;
        }
        if(root->val>=low and root->val<=high){
            sum+=root->val;
        }
        if(root->val<low and root->val>high){
            return 0;
        }
        solve(root->left,low,high,sum);
        solve(root->right,low,high,sum);
        return sum;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        return solve(root,low,high,sum);
    }
};