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
    array<int,2> solve(TreeNode* root,int &cnt){
        if(root==NULL){
            return {0,0};
        }
        array<int,2> a=solve(root->left,cnt);
        array<int,2> b=solve(root->right,cnt);
        if((root->val+a[0]+b[0])/(1+a[1]+b[1])==root->val){
            cnt++;
        }
        return {root->val+a[0]+b[0],1+a[1]+b[1]};
    }
    int averageOfSubtree(TreeNode* root) {
        int cnt=0;
        solve(root,cnt);
        return cnt;
    }
};