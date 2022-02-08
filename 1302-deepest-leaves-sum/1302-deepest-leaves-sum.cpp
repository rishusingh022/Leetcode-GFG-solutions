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
    int solve(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);q.push(NULL);
        vector<int> temp;
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr==NULL){
                if(q.empty()==true){
                    break;
                }
                // for(auto i:temp) cout<<i<<" ";
                // cout<<endl;
                temp=vector<int>();
                q.push(curr);
                continue;
            }
            temp.push_back(curr->val);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        return accumulate(temp.begin(),temp.end(),0);
    }
    int deepestLeavesSum(TreeNode* root) {
        return solve(root);
    }
};