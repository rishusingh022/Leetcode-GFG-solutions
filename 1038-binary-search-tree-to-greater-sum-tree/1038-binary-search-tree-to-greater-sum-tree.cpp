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
    void solve1(TreeNode* root,int &sum){
        if(!root){
            return;
        }
        solve1(root->left,sum);
        sum=sum+root->val;
        solve1(root->right,sum);
    }
    void solve(TreeNode* root,int &prev,int sum){
        if(!root){
            return;
        }
        solve(root->left,prev,sum);
        prev+=root->val;
        root->val+=(sum-prev);
        solve(root->right,prev,sum);
    
    }
    TreeNode* bstToGst(TreeNode* root) {
        int prev=0;
        int sum=0;
        solve1(root,sum);
        solve(root,prev,sum);
        return root;
    }
};