/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* res;
    void solve(TreeNode* r1, TreeNode* r2, TreeNode* t,TreeNode** ans){
        if(r1==t){
            //cout<<"Hello";
            res=r2;
            ans=&r2;
            return ;
        }
        if(r1==NULL && r2==NULL){
            return ;
        }
        solve(r1->left,r2->left,t,ans);
        solve(r1->right,r2->right,t,ans);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode *ans;
        solve(original,cloned,target,&ans);
        return res;
    }
};